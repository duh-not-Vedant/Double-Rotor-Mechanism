#include "variables.h"
#include "RPM_calc.h"
#include "PID_calc.h"

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  // pinMode(enable1,OUTPUT);
  // pinMode(enable2,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2),enc1,FALLING);//MOTOR1
  
  attachInterrupt(digitalPinToInterrupt(3),enc2,FALLING);//MOTOR2
  

  //MOTOR1
  pinMode(PWM_pin1,OUTPUT);
  pinMode(dir1,OUTPUT);
  //MOTOR2
  pinMode(PWM_pin2,OUTPUT);
  pinMode(PWM_right,OUTPUT);

  //FEEDING MECHANISM
  pinMode(39,OUTPUT); 
  pinMode(35,OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    read = Serial.read();
    Serial.println(read);
  }

  if(millis() - shootmillis > 1500 && shoot == 1){
    digitalWrite(39,LOW);
    digitalWrite(35,HIGH);
    
    if(flag == 1){
      shootmillis2 = millis();
      flag = 0;
    }
    
    if(millis() - shootmillis2 > 200){
    digitalWrite(39,LOW);
    digitalWrite(35,LOW);
    shoot = 0;
    }
  }

  switch(read){
    case 53:// 5 ON SERIAL MONITOR
    shoot = 1;
    flag = 1;
    shootmillis = millis();

    Serial.print("shooting");
    
    //FORWARD MOVEMENT OF PISTON
    digitalWrite(39,HIGH);
    digitalWrite(35,LOW);
    break;

    default:
    break;
  }

  read = 0;
  RPM_calc1();
  
  // Serial.print("RPM in void loop: ");
  // Serial.print(RPM);
  // Serial.print("    ");

  RPM_calc2();

  // Serial.print("RPM2: ");
  // Serial.print(RPM2);
  // Serial.print("    ");

  PID1();
  
  // Serial.print("PWM1: ");
  // Serial.print(PWM1);
  // Serial.print("    ");
  PID2();
  // Serial.print("PWM2: ");
  // Serial.print(PWM2);
  // Serial.println();
  analogWrite(PWM_pin2, PWM2);
  digitalWrite(PWM_right, LOW);

  analogWrite(PWM_pin1,PWM1);
  digitalWrite(dir1,HIGH);

}