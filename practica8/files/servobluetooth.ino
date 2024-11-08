#include <Servo.h>
#include <SoftwareSerial.h>
SoftwareSerial blue(2,3);
 
 
Servo servo1;
char dato='x';

 
void setup() {
  // put your setup code here, to run once:
  blue.begin(9600);
  Serial.begin(9600);
//  servo1.attach(6);
 
 
  ////////
 
}
void loop() {
    servo1.attach(6);
  // bluetooth
  if(blue.available()>=2){
    dato=blue.read();
    Serial.println(dato);

  // ON  
    if(dato='1'){
      digitalWrite(13,HIGH);
      servo1.write(90);
    }
    if(dato='0'){
      servo1.write(0);
    }
    if(dato='2'){
 
      servo1.write(180);
    }
}
}
