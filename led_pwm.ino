int led[] = 13;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 2; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 2; i++){
    for(int fade_value = 0; fade_value <= 255; fade_value += 5){
      analogWrite(led[i], fade_value);
      delay(30);
    }
    for(int fade_value = 255; fade_value >= 0; fade_value -= 5){
      analogWrite(led[i], fade_value);
      delay(30);
    }
  }
}
