int servoPin = 2;
int pulse = 2500;

void setup()
{
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(pulse);
  digitalWrite(servoPin, LOW);
  delay(20);
} 
