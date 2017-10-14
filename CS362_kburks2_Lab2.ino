const int button_increase_PIN_2 = 2, button_decrease_PIN_1 = 1;    // the number of the pushbutton pins
const int PIN_10 = 10, PIN_9 = 9, PIN_8 = 8;                         // the number of the LED pins: blue = pin_10; red = pin_9; green = pin_8
int buttonState_increase = LOW, buttonState_decrease = LOW, count = 0; // variables for reading the pushbutton status
int PIN_START = 10, PIN_STOP = 7, iterator = PIN_START;

void setup() {
  // initialize the LED pins as output:
  while(iterator > PIN_STOP){
  pinMode(iterator, OUTPUT);
  iterator--;
  }
  // initialize the pushbutton pins as input:
  pinMode(button_increase_PIN_2, INPUT);
  pinMode(button_decrease_PIN_1, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  while (buttonState_increase == LOW && buttonState_decrease == LOW) {
  buttonState_increase = digitalRead(button_increase_PIN_2);
  buttonState_decrease = digitalRead(button_decrease_PIN_1);
  }

  // INCREASE or DECREASE count accordingly
  if (buttonState_increase == HIGH) {count++;}
  if (buttonState_decrease == HIGH) {count--;}

  //reset all LEDs to LOW
  digitalWrite(PIN_10, LOW);
  digitalWrite(PIN_9, LOW);
  digitalWrite(PIN_8, LOW);
  
  // turn LEDs on:
  long light = count;
  if ((light & 1 ) == 1) {
    digitalWrite(PIN_10, HIGH);
  }
  if (((light >> 1) & 1) == 1) {
    digitalWrite(PIN_9, HIGH);
  }
  if (((light >> 2) & 1) == 1) {
    digitalWrite(PIN_8, HIGH);
  }
  delay(100);
  
  while (buttonState_increase == HIGH || buttonState_decrease == HIGH) {
    buttonState_increase = digitalRead(button_increase_PIN_2);
    buttonState_decrease = digitalRead(button_decrease_PIN_1);
  }
}
