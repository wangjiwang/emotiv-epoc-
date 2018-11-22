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
  //手机————>Arduino
  if(bluetooth.available()){
    char c = (char)bluetooth.read();
    Serial.println("手机：");
    Serial.write(c);
  }
    //Arduino—————>手机
  if(Serial.available()){ 
    char d=(char)Serial.read();
    bluetooth.println("Arduino:");
    bluetooth.write(d);
   }
  }
