#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int stringLength = 0, itr = 0, setDelay = 250, LCDWidth = 16;
String myName = "Kandyce", subString[16];

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  scroll(1, "Float like a butterfly, sting like a bee -Muhammad Ali ");
}

void scroll(int line, String string) {
  stringLength = string.length();
  
  for (itr = LCDWidth; itr >= 0; itr--) {
    lcd.setCursor(0, line - 1);
    lcd.print(myName);
    lcd.setCursor(itr, line);
    lcd.print(string.substring(0, 16));
    delay(setDelay);
  }
  
  itr = 0;
  
  while (itr != stringLength) {
    itr++;
    lcd.setCursor(0, line);
    lcd.print(string.substring(itr,itr+16));
    delay(setDelay);
  }
}
