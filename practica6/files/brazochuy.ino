me #include <Servo.h>

// Creamos seis objetos Servo
Servo servoMotor1; // Servo que se moverá normalmente
Servo servoMotor2; // Servo que se moverá en sentido opuesto
Servo servoMotor3; // Tercer servo
Servo servoMotor4; // Cuarto servo
Servo servoMotor5; // Quinto servo
Servo servoMotor6; // Sexto servo

int valor1;   // Variable que almacena la lectura del primer potenciómetro
int valor2;   // Variable que almacena la lectura del segundo potenciómetro
int valor3;   // Variable que almacena la lectura del tercer potenciómetro
int valor4;   // Variable que almacena la lectura del cuarto potenciómetro
int valor5;   // Variable que almacena la lectura del quinto potenciómetro
int pos1;     // Variable que almacena la posición del primer servo
int pos2;     // Variable que almacena la posición del segundo servo
int pos3;     // Variable que almacena la posición del tercer servo
int pos4;     // Variable que almacena la posición del cuarto servo
int pos5;     // Variable que almacena la posición del quinto servo
int pos6;     // Variable que almacena la posición del sexto servo

void setup()
{
  // Iniciamos los servos en los pines 9, 10, 11, 6, 5 y 4
  servoMotor1.attach(9);  
  servoMotor2.attach(10); 
  servoMotor3.attach(11); // Tercer servo
  servoMotor4.attach(6);  // Cuarto servo
  servoMotor5.attach(5);  // Quinto servo
  servoMotor6.attach(3);  // Sexto servo
}

void loop()
{
  // Leemos el valor del primer potenciómetro
  valor1 = analogRead(A0);
  
  // Leemos el valor del segundo potenciómetro
  valor2 = analogRead(A1);
  
  // Leemos el valor del tercer potenciómetro
  valor3 = analogRead(A2); // Tercer potenciómetro

  // Leemos el valor del cuarto potenciómetro
  valor4 = analogRead(A3); // Cuarto potenciómetro

  // Leemos el valor del quinto potenciómetro
  valor5 = analogRead(A4); // Quinto potenciómetr
  // Convertimos el valor del primer potenciómetro a una posición que entienda el servo
  pos1 = map(valor1, 0, 1023, 0, 180); // Posición normal para el primer servo
  pos2 = 180 - pos1; // Posición opuesta para el segundo servo
  
  // Convertimos el valor del segundo potenciómetro a una posición para el tercer servo
  pos3 = map(valor2, 0, 1023, 0, 180); // Posición normal para el tercer servo

  // Convertimos el valor del tercer potenciómetro a una posición para el cuarto servo
  pos4 = map(valor3, 0, 1023, 0, 180); // Posición normal para el cuarto servo

  // Convertimos el valor del cuarto potenciómetro a una posición para el quinto servo
  pos5 = map(valor4, 0, 1023, 0, 180); // Posición normal para el quinto servo

  // Convertimos el valor del quinto potenciómetro a una posición para el sexto servo
  pos6 = map(valor5, 0, 1023, 0, 180); // Posición normal para el sexto servo

  // Mandamos la posición a los servos
  servoMotor1.write(pos1); // Servo normal
  servoMotor2.write(pos2); // Servo en sentido opuesto
  servoMotor3.write(pos3); // Tercer servo
  servoMotor4.write(pos4); // Cuarto servo

  
  servoMotor5.write(pos5); // Quinto servo
  servoMotor6.write(pos6); // Sexto servo


  // Esperamos un corto periodo de tiempo para evitar actualizaciones demasiado rápidas
  delay(15);
}
