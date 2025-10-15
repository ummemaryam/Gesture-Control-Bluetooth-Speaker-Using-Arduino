# Gesture Control Bluetooth Speaker Using Arduino

# Introducction
The Gesture Control Bluetooth Speaker is an interactive system that allows users to control music playback using simple hand gestures instead of physical buttons.
By integrating the APDS-9960 gesture sensor, DFPlayer Mini MP3 module, and Bluetooth communication, this project provides a modern, touch-free music experience. It demonstrates the fusion of embedded systems, gesture recognition, and wireless communication, making it a perfect example of innovative human-computer interaction in audio technology.

# Objectives

1) Design a gesture recognition interface using the APDS-9960 sensor.
2) Integrate Bluetooth connectivity for wireless control.
3) Control audio playback with DFPlayer Mini MP3 module.
4) Enable hands-free track and volume control via gestures.

# Hardware Components
Component	Description
1) Arduino Uno	Central microcontroller for processing inputs and outputs
2) APDS-9960 Gesture Sensor	Detects hand movements (up, down, left, right)
3) DFPlayer Mini MP3 Module	Plays audio files stored on a microSD card
4) CA6928 / HC-05 Bluetooth Module	Enables wireless communication
5) 8Ω 0.5W Speaker	Outputs sound
6) Breadboard & Jumper Wires	For circuit connections and prototyping

# Software and Libraries
The code is written in Arduino C/C++ and runs on the Arduino IDE.

Required Libraries:
1) Wire.h — for I²C communication
2) SparkFun_APDS9960.h — for gesture sensor functions
3) SoftwareSerial.h — for serial communication with Bluetooth
4) DFRobotDFPlayerMini.h — for MP3 playback control

# System Workflow
The APDS-9960 sensor continuously monitors for gestures.
Detected gestures are interpreted by the Arduino:
Swipe Right → Next Track
Swipe Left → Previous Track
Swipe Up → Increase Volume
Swipe Down → Decrease Volume

Commands are sent to the DFPlayer Mini to execute playback actions.
Bluetooth module transmits feedback or receives control commands remotely.

# How to Run the Project
1) Install Arduino IDE

2) Install Libraries
In the IDE, go to:
Sketch → Include Library → Manage Libraries
Then install:
SparkFun_APDS9960

DFRobotDFPlayerMini
(Wire and SoftwareSerial are pre-installed)

3) Hardware Connections
Component	Arduino Pin	Function
APDS-9960	SDA → A4, SCL → A5	I²C communication
DFPlayer Mini	RX → 11, TX → 10	Serial communication
Bluetooth Module	RX → 10, TX → 11	Communication channel
Speaker	Pin 9	Audio output

Make sure your DFPlayer Mini has an SD card with MP3 files like:

/mp3/0001.mp3  
/mp3/0002.mp3  
/mp3/0003.mp3

4) Upload the Code
Open Gesture_Control_Bluetooth_Speaker.ino in Arduino IDE.

Select your board:
Tools → Board → Arduino Uno

Select COM Port:
Tools → Port → (choose correct port)

Click the Upload (→) button.

5) Test the System
Once uploaded and powered on:
Swipe your hand across the sensor to control playback.
Monitor output on the Serial Monitor (9600 baud).

Gesture	Action
-Swipe Right	Next Song
-Swipe Left	Previous Song
-Swipe Up	Volume Up
-Swipe Down	Volume Down

# Results & Observations
1) Gesture detection is accurate within 5–10 cm range.
2) Bluetooth communication is stable and responsive.
3) DFPlayer Mini provides smooth and reliable playback.

# Conclusion
This project successfully integrates gesture sensing, Bluetooth communication, and audio control into one interactive device. The Gesture Control Bluetooth Speaker offers a futuristic, touch-free way to interact with audio systems — combining innovation, usability, and embedded design.

# Future enhancements
1) Gesture-based play/pause
2) Voice command support
