# Embedded Traffic Light Control System

Design and implement an embedded traffic light control system for a typical four-way intersection, including a pedestrian crossing feature.  using  an RTOS  , LEDs to represent traffic lights  for each direction. - LEDs for pedestrian signals (Walk/Don’t Walk). - Push button(s) to simulate pedestrian crossing requests. 


## Overview
This project implements an embedded traffic light control system for a typical four-way intersection. The system includes:
- Traffic lights (Red, Yellow, Green) for each direction.
- Pedestrian crossing signals (Walk/Don’t Walk).
- Push buttons to simulate pedestrian crossing requests.
- Designed with a Real-Time Operating System (RTOS) for efficient task management.

## Features

- **Traffic Lights**: LEDs representing Red, Yellow, and Green for each direction.
- **Pedestrian Signals**: Separate LEDs for Walk and Don’t Walk indications.
- **Push Buttons**: Simulate pedestrian crossing requests, triggering the appropriate signals.
- **RTOS Integration**: Ensures timely and reliable operation of traffic light cycles and pedestrian requests.

## Hardware Requirements

- Microcontroller (AVR 32 )
- LEDs (Red, Yellow, Green for each direction, Walk, Don’t Walk)
- Push buttons (for pedestrian requests)
- Resistors (appropriate values for LEDs)
- Simulation


## Software Requirements

- Development Environment (Eclips for avr 32)
- RTOS (e.g., FreeRTOS)
- C/C++ Compiler

## Setup Instructions

1. **Hardware Setup**:
   - Connect the LEDs to the microcontroller pins according to the following configuration:
     - Red LED: Pin -> PA2 , PA2 ,PC1 , PC3
     - Yellow LED: Pin -> PB0 , PB1 , PB2 , PB3
     - Green LED: Pin -> PA0 , PA1 ,PC0 ,PC2
     - Walk Signal BUTTON: Pin -> PD2 
     - Don’t Walk Signal BUTTON: Pin -> PD3
   - Connect the push buttons to the specified pins with pull-up resistors.

2. **Software Installation**:
   - Install the necessary IDE (ECLIPS).
   - Install proteus 
   - Set up the RTOS library (e.g., FreeRTOS) in your development environment.

3. ** To run project**:
   Open proteus and put hex file in micro controller program

