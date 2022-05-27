#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Wire.h> 
#include <Keypad.h>
#include "DHT.h"

#define Password_Length 8  
#define DHTPIN 23         
#define DHTTYPE DHT11     
#define gasSensorPin A0
   
DHT dht(DHTPIN, DHTTYPE);
    
Servo myservo;
int pos = 0;
int openPos = 180;
int closePos = 0;
     
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

int Buzzer = 33;
int FlameSensor = 31;
int flame;

float gas;
int device1 = 37;
int device2 = 39;

void setup(){
  lcd.begin(); 
  lcd.backlight();
  dht.begin();
  Serial3.begin(9600);

  pinMode(RedLightPin, OUTPUT);
  pinMode(GreenLightPin, OUTPUT);
  pinMode(BlueLightPin, OUTPUT);

  pinMode(Buzzer, OUTPUT);
  pinMode(FlameSensor, INPUT);

  myservo.attach(35);
  pos = closePos;
  myservo.write(pos);
 
  pinMode(device1, OUTPUT);
  pinMode(device2, OUTPUT);
}

void loop() {
  // Keypad Door System
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
  
  customKey = customKeypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    lcd.setCursor(data_count,1); 
    //lcd.print(Data[data_count]);
    lcd.print('*');
    data_count++; 
    }

  if(data_count == Password_Length-1){
    lcd.clear();

    if(!strcmp(Data, Master)){
      lcd.setCursor(0, 0);
      lcd.print("Welcome Home");
      myservo.write(openPos);
      RGBColor(0, 255, 0); // Green LED Light Up
      lcd.setCursor(0, 1);
      lcd.print("Door Open");
      delay(2000);
      RGBColor(0, 0, 0); // LED Light OFF
      myservo.write(closePos);
      }
    else{
      lcd.print("Incorrect");
      RGBColor(255, 0, 0); // Red LED Light Up
      delay(1000);
      RGBColor(0, 0, 0); // LED Light OFF
      }
      
      lcd.clear();
      clearData();
  }
  
  // Read Temperature and Humidity from DHT11 Sensor
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  
  // Send Temperature and Humidity Data to MIT App via Bluetooth 
  Serial3.print(temp);
  Serial3.print(";");
  Serial3.print(hum);
  Serial3.print(";");

  // Flame Detected System
  flame = digitalRead(FlameSensor);
  if(flame == 1) {
    Serial3.print(flame);
    Serial3.print(";");
    digitalWrite(Buzzer, HIGH); // Buzzer ON
    RGBColor(255, 0, 0); // RED LED Light Up
  }
  else {
    digitalWrite(Buzzer, LOW);  // Buzzer OFF
  }

  // Gas (Smoke) Detected System
  gas = analogRead(gasSensorPin);
  if (gas > 800) {
    Serial3.print(gas);
    Serial3.print(";");
    digitalWrite(Buzzer, HIGH);
    RGBColor(255, 0, 0);
  }
  else {
    digitalWrite(Buzzer, LOW);
  }

  // Home Appliance Control
  if(Serial3.available() > 0) {
    int phone_data = Serial3.parseInt();
    if(phone_data == 1) {
      digitalWrite(device1, HIGH);
    }
    else if(phone_data == 2) {
      digitalWrite(device1, LOW);
    }
    else if(phone_data == 3) {
      digitalWrite(device2, HIGH);
    }
    else if(phone_data == 4) {
      digitalWrite(device2, LOW);
    }
  }
}

void clearData(){
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  return;
}

void doorOpen() {
  for (pos = 180; pos >= 0; pos -= 5) { 
    myservo.write(pos);              
    delay(15);                       
  }
}

void doorClose() {
  for (pos = 0; pos <= 180; pos += 5) { 
    myservo.write(pos);              
    delay(15);                       
  }
}

void RGBColor(int RedLightValue, int GreenLightValue, int BlueLightValue) {
  analogWrite(RedLightPin, RedLightValue);
  analogWrite(GreenLightPin, GreenLightValue);
  analogWrite(BlueLightPin, BlueLightValue);
}
