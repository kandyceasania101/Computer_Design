int PIN_12 = 12, PIN_11 = 11;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIN_12, OUTPUT);
  pinMode(PIN_11, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(200);
  digitalWrite(LED_BUILTIN, LOW);
  delay(200);
  digitalWrite(PIN_12, HIGH);
  delay(200);
  digitalWrite(PIN_12, LOW);
  delay(200);
  digitalWrite(PIN_11, HIGH);
  delay(200);
  digitalWrite(PIN_11, LOW);
  delay(200);
}
