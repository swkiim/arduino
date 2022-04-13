#include <SoftwareSerial.h>
SoftwareSerial btSerial(2, 3);

int seg_pin[8] = {4, 5, 6, 7, 8, 9, 10, 11};
int seg_data[16][8] = {{1,1,1,1,1,1,0,0}, {0,1,1,0,0,0,0,0}, // fnd 0, 1
                        {1,1,0,1,1,0,1,0}, {1,1,1,1,0,0,1,0}, // fnd 2, 3
                        {0,1,1,0,0,1,1,0}, {1,0,1,1,0,1,1,0}, // fnd 4, 5
                        {1,0,1,1,1,1,1,0}, {1,1,1,0,0,1,0,0}, // fnd 6, 7
                        {1,1,1,1,1,1,1,0}, {1,1,1,1,0,1,1,0}, // fnd 8, 9
                        {1,1,1,0,1,1,1,0}, {0,0,1,1,1,1,1,0}, // fnd A, B
                        {1,0,0,1,1,1,0,0}, {0,1,1,1,1,0,1,0}, // fnd C, D
                        {1,0,0,1,1,1,1,0}, {1,0,0,0,1,1,1,0}}; // fnd E, F

void fnd(int j){
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(seg_pin[i], seg_data[j][i]);
  }
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Serial 통신 속도 지정
  btSerial.begin(9600);
  for(int i = 0; i < 8; i++)
  {
    pinMode(seg_pin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(btSerial.available() > 0)
  {   
    int a = btSerial.read();
    Serial.println(a);
    fnd(a);
  }
}
