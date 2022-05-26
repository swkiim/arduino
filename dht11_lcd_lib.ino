#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT11.h>

int ths = A0;

DHT11 dht11(ths);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.home();
  lcd.backlight();  
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  float humi, temp;
  if((i = dht11.read(humi, temp)) == 0){
    Serial.print("Humidity : ");
    Serial.println(humi);
    Serial.print("Temperature : ");
    Serial.println(temp);

    lcd.setCursor(0, 0);
    lcd.print("HUMI : ");
    lcd.print(humi);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("TEMP : ");
    lcd.print(temp);
    lcd.print("C");
  }
  else{
    Serial.print("Error : ");
    Serial.print(i);
  }
  delay(2000);
}
