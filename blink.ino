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
    if(temp==97){  //皱眉发送挂断电话信号
        Serial.print("off off");
        bluetooth.print(2);
    }
    //如果想加入更多指令操控，以相同方式写在这里
    else{
        starttime = millis();
        Serial.print("the starttime");
        Serial.println(starttime);
        
        delay(1000);
    //判断眨眼两次发送拨打电话信号   
        if(Serial.available()>0){
          digitalWrite(led,HIGH);
          temp = Serial.read();
          stoptime = millis();
          Serial.print("the stoptime");
          Serial.println(stoptime);
          
         looptime = stoptime - starttime;
         Serial.println(looptime);
         int c=Serial.read();
        //bluetooth.println("Arduino:");
         bluetooth.print(c);
       }
       else{
        digitalWrite(led,LOW);
       }
    }
    
 }
}

