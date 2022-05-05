#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

SoftwareSerial mySerial(2, 3);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.print("Smart COMM Test"); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available() > 0)
  {
    byte mon_data = mySerial.read();
    if(mon_data == 1)
    {
      lcd.setCursor(0, 1);
      lcd.print("        ");
      lcd.setCursor(0, 1);
      lcd.print("Number 1 sent");
      Serial.println("You Sent Number 1");
    }
    else if(mon_data == 2)
    {
      lcd.setCursor(0, 1);
      lcd.print("        ");
      lcd.setCursor(0, 1);
      lcd.print("Number 2 sent");
      Serial.println("You Sent Number 2");
    }
    else if(mon_data == 'a')
    {
      lcd.setCursor(0, 1);
      lcd.print("        ");
      lcd.setCursor(0, 1);
      lcd.print("Char is sent ");
      Serial.println("You Sent Char");
    }
  }
}
