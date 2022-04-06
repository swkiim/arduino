#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);

byte phone_date;
int led13 = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(led13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available() > 0){
    phone_data = BTSerial.read();
    Serial.println("LED13 ON");
  }
  if(phone_data == 2){
    digitalWrite(led13, LOW);
    Serial.println("LED13 OFF");
  }
}
