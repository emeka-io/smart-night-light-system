# Phase 1: Basic Photo-Sensitive Logic & Thresholding

## 1. Overview
Phase 1 marks the "Genesis" of the Smart Light System. The goal was to move away from manual switches and create a light that "thinks" for itself. This phase established the fundamental "Sense-Think-Act" loop that governs the entire project.

## 2. The Problem
**Energy Waste & Inconvenience.** Standard lights are "dumb"—they stay on until a human physically flips a switch. This leads to two main issues:
1. **Wasted Power:** Lights are often left on in broad daylight because people forget to turn them off.
2. **Safety/Inconvenience:** Searching for a physical light switch in a pitch-black room is frustrating and can be a tripping hazard.

## 3. The Solution: The "Sense-Think-Act" Loop
I built an automated system that monitors its environment in real-time. By using a **Photoresistor (LDR)** as an "eye," the Arduino constantly measures brightness and decides whether to act.

**The Logic Flow:**
- **Sense:** The LDR detects the current light level.
- **Think:** The Arduino compares that level to a pre-set "Darkness" value.
- **Act:** If it's too dark, the Arduino snaps the LED on instantly. No human intervention required.

## 4. Technical Specifications (BOM)
| Component | Specification | Role |
| :--- | :--- | :--- |
| **Arduino Uno** | ATmega328P | The "Brain" (Decision Maker) |
| **LDR (Photo Resistor 5528)** | 5mm GL55 Series | The "Eye" (Light Sensor) |
| **10kΩ Resistor** | Fixed Resistor | Pull-down for LDR Voltage Divider |
| **220Ω Resistor** | Fixed Resistor | Current Limiter (Protects the LED) |
| **LED** | 5mm Standard | The "Output" (The Light) |


### System Architecture
Below is the wiring diagram and physical prototype for Phase 1:

![Circuit Diagram](../assets/phase1-circuit-diagram.png)
*Figure 1: Schematic of the LDR Voltage Divider.*

![Physical Wiring](../assets/phase1-wiring.jpeg)
*Figure 2: Breadboard implementation of the basic Sense-Think-Act loop.*

## 5. Implementation & Code Snippet
The system uses a **Threshold Value of 450 (ADC counts)**. This is the "tipping point" where the system decides it is officially "dark."

```cpp
// Phase 1 Logic: The Decision Maker
int ldrValue = analogRead(A0); // Sensing the room

if (ldrValue < 450) { 
  // It is dark -> ACT
  digitalWrite(ledPin, HIGH); 
} else { 
  // It is bright -> STAY OFF
  digitalWrite(ledPin, LOW); 
}
```

## 6. Observations & Limitations
After testing Phase 1, I realized that pure automation is actually a headache. The system was "smart" enough to detect light, but too "dumb" to know when I didn't want it on.

### The "Cinema" Problem:
I noticed a major flaw in the logic during real-world use. If I wanted to watch a movie or try to sleep in a dark room, the LED would snap ON and stay there. There was no way to tell the system, "I know it's dark, but keep the light off".

Key Takeaways:
- **Total Automation isn't always better**: A system without a manual off switch is incomplete and intrusive.
- **Sensor Jitter**: Near the 450 threshold, the light would flicker(blink) rapidly.
