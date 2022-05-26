#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

char  humi = A0;
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
  lcd.init();
  lcd.home();
  lcd.backlight();
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
  byte dht11_check_sum = dht11_dat[0] + dht11_dat[2];

  lcd.setCursor(0, 0);
  lcd.print("Humi : ");
  lcd.print(dht11_dat[0]);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp : ");
  lcd.print(dht11_dat[2]);
  lcd.print("C");

  Serial.print("Humidity : ");
  Serial.print(dht11_dat[0], DEC);
  Serial.println('%');
  Serial.print("Temperature : ");
  Serial.print(dht11_dat[2], DEC);
  Serial.println('C');
  delay(2000);
}
