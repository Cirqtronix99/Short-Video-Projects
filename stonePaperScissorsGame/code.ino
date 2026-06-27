#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 9;

String choices[] = {"STONE", "PAPER", "SCISSOR"};

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();

  // Make the random choice different each time
  randomSeed(analogRead(A0));

  // Initial message (shown only once)
  lcd.setCursor(0, 0);
  lcd.print("Press button");
  lcd.setCursor(0, 1);
  lcd.print("to start");
}

void loop() {

  // Wait for button press
  while (digitalRead(buttonPin) == HIGH);

  delay(50); // Debounce
  while (digitalRead(buttonPin) == LOW);

  // Countdown: 3 -> 2 -> 1 in about 2 seconds
  for (int i = 3; i >= 1; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Ready...");
    lcd.setCursor(7, 1);
    lcd.print(i);
    delay(667);
  }

  // Show random choice
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Computer:");
  lcd.setCursor(0, 1);
  lcd.print(choices[random(3)]);

  // Stay here until button is pressed again
  while (digitalRead(buttonPin) == HIGH);

  delay(50); // Debounce
  while (digitalRead(buttonPin) == LOW);

  // Loop repeats, going directly to the countdown
}
