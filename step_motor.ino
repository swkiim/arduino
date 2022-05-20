byte mp[4] = {4, 5, 6, 7};
byte p[4] = {B1000, B0100, B0010, B0001};
byte n[4] = {B0001, B0010, B0100, B1000};

void setup() {
  // put your setup code here, to run once:
  for(int k = 0; k < 4; k++){
    pinMode(mp[k], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 512; i++){
    for(int j = 0; i < 4; j++){
      for(int k = 0; k < 4; k++){
        digitalWrite(mp[k], bitRead(p[j], k));
        delay(3);
      }
    }
  }
  delay(3000);
}
