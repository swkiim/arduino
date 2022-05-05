#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.print("Serial Monitor"); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    char mon_data = Serial.read();
    if(mon_data == '1')
    {
      lcd.setCursor(0, 1);
      lcd.print("Number 1 sent");
      Serial.println("Number 1 sent");
    }
    if(mon_data == '2')
    {
      lcd.setCursor(0, 1);
      lcd.print("Number 2 sent");
      Serial.println("Number 2 sent");
    }
  }
}
