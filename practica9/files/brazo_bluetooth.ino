#include <SoftwareSerial.h>
SoftwareSerial blue(2, 3);  // Configura los pines 2 y 3 para comunicación Bluetooth

#include <Servo.h>

Servo servo1;  // Objeto Servo para el primer servomotor
Servo servo2;  // Objeto Servo para el segundo servomotor
Servo servo3;  // Objeto Servo para el tercer servomotor
Servo servo4;  // Objeto Servo para el cuarto servomotor

int servoPin1 = 9;   // Pin del primer servomotor
int servoPin2 = 10;  // Pin del segundo servomotor
int servoPin3 = 11;  // Pin del tercer servomotor
int servoPin4 = 12;  // Pin del cuarto servomotor

void setup() {
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  
  Serial.begin(9600);   // Comunicación serial para depuración
  blue.begin(9600);     // Comunicación Bluetooth a 9600 bps
}

void loop() {
  if (blue.available() >= 4) {          // Verifica si hay al menos 4 caracteres en el buffer Bluetooth
    char servoId = blue.read();         // Lee el primer carácter (ID del servomotor)
    int angle = blue.parseInt();        // Lee el siguiente número (ángulo)

    if (angle >= 0 && angle <= 180) {   // Asegura que el ángulo esté entre 0 y 180
      switch (servoId) {
        case '1': 
          servo1.write(angle); 
          break;
        case '2': 
          servo2.write(angle); 
          break;
        case '3': 
          servo3.write(angle); 
          break;
        case '4': 
          servo4.write(angle); 
          break;
      }
      Serial.print("Servo ");  // Mensaje de depuración en el monitor serial
      Serial.print(servoId);
      Serial.print(" movido a ");
      Serial.println(angle);
    }
  }
}
