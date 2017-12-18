void setup() {
  pinMode(PIN_PC1, INPUT);
  pinMode(PIN_PD6, INPUT);
  pinMode(PIN_PD5, INPUT);
  pinMode(PIN_PB0, OUTPUT);
  pinMode(PIN_PB1, OUTPUT);
  pinMode(PIN_PC3, OUTPUT);

  digitalWrite(PIN_PC3, HIGH);
  digitalWrite(PIN_PB1, LOW);
  digitalWrite(PIN_PB0, LOW);
}

int val, check;
void loop() {
  val = digitalRead(PIN_PD5);
  check = digitalRead(PIN_PD6);
  if(val == HIGH && check == LOW)
  {
    digitalWrite(PIN_PC3, LOW);
    digitalWrite(PIN_PB0, HIGH);
    if(analogRead(PIN_PC1) < 700)
    {
      digitalWrite(PIN_PB1, HIGH);
    }
    else
    {
      digitalWrite(PIN_PB1, LOW);
    }
  }
  if(check == HIGH)
  {
    digitalWrite(PIN_PB0, LOW);
  }
}
