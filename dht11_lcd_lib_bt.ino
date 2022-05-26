#include <SoftwareSerial.h>
#include <Wire.h>
#include <DHT11.h>
#include <LiquidCrystal_I2C.h>

int ths = A0;
int i;
byte p_data;
float humi, temp;

DHT11 dht11(ths);
LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial BTSerial(2, 3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  lcd.init();
  lcd.home();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  int p_data;
  if(BTSerial.available() > 0){
    p_data = BTSerial.read();
    i = dht11.read(humi, temp);
    if(i == 0){
      if(p_data == 1){
        Serial.print("Temperature : ");
        Serial.println(temp);
        BTSerial.print("현재 온도 : ");
        BTSerial.print(temp, 0);
        BTSerial.print(" C deg");
      }
      if(p_data == 2){
        Serial.print(" Humidity : ");
        Serial.println(humi);
        BTSerial.print("현재 습도 : ");
        BTSerial.print(humi, 0);
        BTSerial.print(" %");
      }
      else{
        Serial.print("Error No : ");
        Serial.println(i);
      }
    }
  }
  lcd.setCursor(0, 0);
  lcd.print("HUMI : ");
  lcd.print(humi);
  lcd.print(" %");
  lcd.setCursor(0, 1);
  lcd.print("TEMP : ");
  lcd.print(temp);
  lcd.print(" C");
  delay(2000);
}
