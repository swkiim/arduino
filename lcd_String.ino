#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

SoftwareSerial mySerial(2, 3);
LiquidCrystal_I2C lcd(0x27, 16, 2);

String s0, s1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.print("I2C LCD TESTING"); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    s0 = Serial.readString();
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print(s0);
    Serial.println(s0);
    mySerial.print(s0);
    delay(2000);
  }
  if(mySerial.available())
  {
    s1 = mySerial.readString();
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(s1);
    Serial.println(s1);
  }
}
