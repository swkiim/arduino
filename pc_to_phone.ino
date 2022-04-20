#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);

String s0; // string으로 데이터를 수신

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    mySerial.write(Serial.read());
  }
  if(mySerial.available())
  {
    s0 = mySerial.readString();
    Serial.print(s0); // 문자열을 출력하는 Serial명령어
//    Serial.write(mySerial.read());
    Serial.println();
  }
}
