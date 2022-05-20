byte mp[4] = {4, 5, 6, 7};
byte p[4] = {B1000, B0100, B0010, B0001};
byte n[4] = {B0001, B0010, B0100, B1000};

byte data;

void setup() {
  // put your setup code here, to run once:
  for(int k = 0; k < 4; k++){
    pinMode(mp[k], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    data = Serial.read();
    if(data == '1'){
      right();
    }
    if(data == '2'){
      left();
    }
    if(data == '3'){
      Serial.println("정지");
      Stop(); 
    }
  }
}

void right(){
  Serial.println("시계방향");
  for(int i = 0; i < 512; i++){
    data = Serial.read();
    if(data == '2'){
      left();
    }
    if(data == '3'){
      Stop();
    }
    right_step();
  }
}

void left(){
  Serial.println("반시계방향");
  for(int i = 0; i < 512; i++){
    data = Serial.read();
    if(data == '1'){
      right();
    }
    if(data == '3'){
      Stop();
    }
    left_step();
  }
}

void right_step(){
  for(int j = 0; j < 4; j++){
    for(int k = 0; k < 4; k++){
      digitalWrite(mp[k], bitRead(p[j], k));
      delay(3);
    }
  }
}

void left_step(){
  for(int j = 0; j < 4; j++){
    for(int k = 0; k < 4; k++){
      digitalWrite(mp[k], bitRead(n[j], k));
      delay(3);
    }
  }
}

void Stop(){
  for(int i; i < 4; i++){
    digitalWrite(mp[i], LOW);
    delay(3);
  }
}

