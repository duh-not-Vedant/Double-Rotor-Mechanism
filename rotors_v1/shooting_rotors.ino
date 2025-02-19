#include "variables.h"

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),count,RISING);
  attachInterrupt(digitalPinToInterrupt(3),count2,RISING);
  
  // //ENABLES FOR BTS DRIVERS
  // pinMode(EN1,INPUT_PULLUP);
  // pinMode(EN2,INPUT_PULLUP);
  // pinMode(EN3,INPUT_PULLUP);
  // pinMode(EN4,INPUT_PULLUP);

  //MOTOR1
  pinMode(PWM_pin1,OUTPUT);
  //MOTOR2
  pinMode(PWM_pin2,OUTPUT);
  pinMode(PWM_right,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

}

void loop() {
  
  // digitalWrite(EN1,HIGH);
  // digitalWrite(EN2,HIGH);
  // digitalWrite(EN3,HIGH);
  // digitalWrite(EN4,HIGH);
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,LOW);


    Serial.println(shoot);
    if(Serial.available() > 0){ 
    shoot = Serial.read();

      time = millis() - previousmillis;
  if(time >= RPM_sample){
    RPM1 = RPM_calc(counter, 600);
    RPM2 = RPM_calc(counter2, 360);
    counter = 0;
    counter2 = 0;
  }

  if(time >= PID_sample){
  PWM1 = PID(RPM1,/*kp*/0.4,/*kd*/0.05,/*ki*/0.06,1,RPM_set1);
  PWM2 = PID(RPM2,/*kp*/0.45,/*kd*/0.02,/*ki*/0.15,2,RPM_set2);

  analogWrite(PWM_pin2,PWM2); // MOTOR2
  analogWrite(PWM_pin1,PWM1); // MOTOR1
  analogWrite(PWM_right,0);

  Serial.print("RPM1: ");
  Serial.print(RPM1);
  Serial.print("PWM1: ");
  Serial.print(PWM1);
  Serial.print("  ");
  Serial.print("RPM2: ");
  Serial.print(RPM2);
  Serial.print("PWM2: ");
  Serial.print(PWM2);
  Serial.println("  ");
  }
    
    //Serial.print("IN SERIAL.AVAILABLE");
    }
    else{
      shoot = 0;
      //Serial.println("NOT IN SERIAL.AVAILABLE");
    }
   
    // Serial.print(shoot);

  if(shoot != 0){

    Serial.print("shooting");
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);



    delay(200);
    // if(millis() - delaymillis == 100){
    digitalWrite(6,LOW);
    digitalWrite(5,HIGH);



    delay(200);
    // delaymillis = millis();
    // }
    // if(millis() - delaymillis == 100){
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    // shoot = 0;
    // delaymillis = millis();
    }
    
  // }
    
  



  time = millis() - previousmillis;
  if(time >= RPM_sample){
    RPM1 = RPM_calc(counter, 600);
    RPM2 = RPM_calc(counter2, 360);
    counter = 0;
    counter2 = 0;
  }

  if(time >= PID_sample){
  PWM1 = PID(RPM1,/*kp*/0.5,/*kd*/0.05,/*ki*/0.06,1,RPM_set1);
  PWM2 = PID(RPM2,/*kp*/0.55,/*kd*/0.02,/*ki*/0.15,2,RPM_set2);

  analogWrite(PWM_pin2,PWM2); // MOTOR2
  analogWrite(PWM_pin1,PWM1); // MOTOR
  analogWrite(PWM_right,0);

  Serial.print("RPM1: ");
  Serial.print(RPM1);
  Serial.print("PWM1: ");
  Serial.print(PWM1);
  Serial.print("  ");
  Serial.print("RPM2: ");
  Serial.print(RPM2);
  Serial.print("PWM2: ");
  Serial.print(PWM2);
  Serial.println("  ");
  }
}

 


double RPM_calc(int pulses, int PPR){
  time = millis() - previousmillis;
  countcopy = pulses;
  pulses = 0;
  RPM = (countcopy*60000) / (time * PPR);
  RPM = abs(RPM);
 
  return RPM;
 
}

int PID(double rpm,double KP,double KD,double KI, int motor,int RPM_set){
  //calculate error for kp
  error = RPM_set - rpm;
  if(rpm > RPM_set - 300){
    KI = KI;
    if(motor ==1){
      errorsum1 = errorsum1 + error;
      errorsum1 = constrain(errorsum1,0,2500);
    }
    else{
      errorsum2 = errorsum2 + error;
      errorsum2 = constrain(errorsum2,0,1500);
    }
  }
  else{
  KI = 0;
  }
  //calculate errorsum for ki
  if(motor ==1){
    //calculate error diff for kd
    errordiff1 = error - pre_error1;
    pre_error1 = error;
    PWM = Base_PWM + (KP*error) + (KI*errorsum1) - (KD*errordiff1);
    }
  else{
  //calculate error diff for kd
    errordiff2 = error - pre_error2;
    pre_error2 = error;
    PWM = Base_PWM + (KP*error) + (KI*errorsum2) - (KD*errordiff2);
    }
  previousmillis = millis();
  // Serial.print(error);
  // Serial.print("  ");
  // Serial.print(errorsum2);
  // Serial.print("  ");
  // Serial.println(errordiff2);
  PWM = abs(PWM);
  PWM = constrain(PWM,0,254/*255*/);//127 because we are using 24v battery on 12v motors.
  return PWM;
}


void count(){
  counter++;
}

void count2(){
  counter2++;
}