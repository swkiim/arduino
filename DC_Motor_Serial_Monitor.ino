int pin_DC_N = 6;
int pin_DC_P = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_DC_N, OUTPUT);
  pinMode(pin_DC_P, OUTPUT);
  digitalWrite(pin_DC_P, LOW);
  digitalWrite(pin_DC_N, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Speed;
  int m_con;
  if(Serial.available() > 0){
    m_con = Serial.read();
    if(m_con == '1'){
      Serial.println("시계방향");
      cw();
    }
    if(m_con == '2'){
      Serial.println("반시계방향");
      ccw();
    }
    if(m_con == '3'){
      Serial.println("모터 멈춤");
      Stop();
    }
  }
}

void cw(){
  int m_con;
  int i;
  for(i = 0; i < 255; i++){
    m_con = Serial.read();
    if(m_con == '3'){
      Stop();
      Serial.println("모터 멈춤");
      break;
    }
    Motor_CW(i);
    delay(20);
  }
}

void ccw(){
  int m_con;
  int i;
  for(i = 255; i > 0; i--){
    m_con = Serial.read();
    if(m_con == '3'){
      Stop();
      Serial.println("모터 멈춤");
      break;
    }
    Motor_CCW(i);
    delay(20);
  }
}

void Motor_CW(unsigned char i){
  digitalWrite(pin_DC_N, LOW);
  analogWrite(pin_DC_P, i);
}

void Motor_CCW(unsigned char i){
  digitalWrite(pin_DC_P, LOW);
  analogWrite(pin_DC_N, i);
}

void Stop(void){
  digitalWrite(pin_DC_N, LOW);
  digitalWrite(pin_DC_P, LOW);
}
