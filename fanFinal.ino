#include <dht.h> // including library

dht DHT;

#define DHT11_PIN 7

int pinRelay = 6; // defining pin

void setup() {
  pinMode( pinRelay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
int chk = DHT.read11(DHT11_PIN); // checking temp
if ( DHT.temperature > 30.0 ){
  digitalWrite( pinRelay, HIGH);
  Serial.print("Relay ON ");
}

if ( DHT.temperature < 30.0 ) {
  digitalWrite( pinRelay, LOW);
  Serial.print("Relay OFF ");
}

Serial.print("Temperature = ");
Serial.println(DHT.temperature);
delay (1000);  

} 
