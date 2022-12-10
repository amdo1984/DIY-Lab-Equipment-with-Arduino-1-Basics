
int sensor = 0;

void setup() {

  pinMode(3, OUTPUT);
  pinMode(8, INPUT);

}

void loop() {
  sensor = digitalRead(8);
  if (sensor == 1)
  {
    digitalWrite(3, HIGH);
  }
  else
  {
    digitalWrite(3, LOW);
  }

}