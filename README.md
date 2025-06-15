# Smart Factory Arduino System

## Description
This project simulates a smart factory environment using Arduino. The system autonomously manages temperature, water level, and cooling functions to maintain environmental equilibrium. It was designed and built as part of an engineering and cyber-physical systems course project.

## Functionality
- A 5V LED simulates heat generation.
- A temperature control loop monitors heat levels.
- A water pump refills fluid when the level drops below a threshold.
- A DC fan activates when temperature exceeds the set point.
- All sensor readings are logged manually in Excel.
- Gantt charts were used to plan the development timeline.

## Hardware Used
- Arduino Uno
- 5V LED (to simulate heat)
- Water level sensor
- Temperature sensor (e.g., TMP36 or thermistor)
- DC fan with driver circuit
- Water pump module
- Breadboard, wires, resistors
- Power supply

## Skills Applied
- Arduino (Embedded C)
- Real-time sensor input handling
- Actuator control (fan, pump)
- Project planning with Gantt charts
- Data collection in Excel

## How It Works
1. The heat simulation (LED) runs continuously.
2. The system monitors temperature and activates the fan if it crosses a preset threshold.
3. Water level is monitored via a sensor; the pump is triggered if the level drops too low.
4. These systems run simultaneously to keep factory conditions stable.

## Future Improvements
- Integrate data logging to SD card instead of manual Excel entry
- Add OLED or LCD display for real-time monitoring
- Incorporate wireless control via Bluetooth/Wi-Fi

## Project Planning
- Project broken into phases and tracked using Gantt charts.
- Timelines, testing cycles, and team tasks defined clearly.

## Notes
- No cloud integration or ML logic was used; the system is purely microcontroller-based.
