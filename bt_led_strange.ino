#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

byte phonedata;
int led = 4;
int sw = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(sw, INPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available()){
    phonedata = mySerial.read();
    Serial.println(phonedata);
    if(phonedata == 1){
      digitalWrite(led, HIGH);
      Serial.println("data 1");
    }
    if(phonedata == 2){
      digitalWrite(led, LOW);
      Serial.println("data 2");
    }
    delay(1000);
  }
  if(digitalRead(sw) == HIGH){
      mySerial.print(3);
      Serial.println("Door is Closed");
    }
  delay(1000);  
  if(digitalRead(sw) == LOW){
      mySerial.print(4);
      Serial.println("Door is Opened");
    }
  delay(1000);
}
