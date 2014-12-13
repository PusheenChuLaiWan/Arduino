#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX | TX
int inputPin=4;
int outputPin=5;
int touch_sensor = 7;
int led = 2;
void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);  // HC-06 current bound rate (default 9600)
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  pinMode(led, OUTPUT);

}

void loop()
{
  // Keep reading from HC-06 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());
  // Keep reading from Arduino Serial Monitor and send to HC-06
  if (Serial.available())
    BTSerial.write(Serial.read());
  //BTSerial.println(digitalRead(touch_sensor));
  
  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  int distance = pulseIn(inputPin, HIGH);
  distance = distance/58;
  BTSerial.println(distance);
  if(distance < 50)
      digitalWrite(led, HIGH);
  else
      digitalWrite(led, LOW);
  delay(200);
}
