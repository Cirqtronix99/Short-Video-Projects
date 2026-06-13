const int irSensor = 9;
const int buzzer = 10;

void setup() {
  pinMode(irSensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (digitalRead(irSensor) == LOW) {   // Object detected
    digitalWrite(buzzer, HIGH);         // Turn buzzer ON
  }
  else {                                // No object detected
    digitalWrite(buzzer, LOW);          // Turn buzzer OFF
  }
}
