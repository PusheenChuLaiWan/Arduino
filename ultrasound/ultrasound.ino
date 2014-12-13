int inputPin=4;
int outputPin=5;
void setup()
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
}

void loop()
{
  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  int distance = pulseIn(inputPin, HIGH);
  distance = distance/58;
  Serial.println(distance);
  delay(50);
}
