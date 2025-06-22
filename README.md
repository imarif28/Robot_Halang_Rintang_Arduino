# Arduino Obstacle Avoidance Robot

## Project Description
This project demonstrates the implementation of an autonomous obstacle avoidance robot using Arduino microcontroller. The robot is designed to move automatically while detecting and avoiding obstacles in its path using ultrasonic sensors and servo motors. This project was developed as part of the Robotics 2 Practicum course.

## Features
- Autonomous navigation with obstacle detection and avoidance
- Ultrasonic sensor HC-SR04 for distance measurement
- Servo motor for sensor positioning and area scanning
- Intelligent decision-making algorithm for path planning
- Automatic direction control based on sensor readings
- 180-degree turn capability when completely blocked

## Technologies Used
- **Microcontroller:** Arduino Uno
- **Programming Language:** C++ (Arduino IDE)
- **Sensors:** HC-SR04 Ultrasonic Sensor
- **Actuators:** DC Motors, Servo Motor
- **Motor Driver:** L298N Module

## Components List
1. Arduino Uno (1 unit)
2. DC Motor (2 units)
3. Arduino Sensor Shield (1 unit)
4. L298N Motor Driver Module (1 unit)
5. HC-SR04 Ultrasonic Sensor Module (1 unit)
6. AA Battery Holder (1 unit)
7. ON/OFF Switch (2 units)
8. AA Batteries (4 units)
9. 18650 Batteries (3 units)
10. Jumper Cables
11. Robot Chassis (1 unit)
12. Wheels (2 units)

## How the Robot Works

### Main Program Logic
1. **Initialization:**
   - Configures pin modes for motors and sensors
   - Sets servo motor to initial position (95 degrees)
   - Performs initial distance readings for system stability

2. **Navigation Algorithm:**
   - Continuously measures distance ahead using ultrasonic sensor
   - When obstacle detected, stops and scans left and right sides
   - Makes movement decisions based on available free space
   - Executes appropriate movement commands

3. **Decision Making Process:**
   - **Forward Movement:** When path ahead is clear
   - **Turn Left/Right:** When one side has more clearance
   - **Reverse and Turn:** When all directions are blocked

### Key Functions

#### Sensor Functions
- `readPing()`: Measures distance using ultrasonic sensor
- `lookRight()`: Rotates servo to scan right side
- `lookLeft()`: Rotates servo to scan left side

#### Movement Functions
- `moveForward()`: Moves robot forward
- `moveBackward()`: Moves robot backward
- `turnRight()`: Turns robot right
- `turnLeft()`: Turns robot left
- `turnRight2()`: Extended right turn for 180-degree rotation
- `moveStop()`: Stops robot movement

### Libraries and Configuration
- **Servo.h:** Controls servo motor positioning
- **NewPing.h:** Manages ultrasonic sensor operations

#### Pin Configuration
- Motor Driver (Right Motor): Pins 3, 4
- Motor Driver (Left Motor): Pins 7, 8
- Motor Speed Control: Pins 5, 6
- Ultrasonic Sensor: Trigger Pin 10, Echo Pin 9
- Servo Motor: Pin 12

## Circuit Design
The robot uses a modular approach with:
- Arduino Uno as the main controller
- L298N motor driver for DC motor control
- HC-SR04 ultrasonic sensor for distance measurement
- Servo motor for sensor positioning
- Dual power supply system (AA batteries for logic, 18650 for motors)



## Documentation
- **Project Presentation:** [View Documentation](https://www.canva.com/design/DAGp-UWrJf4/uimw1KvMuyRH1g1h7Gnfjw/view?utm_content=DAGp-UWrJf4&utm_campaign=designshare&utm_medium=link2&utm_source=uniquelinks&utlId=h7e94a097dd)

## Development Team
- **Ilham M Arif**
- **Ryvannio Satria** 
- **Farhan Rahman**
- **Dimas Iryad**
- **Arya Damar S**

## Course Information
- **Course:** Robotics 2 Practicum
- **Institution:** Politeknik Negeri Semarang
- **Academic Program:** Simulation and Robot Programming
