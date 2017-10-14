#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int stringLength = 0, itr = 0, k = 0, setDelay = 200, screenLength = 16, nameLength = 0;
char myName = "Kandyce";

void scroll(int line, char string[]) {
  stringLength = strlen(string);
  nameLength = strlen(myName);
  for (itr = screenLength; itr >= -48; itr--) {
    lcd.setCursor(1, line - 1);
    lcd.print(myName);
    lcd.setCursor(itr, line);
    if (itr <= 0 && itr > -9) {
      lcd.setCursor(itr - 8, line);
    }
    else if (itr == -9) {
      itr = -33;
      lcd.setCursor(itr, line);
    }
    lcd.print(string);
    delay(setDelay);
  }
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  scroll(1, "I Work Hard To Dream Big ");
  lcd.clear();
}
