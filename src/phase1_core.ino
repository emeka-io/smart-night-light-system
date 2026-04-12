/*
 * Project: Smart Night-Light System (Phase 1)
 * Author: [Emeka / @EmekaBuilds_ on X]
 * Date: April 2026
 */

int sensorPin = A0;    // The Photoresistor is on A0
int ledPin = 13;       // The LED is on Pin 13
int lightLevel;        // Variable to store the reading
int threshold = 400;   // The "Darkness" limit 

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  lightLevel = analogRead(sensorPin); // Read the light (0 to 1023)
  
  // Print the value to the Serial Monitor for calibration
  Serial.print("Current Light Level: ");
  Serial.println(lightLevel);

  if (lightLevel < threshold) {
    digitalWrite(ledPin, HIGH); // When it's dark, Turn light ON
  } else {
    digitalWrite(ledPin, LOW);  // When it's bright, Turn light OFF
  }

  delay(100); // Small pause so the serial monitor doesn't fly by
}

