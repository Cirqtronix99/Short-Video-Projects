#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD address is usually 0x27 or 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int trigPin = 2;
const int echoPin = 3;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Distance Meter");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration;
  float distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.0343 / 2;

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance:");

  lcd.setCursor(0, 1);
  lcd.print(distance, 1);
  lcd.print(" cm     "); // extra spaces clear old text

  delay(200);
}
