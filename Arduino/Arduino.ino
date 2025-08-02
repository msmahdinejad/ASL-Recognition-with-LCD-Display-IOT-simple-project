#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
String sentence = "";

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      lcd.clear();
      lcd.print(sentence);
      sentence = "";
    } else if (c >= 32) {
      sentence += c;
    }
  }
}