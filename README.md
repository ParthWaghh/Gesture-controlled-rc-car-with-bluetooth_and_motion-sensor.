# Gesture-Controlled RC Car with Object Detection

## Overview

This project implements an Arduino-based robotic vehicle controlled through hand gestures, with ultrasonic obstacle detection. The system uses an MPU6050 inertial measurement unit (IMU) to capture hand movements, HC-05 Bluetooth modules for wireless command transmission, and an L298N motor driver for DC motor control. An HC-SR04 ultrasonic sensor measures the distance to nearby objects, enabling obstacle detection and providing the input required for collision-avoidance logic. The project demonstrates embedded C/C++ programming, peripheral interfacing, serial communication, sensor data processing, and hardware–firmware integration.

## System Architecture

The system consists of two subsystems:

**1. Transmitter — Gesture Controller**
- Arduino Nano / Uno
- MPU6050 accelerometer and gyroscope
- HC-05 Bluetooth module
- 7–9 V power source, subject to board and regulator specifications

The transmitter reads motion data from the MPU6050, interprets hand gestures, and sends corresponding movement commands over Bluetooth.

**2. Receiver — Robotic Vehicle**
- Arduino Uno
- HC-05 Bluetooth module
- L298N dual H-bridge motor driver
- Two DC motors
- HC-SR04 ultrasonic sensor
- Suitable battery pack

The receiver processes wireless commands and controls the motors through the L298N. The ultrasonic sensor provides distance measurements for obstacle detection.

## Key Features

- Gesture-based directional control
- Wireless communication between transmitter and receiver
- IMU-based motion sensing
- Dual DC motor control using an H-bridge driver
- Ultrasonic distance measurement
- Expandable firmware architecture for obstacle-avoidance behavior

## Hardware and Interfaces

| Component | Interface | Function |
|---|---|---|
| MPU6050 | I2C | Accelerometer and gyroscope data acquisition |
| HC-05 | UART | Wireless serial communication |
| L298N | GPIO / PWM | Motor direction and speed control |
| HC-SR04 | GPIO | Trigger and echo-based distance measurement |
| Arduino Nano / Uno | GPIO, I2C, UART, PWM | Embedded control and firmware execution |

## Firmware Workflow

1. Initialize the microcontroller peripherals and connected sensors.
2. Acquire motion data from the MPU6050.
3. Map the detected hand movement to a directional command.
4. Transmit the command to the receiver through the HC-05 Bluetooth link.
5. Parse the received command and update the motor driver control signals.
6. Measure obstacle distance using the HC-SR04.
7. Apply obstacle-response logic if implemented in the receiver firmware.

## Software Requirements

- Arduino IDE
- Arduino AVR Boards package
- MPU6050-compatible library, if used by the firmware
- I2C communication support
- USB cable for programming the Arduino boards

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/YOUR_USERNAME/Gesture-controlled-rc-car-with-object-detection-.git
cd Gesture-controlled-rc-car-with-object-detection-
```

Replace `YOUR_USERNAME` with your GitHub username.

### 2. Configure the Transmitter

1. Connect the MPU6050 to the Arduino using I2C.
2. Connect the HC-05 module to the Arduino's UART interface.
3. Open the transmitter firmware in Arduino IDE.
4. Verify the sensor connections, Bluetooth baud rate, and gesture thresholds.
5. Compile and upload the firmware.

### 3. Configure the Receiver

1. Connect the HC-05 module to the Arduino Uno.
2. Connect the L298N motor driver to the motor-control GPIO and PWM pins.
3. Connect the HC-SR04 trigger and echo pins.
4. Open the receiver firmware in Arduino IDE.
5. Verify the Bluetooth communication settings, motor pin assignments, and obstacle-detection thresholds.
6. Compile and upload the firmware.

### 4. Validate the System

- Verify that the MPU6050 returns valid sensor readings.
- Confirm that the transmitter sends the expected commands for each gesture.
- Test Bluetooth communication independently before integrating motor control.
- Check forward, reverse, left, and right motor operation with the wheels lifted.
- Validate ultrasonic distance readings and test obstacle-response behavior.

## Repository Structure

```text
Gesture-controlled-rc-car-with-object-detection-/
├── Transmitter/
│   └── transmitter.ino
├── Receiver/
│   └── receiver.ino
├── docs/
│   ├── circuit-diagram.png
│   └── system-architecture.png
├── images/
│   └── project-setup.jpg
├── .gitignore
└── README.md
```

*This is a suggested structure. Adjust the filenames and folders to match the actual repository contents.*

## Engineering Considerations

- **UART configuration:** Ensure the transmitter and receiver use compatible Bluetooth settings and baud rates.
- **Logic-level compatibility:** Verify voltage requirements for the HC-05 and other peripherals before connecting them to the Arduino.
- **Power integrity:** Use a suitable motor supply and a common ground between the Arduino and motor driver. Avoid powering DC motors directly from the Arduino's GPIO pins.
- **Sensor robustness:** Use appropriate filtering, thresholds, and timeouts to handle noisy IMU readings and invalid ultrasonic measurements.
- **Fail-safe behavior:** Define a safe motor-stop state when Bluetooth communication is lost or an obstacle is detected within the configured safety threshold.
- **Power supply:** Select a battery and regulator arrangement that meets the voltage and current requirements of the motors, controller, and sensors.

## Applications

- Gesture-controlled mobile robotics
- Embedded firmware development and debugging
- Wireless control systems
- Sensor integration and motor-control experiments
- Introductory autonomous navigation and obstacle detection

## Skills Demonstrated

Embedded C/C++, Arduino firmware development, I2C, UART, GPIO, PWM, IMU interfacing, Bluetooth communication, ultrasonic sensing, motor control, and hardware–software integration.

## Future Improvements

- Implement filtered IMU readings and calibrated gesture thresholds.
- Add a communication timeout and watchdog-based recovery strategy.
- Implement a priority-based obstacle-avoidance state machine.
- Add a structured command protocol with error checking.
- Introduce adjustable motor speed using PWM.
- Evaluate transition to an STM32-based controller for more advanced embedded firmware development.

## License

This project can be distributed under the MIT License. Add a `LICENSE` file to the repository if you choose this license.
