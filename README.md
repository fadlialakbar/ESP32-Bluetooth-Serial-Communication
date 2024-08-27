ESP32 Bluetooth Serial Communication
This project showcases a basic implementation of Bluetooth serial communication using an ESP32 microcontroller. The ESP32 is set up to send and receive data over Bluetooth, simulating a real-time data stream with generated sensor readings, results, and error codes.

Table of Contents
Features
Getting Started
Prerequisites
Installation
Usage
Functions
generateDataStream
generateDataResult
generateErrorResult
Contributing
License
Acknowledgements
Features
Bluetooth Setup: Initializes the ESP32 as a Bluetooth device named "ESP32 test."
Data Streaming: Generates and sends continuous random data streams including sensor readings and system status.
Result Simulation: Produces simulated results such as systolic/diastolic pressure, heart rate, and pump status.
Error Handling: Generates and sends random error codes for diagnostics.
Getting Started
Prerequisites
Hardware: ESP32 board
Software: Arduino IDE with ESP32 board support
Bluetooth-enabled device: For testing and data communication
Installation
Clone the repository:
bash
Copy code
git clone https://github.com/yourusername/esp32-bluetooth-serial.git
cd esp32-bluetooth-serial
Open the project in Arduino IDE.
Select the correct ESP32 board under Tools > Board.
Compile and upload the code to your ESP32.
Usage
Open the Serial Monitor at a baud rate of 115200 to monitor communication.
Pair your ESP32 with a Bluetooth-enabled device (e.g., smartphone or computer).
The ESP32 will send and receive data through Bluetooth. Monitor the transmitted data stream, simulated results, and error codes.
Functions
generateDataStream
Generates a random data stream simulating sensor readings and system status.

Output Format:

php
Copy code
DAT,<hh:mm dd/mm/yy>,<init>,<adapt>,<batt>,<senssRaw>,<senss>,<pwmValue>,<deflectRate>,<heartRate>,<iRH>,<beats>,TAD
generateDataResult
Simulates and generates result data including systolic and diastolic pressure, heart rate, and pump status.

Output Format:

php
Copy code
vin,sys:<sys>,dia:<dia>,map:<map>,hr:<hr>,ihb:<ihb>,t_pump:<tPump>,d_pump:<dPump>,s_pump:<sPump>,niv
generateErrorResult
Generates a random error code for testing error handling.

Output Format:

php
Copy code
vin,err <errorCode>,niv
Contributing
Contributions are welcome! Please submit a pull request or open an issue to discuss any changes or enhancements.

License
This project is licensed under the MIT License. See the LICENSE file for more details.

Acknowledgements
Special thanks to the open-source community for providing valuable resources and inspiration for this project.
