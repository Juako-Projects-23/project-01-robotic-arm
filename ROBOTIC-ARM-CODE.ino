#include <Servo.h>
#include <Stepper.h>


Servo miServo; 
Stepper miStepper(2048,8,10,9,11);
Servo miServo2;
Servo miServo3;
Servo miServo4;

int pinJoystickX = A0;
int pinJoystickY = A2;
int pinJoystickX2 = A15;
int pinJoystickY2 = A14;
int angulo = 90; 
int angulo2 = 90;
int angulo3 = 90;
int angulo4 = 90;
int step=0;
int pinBotonAbrir = 12;  
int pinBotonCerrar = 13; 

void setup() {
  Serial.begin(9600);
  
  miServo.attach(6); 
  miServo2.attach(4);
  miServo3.attach(2);
  miServo4.attach(3);
  miStepper.setSpeed(5);
  pinMode(pinBotonAbrir, INPUT_PULLUP);
  pinMode(pinBotonCerrar, INPUT_PULLUP);
}

void loop() {
  int posicionX = analogRead(pinJoystickX);
  int posicionY = analogRead(pinJoystickY);
  int posicionX2 = analogRead(pinJoystickX2);
  int posicionY2 = analogRead(pinJoystickY2);
  Serial.print('EJE X' );
  Serial.println(posicionX);
  Serial.print('EJE Y' );
  Serial.println(posicionY);
  


  
  if (posicionX < 300) {
    angulo = angulo + 1;
    if (angulo > 180) angulo = 180; 
    miServo.write(angulo);
  }

  
  if (posicionX > 800) {
    angulo = angulo - 1;
    if (angulo < 0) angulo = 0; 
    miServo.write(angulo);
  }

 if (posicionX2 < 300) {
    angulo2 = angulo2 + 1;
    if (angulo2 > 180) angulo2 = 180; 
    miServo2.write(angulo2);
  }

  
  if (posicionX2 > 800) {
    angulo2 = angulo2 - 1;
    if (angulo2 < 0) angulo2 = 0; 
    miServo2.write(angulo2);
  }

  if (posicionY2 > 800) {
    angulo3 = angulo3 + 1;
    if (angulo3 > 180) angulo3 = 180; 
    miServo3.write(angulo3);
  }

  
  if (posicionY2 < 300) {
    angulo3 = angulo3 - 1;
    if (angulo3 < 0) angulo3 = 0; 
    miServo3.write(angulo3);
  }

  if (posicionY > 800){

    miStepper.step(20);

  }

  if (posicionY < 300){

    miStepper.step(-20);
    
  }

 
  if (digitalRead(pinBotonAbrir) == LOW) { 
    angulo4 = angulo4 + 2; 
    if (angulo4 > 180) angulo4 = 180; 
    miServo4.write(angulo4);
  }
  
  // Si pulsas el segundo joystick
  if (digitalRead(pinBotonCerrar) == LOW) { 
    angulo4 = angulo4 - 2;
    if (angulo4 < 0) angulo4 = 0; 
    miServo4.write(angulo4);
  }



 

  delay(20); 
}