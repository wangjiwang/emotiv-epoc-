#include <SoftwareSerial.h>

const int rxpin = 2;
const int txpin = 3; 
SoftwareSerial bluetooth(rxpin,txpin);
int temp;
int led = 13;
unsigned long starttime;
unsigned long stoptime;
unsigned long looptime;
void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
  //Serial.println("Serial ready");
  //bluetooth.println("Bluetooth ready");
}
void loop() {
  if(Serial.available()>0){
    temp = Serial.read();
    starttime = millis();
    Serial.print("the starttime");
    Serial.println(starttime);
    
    delay(1000);
   
    if(Serial.available()>0){
      digitalWrite(led,HIGH);
      temp = Serial.read();
      stoptime = millis();
      Serial.print("the stoptime");
      Serial.println(stoptime);
      
     looptime = stoptime - starttime;
     Serial.println(looptime);
     
    char c=(char)Serial.read();
    //bluetooth.println("Arduino:");
    bluetooth.write(c);
   }
   else{
    digitalWrite(led,LOW);
   }
 }
}
