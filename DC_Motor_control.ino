int pin_MOTOR_N = 6;
int pin_MOTOR_P = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_MOTOR_P, OUTPUT);
  pinMode(pin_MOTOR_N, OUTPUT);
  digitalWrite(pin_MOTOR_P, LOW);
  digitalWrite(pin_MOTOR_N, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  
  // 시계방향 회전
  for(i = 0; i < 256; i++){
    ClockWise(i);
    delay(10);
  }
  for(i = 255; i > 0; i--){
    ClockWise(i);
    delay(10);
  }
  MotorStop();
  delay(1000);

  // 반시계방향 회전
  for(i = 0; i < 256; i++){
    CountClockWise(i);
    delay(10);
  }
  for(i = 255; i > 0; i--){
    CountClockWise(i);
    delay(10);
  }
  MotorStop();
  delay(1000);
}

void ClockWise(int Speed){ // 시계방향으로 회전하는 함수
  digitalWrite(pin_MOTOR_N, LOW); // N off
  digitalWrite(pin_MOTOR_P, Speed); // P on
}

void CountClockWise(int Speed){ // 반시계방향으로 회전하는 함수
  analogWrite(pin_MOTOR_N, Speed);
  digitalWrite(pin_MOTOR_P, LOW);
}

void MotorStop(){ // 모터를 정지하는 함수
  digitalWrite(pin_MOTOR_N, LOW);
  digitalWrite(pin_MOTOR_P, LOW);
}
