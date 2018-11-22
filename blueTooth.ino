void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  while(Serial.available()){ 
    int c=Serial.read();
    if(c==97) { 
    Serial.println("BT is ready!"); 
    Serial.write("Serial--13--high"); // 返回到手机调试程序上 
    digitalWrite(13, HIGH); 
    } 
    if(c==98) { 
      Serial.write("Serial--13--low"); 
      digitalWrite(13, LOW); 
     } 
   }
  }

