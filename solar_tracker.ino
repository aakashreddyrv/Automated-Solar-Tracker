#include <Servo.h>

int servoXPin = 9;
int servoYPin = 10;
int posX = 90;
int posY = 90;    // variable to store the servo position
int buffX = 20; 
int buffY = 30; 

int LDR1Pin = A0;
int LDR2Pin = A1;
int LDR3Pin = A2;
int LDR4Pin = A3;

int Sensor1val = 0;
int Sensor2val = 0;
int Sensor3val = 0;
int Sensor4val = 0;

Servo servoX;   // create servo object to control a servo
Servo servoY;   // twelve servo objects can be created on most boards

void setup() {
  servoX.attach(servoXPin); // attaches the servo on pin 9 to the servo object
  servoY.attach(servoYPin);
  Serial.begin(9600);
  pinMode(LDR1Pin, INPUT);
  pinMode(LDR2Pin, INPUT);
  pinMode(LDR3Pin, INPUT);
  pinMode(LDR4Pin, INPUT);
  servoX.write(90);
  servoY.write(90);
  delay(15);
}

void loop() {
  Sensor1val = analogRead(LDR1Pin);
  Sensor2val = analogRead(LDR2Pin);
  Sensor3val = analogRead(LDR3Pin);
  Sensor4val = analogRead(LDR4Pin);

  if((posX>0 && posX<180)&&(posY>0 && posY<180))
  {
    if((Sensor1val > Sensor2val + buffX)||(Sensor3val > Sensor4val + buffX)){
      posX = posX + 5;
    }
    else if((Sensor1val  + buffX < Sensor2val)||(Sensor3val  + buffX < Sensor4val)) {
      posX = posX - 5;
    }
  
    if((Sensor1val > Sensor3val + buffY)||(Sensor2val > Sensor4val + buffY)){
      posY = posY - 5;
    }
    else if((Sensor1val  + buffY < Sensor3val)||(Sensor2val  + buffY < Sensor4val)) {
      posY = posY + 5;
    }

    servoX.write(posX);
    servoY.write(posY);

  }
  else{
    if(posX<=0)
      posX = posX + 10;
    else if(posX>=180)
      posX = posX - 10;

    if(posY<=0)
      posY = posY + 10;
    else if(posY>=180)
      posY = posY - 10;
  }

  Serial.print("\n sensor1 = "); Serial.print(Sensor1val); Serial.print(", sensor2 = "); Serial.print(Sensor2val);
  Serial.print(", sensor3 = "); Serial.print(Sensor3val); Serial.print(", sensor4 = "); Serial.print(Sensor4val);
  delay(300);
}