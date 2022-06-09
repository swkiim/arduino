int ECHO = 8;
int TRIG = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int distance = Distance_cm();
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("[cm]");
  BTSerial.print(distance);
  delay(1000);
}

uint16_t Distance_cm(void){
  uint32_t timer = 0;
  uint16_t distance = 0;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  timer = pulseIn(ECHO, HIGH,24000);
  if(timer == 0){
    distance = 400;
  }else{
    distance = timer * 0.034/2;
  }
  return distance;
}
