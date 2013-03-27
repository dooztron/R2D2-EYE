
#include <Servo.h>      // include the servo library

Servo servoMotor1;
Servo servoMotor2;

char servoPin1 = 3;
char servoPin2 = 4;

int pos1 = 10;
int pos2 = 10;

long nextTime = 1500;

boolean servoHigh = false;

void setup(){
  Serial.begin(57600);

  Serial.write(servoPin1);
  servoMotor1.attach(servoPin1);
  servoMotor1.write(pos1);
  
  Serial.write(servoPin2);
  servoMotor2.attach(servoPin2);
  servoMotor2.write(pos2);
}

void loop(){

  if (millis() > nextTime){   
    if(!servoHigh){
      pos1 = random(40,90);
      pos2 = random(40,90);
      servoMotor1.write(pos1);
      servoMotor2.write(pos2);
      servoHigh = true;
    }
    else{
      pos1 = random(90,140);
      pos2 = random(90,140);
      servoMotor1.write(pos1);
      servoMotor2.write(pos2);
      servoHigh = false;
    }
    nextTime = millis() +1000;
  }
  Serial.println(pos1, pos2);
}


