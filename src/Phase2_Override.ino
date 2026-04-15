/*
 * Project: Smart Night-Light System (Phase 2)
 * Author: [Emeka / @EmekaBuilds_ on X]
 * Date: April 2026
 */

const int sensorPin = A0;
const int ledPin = 13;
const int buttonPin = 2;   
const int buzzerPin = 8;   

int threshold = 400;
bool systemActive = true;  
int lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); 
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(sensorPin);
  int currentButtonState = digitalRead(buttonPin);

  if (currentButtonState == LOW && lastButtonState == HIGH) {
    systemActive = !systemActive; 
    
    if (systemActive) {
      // SUCCESS CHIRP: Double beep (ON)
      digitalWrite(buzzerPin, HIGH); delay(60); digitalWrite(buzzerPin, LOW);
      delay(60);
      digitalWrite(buzzerPin, HIGH); delay(60); digitalWrite(buzzerPin, LOW);
    } else {
      // ALERT BEEP
      digitalWrite(buzzerPin, HIGH); 
      delay(500); // 
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW); 
    }
    delay(300); // debounce to prevent accidental double-toggles
  }
  lastButtonState = currentButtonState;

  if (systemActive) {
    if (lightLevel < threshold) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }

  Serial.print("Light: "); Serial.print(lightLevel);
  Serial.print(" | System Active: "); Serial.println(systemActive);
}
