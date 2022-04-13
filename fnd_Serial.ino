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
  for(int i = 0; i < 8; i++)
  {
    pinMode(seg_pin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())  // Serial.available() : Serial 통신이 가능하게함
  {   
//  방법 1 
    int a = Serial.parseInt(); // Serial.parseInt() : Serial 통신으로 입력된 값이 ASCII 값이 아닌 Integer로 나타나게 함
    Serial.println(a);
    fnd(a);
//  방법 2
//  int a  = Serial.read();
//  Serial.println(a - 48);
//  fnd(a - 48);
  }
}
