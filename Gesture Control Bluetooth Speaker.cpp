#include <Wire.h>
#include <SparkFun_APDS9960.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SparkFun_APDS9960 apds;
SoftwareSerial bluetoothSerial(10, 11); // RX, TX
DFRobotDFPlayerMini player;

const int speakerPin = 9; // Connect the speaker to this pin
int currentGesture = -1;  // Variable to store the current gesture

void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600); // Default baud rate for most Bluetooth modules
  pinMode(speakerPin, OUTPUT);

  // Initialize the APDS-9960 sensor
  if (!apds.init()) {
    Serial.println("Error initializing APDS-9960 sensor");
  }

  // Enable gesture sensing
  if (!apds.enableGestureSensor(true)) {
    Serial.println("Error enabling gesture sensor");
  }

  // Initialize the DFPlayer Mini
  if (!player.begin(bluetoothSerial)) {  // Use bluetoothSerial for communication
    Serial.println("Unable to begin:");
    // Handle errors here
  }
}

void loop() {
  // Check for a gesture
  if (apds.isGestureAvailable()) {
    currentGesture = apds.readGesture();
    handleGesture();
  }

  // Check for incoming data from Bluetooth module
  if (bluetoothSerial.available() > 0) {
    char data = bluetoothSerial.read();
    handleBluetoothCommand(data);
  }
}

void handleGesture() {
  switch (currentGesture) {
    case DIR_RIGHT:
      // Change to the next song
      Serial.println("Next Song (Swipe Right)");
      nextTrack();
      sendBluetoothCommand('N'); // Send command 'N' for next song
      break;

    case DIR_LEFT:
      // Change to the previous song
      Serial.println("Previous Song (Swipe Left)");
      previousTrack();
      sendBluetoothCommand('P'); // Send command 'P' for previous song
      break;

    case DIR_UP:
      // Increase the volume
      Serial.println("Increase Volume (Swipe Up)");
      increaseVolume();
      sendBluetoothCommand('+'); // Send command '+' for volume up
      break;

    case DIR_DOWN:
      // Decrease the volume
      Serial.println("Decrease Volume (Swipe Down)");
      decreaseVolume();
      sendBluetoothCommand('-'); // Send command '-' for volume down
      break;


    default:
      // No recognized gesture
      break;
  }

  delay(1000); // Adjust the delay as needed
}

void handleBluetoothCommand(char command) {
  switch (command) {
    case 'N':
      nextTrack();
      break;

    case '+':
      increaseVolume();
      break;

    case '-':
      decreaseVolume();
      break;

    // Add more cases for additional commands

    default:
      // Handle unrecognized commands (optional)
      break;
  }
}

// Functions for controlling the DFPlayer Mini
void nextTrack() {
  player.next();
}

void previousTrack() {
  player.previous();
}


void increaseVolume() {
  player.volumeUp();
}

void decreaseVolume() {
  player.volumeDown();
}

void sendBluetoothCommand(char command) {
  bluetoothSerial.write(command);
}