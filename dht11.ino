#include <Wire.h>

char humi = A0;
int sensor_val;
byte dht11_dat[5];
byte dht11_in;
byte i;

byte read_dht11_dat(){
  byte i = 0;
  byte result = 0;

  for(i = 0; i < 8; i++){
    while(!digitalRead(humi));
    delayMicroseconds(30);
    if(digitalRead(humi) != 0)
      bitSet(result, 7 - i);
    while(digitalRead(humi));
  }
  return result;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(humi, OUTPUT);
  digitalWrite(humi, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(humi, LOW);
  delay(18);
  digitalWrite(humi, HIGH);
  delayMicroseconds(5);
  pinMode(humi, INPUT);
  delayMicroseconds(200);
  for(i = 0; i < 5; i++){
    dht11_dat[i] = read_dht11_dat();
  }
  pinMode(humi, OUTPUT);
  digitalWrite(humi, HIGH);
  byte dht_check_sum = dht11_dat[0] + dht11_dat[2];

  Serial.print(dht11_dat[0], DEC);
  Serial.print('%');
  Serial.print(',');
  Serial.print(dht11_dat[2], DEC);
  Serial.println('C');
  delay(2000);
}
