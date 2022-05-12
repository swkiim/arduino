#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);

int pin_DC_N = 6;
int pin_DC_P = 9;
String Instring;
int Speed;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin_DC_N, OUTPUT);
  pinMode(pin_DC_P, OUTPUT);
  digitalWrite(pin_DC_P, LOW);
  digitalWrite(pin_DC_N, LOW);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available() > 0){
    Instring = BTSerial.readString();
    Speed = Instring.toInt();
    Serial.println(Speed);
    if(Speed > 0){
      Serial.println("시계방향");
      cw(Speed);
    }else if(Speed < 0){
      Serial.println("반시계방향");
      ccw(abs(Speed));
    }else{
      Serial.println("모터 멈춤\n");
      Stop();
    }
  }
}

void cw(int right){
  int stop_val;
  for(;;){
    Instring = BTSerial.readString();
    stop_val = Instring.toInt();
    if(stop_val > 256){
      Stop();
      Serial.println("모터 멈춤\n");
      break;
    }
    Motor_CW(right);
    delay(20);
  }
}

void ccw(int left){
  int stop_val;
  for(;;){
    Instring = BTSerial.readString();
    stop_val = Instring.toInt();
    if(stop_val > 256){
      Stop();
      Serial.println("모터 멈춤\n");
      break;
    }
    Motor_CCW(left);
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
