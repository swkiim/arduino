#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h> 
#include <Keypad.h>
#include "DHT.h"

#define Password_Length 8  
#define DHTPIN 23         
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
Servo servo1;
Servo servo2;
int pos = 90;
int openPos = 0;
int closePos = 90;

char Data[Password_Length]; 
char Master[Password_Length] = "123A456"; 
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

LiquidCrystal_I2C lcd(0x27, 16, 2);

int RedLightPin = 25;
int GreenLightPin = 29;
int BlueLightPin = 27;

void setup() {
  lcd.begin(); 
  lcd.backlight();
  dht.begin();
  Serial3.begin(9600);
  Serial.begin(9600);

  pinMode(RedLightPin, OUTPUT);
  pinMode(GreenLightPin, OUTPUT);
  pinMode(BlueLightPin, OUTPUT);

  servo1.attach(31);
  servo2.attach(33);
  servo1.write(pos);
  servo2.write(pos);
  pos = closePos;
}

void loop() {
  // Read Temperature and Humidity from DHT11 Sensor
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Send Temperature and Humidity Data to MIT App via Bluetooth 
  Serial3.print(temp);
  Serial3.print(";");
  Serial3.print(hum);
  Serial3.print(";");

  if(Serial3.available() > 0) {  
    int phone_data = Serial3.read();
    Serial.print(phone_data);
    if(phone_data == 1) {
      lcd.setCursor(0, 0);
      lcd.print("Welcome         ");
      servo2.write(openPos);
      RGBColor(0, 255, 0); // Green LED Light Up
      lcd.setCursor(0, 1);
      lcd.print("Door Open");
      delay(2000);
      RGBColor(0, 0, 0); // LED Light OFF
      lcd.setCursor(0, 1);
      lcd.print("                ");  
    }
    else if(phone_data == 0) {
      lcd.setCursor(0, 0);
      lcd.print("Good Bye        ");
      servo2.write(closePos);
      RGBColor(255, 0, 0); // Red LED Light Up
      lcd.setCursor(0, 1);
      lcd.print("Door Close");
      delay(2000);
      RGBColor(0, 0, 0); // LED Light OFF
      lcd.setCursor(0, 1);
      lcd.print("                ");  
    }
  }
  
  // Keypad Door System
  lcd.setCursor(0, 0);
  lcd.print("Enter Password ");
  
  customKey = customKeypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    lcd.setCursor(data_count,1); 
    lcd.print(Data[data_count]);
    data_count++; 
  }

  if(data_count == Password_Length-1){
    lcd.clear();

    if(!strcmp(Data, Master)){
      lcd.setCursor(0, 0);
      lcd.print("Welcome         ");
      servo1.write(openPos);
      RGBColor(0, 255, 0); // Blue LED Light Up
      lcd.setCursor(0, 1);
      lcd.print("Door Open       ");
      delay(5000);
      RGBColor(0, 0, 0); // LED Light OFF
      servo1.write(closePos);
    }
    else{
      lcd.print("Incorrect       ");
      RGBColor(255, 0, 0); // Red LED Light Up
      delay(1000);
      RGBColor(0, 0, 0); // LED Light OFF
    }
      lcd.clear();
      clearData();
  }
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}

void RGBColor(int RedLightValue, int GreenLightValue, int BlueLightValue) {
  analogWrite(RedLightPin, RedLightValue);
  analogWrite(GreenLightPin, GreenLightValue);
  analogWrite(BlueLightPin, BlueLightValue);
}
