#include <DHT11.h>
int ths = A0;
DHT11 dht11(ths);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  }
  else{
    Serial.print("Error : ");
    Serial.print(i);
  }
  delay(2000);
}
