const int pResistor = A0, potentiometer = A1; // Photoresistor at analog pin A0 -- Potentiometer at analog pin A1
int value = 0;         // Stores value from photoresistor (0-1023)

int LED3 = 3, LED9 = 9, LED5 = 5, LED6 =  6;

int buzzer = 10;

int potentiometerValue = 0;

void setup() {
  
  Serial.begin(9600);
  pinMode(pResistor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);

}

void loop() {
  
  value = analogRead(pResistor);
  potentiometerValue = analogRead(potentiometer);
  analogWrite(buzzer, potentiometerValue/4);
  displayBrightness(value);
  
}

void displayBrightness(int value) {
  
  if (value <= 205) {
    digitalWrite(LED3, LOW);
    digitalWrite(LED9, LOW);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
  }
  
  else if (value <= 410) {
    digitalWrite(LED3, HIGH);
  }
  
  else if (value <= 615) {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
  }
  
  else if (value <= 820) {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, LOW);
  }
  
  else if (value <= 1023) {
    digitalWrite(LED3, HIGH);
    digitalWrite(LED9, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
  }
}

