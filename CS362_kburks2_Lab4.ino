#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int pResistor = A0, line1 = 0;
int value = 0, itr = 0;

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(pResistor, INPUT);
}

void loop() {
  value = analogRead(pResistor);
  displayBrightness(value);
}

void displayBrightness(int value) {
  lcd.setCursor(0, line1);
  
  if (value <= 205) {
    lcd.print("Dark");
  }
  
  else if (value <= 410) {
    lcd.print("Partially Dark");
  }
  
  else if (value <= 615) {
    lcd.print("Medium");
  }
  
  else if (value <= 820) {
    lcd.print("Partially Light");
  }
  
  else if (value <= 1023) {
    lcd.print("Fully Lit");
  }
  
  lcd.setCursor(0, line1);
  delay(500);
  
  for (itr  = 0; itr < 16; itr++) {
    lcd.print(" ");
  }
}

