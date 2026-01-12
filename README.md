# STM32 Traffic Light System (Cooperative Multitasking)

## Overview
This project implements a sophisticated traffic light controller for a crossroad using the **STM32F103C6** microcontroller. The system features advanced button debouncing, Finite State Machines (FSM), and a **Cooperative Scheduler** to manage multiple tasks without heavy reliance on standard timer interrupts for logic execution.

---

## Features
* **4 Operational Modes**: 
    * **Mode 1**: Normal Traffic Operation.
    * **Mode 2**: Red Light Duration Adjustment (2Hz blinking).
    * **Mode 3**: Amber Light Duration Adjustment (2Hz blinking).
    * **Mode 4**: Green Light Duration Adjustment (2Hz blinking).
* **Software Debouncing**: Reliable button input processing to eliminate mechanical noise and ensure stable state transitions.
* **Cooperative Multitasking**: Tasks are scheduled and executed cooperatively to improve system modularity and predictability.
* **7-Segment Display**: Real-time countdown for traffic lights and clear visualization of the current adjustment mode.

---

## Hardware Requirements
| Component | Quantity | Description |
| :--- | :---: | :--- |
| **STM32F103C6** | 1 | Main Microcontroller |
| **LEDs** | 12 | 4 Red, 4 Amber, 4 Green |
| **Seven-Segment LEDs** | 6 | For time (2x2) and mode display (2) |
| **Push Buttons** | 3 | Mode Select, Adjust, Set |
| **Software** | - | Proteus Simulation Software & STM32CubeIDE |

---

## System Architecture
The software is organized into modular components to ensure clean code and easy maintenance:



* **`input_reading`**: Handles hardware-level debouncing and stable button state detection.
* **`input_processing`**: Manages the system Finite State Machine (FSM) for logic switching between modes.
* **`led_display`**: Controls the traffic light power states and manages 7-segment multiplexing.
* **`scheduler`**: The core cooperative engine that dispatches tasks at defined intervals based on a task list.

---

## How to Run
1.  **Clone the repository**: `git clone https://github.com/Nguyen-Hao-Khang/Traffic-Light-Cooperative.git`
2.  **Open project**: Use STM32CubeIDE to open the source code.
3.  **Build**: Compile the project to generate the `.hex` file.
4.  **Simulate**: Load the compiled file into the **Proteus** schematic provided in the `simulation/` folder.
