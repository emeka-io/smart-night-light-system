# Smart Night-Light System
----

#### An automated LED lighting system designed to optimize energy consumption by responding to environmental light conditions. This project is being built in three iterative phases.
---
## See it in Action
Check out the project demonstration on X:
* [Watch the Phase 2 Demo: Manual Override & Acoustic Feedback](https://x.com/EmekaBuilds_/status/2044038754789134508?s=20)
* [Watch the Phase 1 Demo: Autonomous Core](https://x.com/EmekaBuilds_/status/2043312047945891887?s=20)


## Project Phases
- [x] **Phase 1: The Core** - Autonomous light sensing and LED triggering.
- [x] **Phase 2: User Control** - Manual override button and acoustic (Buzzer) feedback.
- [ ] **Phase 3: System Stability** - Implementation of hysteresis logic for professional stability.

## Phase 1: The Core Logic

### The Problem
Manual lighting systems are often left on unnecessarily, leading to energy waste. In dark environments, finding a manual switch can also be inconvenient.
### The Solution
The initial version uses a **Photoresistor (LDR)** and an **Arduino Uno** to create a "Sense-Think-Act" loop. The system automatically triggers the LED when ambient light drops below a specific threshold.

## Circuit Diagram

To ensure a clean signal flow, I mapped the voltage divider and LED output. This diagram serves as the blueprint for the Phase 1 build.

![Phase 1 Layout](./assets/phase1-circuit-diagram.png)


## Physical Build

A clear picture of my wiring.

![Phase 1 Build](./assets/phase1-wiring.jpeg)

### Components Used
* Arduino Uno
* Photoresistor (LDR 5528)
* 10K Ohm Resistor (Pull-down)
* 220 Ohm Resistor (LED Current Limiting)
* LED (Yellow, any colour can be used)
* Breadboard and Jumper Wires

### How it Works
The system uses a **Voltage Divider** circuit to convert the variable resistance of the LDR into a readable analog voltage (0-5V). The Arduino processes this via its Analog-to-Digital Converter (ADC), turning the LED `HIGH` when the environment is dark.

---

## Phase 2: Manual Override & Feedback

### The Problem
Purely autonomous lights can be annoying. If you’re trying to sleep or watch a movie, you don't want the LED on everytime the room is dark. A system without a "manual off" switch is incomplete.

### The Solution
I added a **tactile button** so the user can turn off the LED when the light isn't needed. To make the interface feel natural, I included an **active buzzer**. It provides a quick "status chirp" so you aren't guessing whether the override is active or not.

## Circuit Diagram

I updated the schematic to include the manual control and the HMI (Human-Machine Interface) feedback loop.

![Phase 2 Layout](./assets/phase2-circuit-diagram.png)

## Physical Build

The updated breadboard layout with the button and buzzer integrated.

![Phase 2 Build](./assets/phase2-wiring.jpeg)

### Components Added
* Tactile Push Button
* Active Buzzer (5V)
* Extra Jumper Wires

### How it Works
The code now monitors **Digital Pin 2** for a button press. By using the Arduino’s internal `INPUT_PULLUP` resistor, the wiring stays clean. When pressed, the system toggles a boolean state: 
* **System Active:** Normal LDR logic applies (Double chirp).
* **System Disabled:** LED is forced `LOW` regardless of light levels (Long beep).
## Repository Structure
* `/src`: Contains the `.ino` source code for each phase.
* `/assets`: Contains the wiring diagrams and project photos for each phase.
