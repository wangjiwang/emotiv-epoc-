#include <SoftwareSerial.h>

const int rxpin = 2;
const int txpin = 3; 
SoftwareSerial bluetooth(rxpin,txpin);
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Serial.println("Serial ready");
  bluetooth.println("Bluetooth ready");
}

void loop() {
  if(bluetooth.available()){
    char c = (char)bluetooth.read();
    Serial.write(c);
  }
  
  if(Serial.available()){ 
    char d=(char)Serial.read();
    bluetooth.write(d);
   }
  }
