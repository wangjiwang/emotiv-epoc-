int led = 13;
int button;
int flag =0;
unsigned long starttime;
unsigned long stoptime;
unsigned long looptime;
void setup() {
  // put your setup code here, to run oncbbe
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if(Serial.available()>0){
    button = Serial.read();
    starttime = millis();
    Serial.print("the starttime");
    Serial.println(starttime);
    
    delay(1000);
   
    if(Serial.available()>0){
      digitalWrite(led,HIGH);
      button = Serial.read();
      stoptime = millis();
      Serial.print("the stoptime");
      Serial.println(stoptime);
      
     looptime = stoptime - starttime;
     Serial.println(looptime);
   }
   else{
    digitalWrite(led,LOW);
   }
 }
}

