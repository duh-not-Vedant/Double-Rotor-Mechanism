//THE UPPER MOTOR IS DEFINED AS MOTOR2 AND LOWER MOTOR IS DEFINED AS MOTOR1____________________________________________________________

#include "variables.h"// ANOTHER FILE WHERE I HAVE STORED THE VARIABLE FOR THIS SKETCH

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(en1,OUTPUT);
  pinMode(en2,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2),count,RISING);//MOTOR1
  attachInterrupt(digitalPinToInterrupt(3),count2,RISING);//MOTOR2

  //MOTOR1
  pinMode(PWM_pin1,OUTPUT);
  //MOTOR2
  pinMode(PWM_pin2,OUTPUT);
  pinMode(PWM_right,OUTPUT);

  //FEEDING MECHANISM
  pinMode(39,OUTPUT); 
  pinMode(35,OUTPUT);
}

void loop() {
  
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  time = millis() - previousmillis;//DETERMINING SAMPLE TIME FOR RPM CALC
  if(time >= RPM_sample){
    RPM1 = RPM_calc(counter1, 600);//MOTOR1
    RPM2 = RPM_calc(counter2, 360);//MOTOR2
    counter1 = 0;
    counter2 = 0;
    previousmillis = millis();//TO RESET previousmillis
  }

  timePID = millis() - previousmillisPID;//DETERMINING SAMPLE TIME FOR PID CALC
  if(timePID >= PID_sample){
    PWM1 = PID(RPM1,/*kp*/0.3,/*kd*/0.04,/*ki*/0.02,1,RPM_set1);
    PWM2 = PID(RPM2,/*kp*/0.30,/*kd*/0.03,/*ki*/0.003,2,RPM_set2);

    analogWrite(PWM_pin2,PWM2); // MOTOR2
    analogWrite(PWM_right,0);

    analogWrite(PWM_pin1,PWM1); // MOTOR1

    // PRINTING STATEMENTS
    Serial.print("RPM1: ");
    Serial.print(RPM1);
    Serial.print("PWM1: ");
    Serial.print(PWM1);
    Serial.print("  ");
    Serial.print("RPM2: ");
    Serial.print(RPM2);
    Serial.print("PWM2: ");
    Serial.print(PWM2);
    Serial.print("  ");
    Serial.print("shoot: ");
    Serial.println(shoot);
    Serial.println("");
    previousmillisPID = millis();//TO RESET previousmillisPID
  }

  //TAKING INPUT FOR SHOOTING OR INC DEC RPM
  if(Serial.available() > 0){
    read = Serial.read();
    Serial.println(read);
  }

  if(millis() - shootmillis > 1500 && shoot == 1){
    digitalWrite(39,LOW);
    digitalWrite(35,HIGH);
    shoot = 0;
    delay(200);
    digitalWrite(39,LOW);
    digitalWrite(35,LOW);
  }


  switch(read){

  //1
    case 49: // 1 ON SERIAL MONITOR
    RPM_set1 = RPM_set1 + 100;
    Serial.print("motor 1 :+100");
    Serial.print("RPM_set1: ");
    Serial.print(RPM_set1);
    Serial.print(" RPM_set2 :");
    Serial.print(RPM_set2);
    break;

  //2
    case 50:// 2 ON SERIAL MONITOR
    RPM_set1 = RPM_set1 - 100;
    Serial.print("motor 1 :-100");
    Serial.print("RPM_set1: ");
    Serial.print(RPM_set1);
    Serial.print(" RPM_set2 :");
    Serial.print(RPM_set2);
    break;

  //3
    case 51:// 3 ON SERIAL MONITOR
    RPM_set2 = RPM_set2 + 100;
    Serial.print("motor 2 :+100");
    Serial.print("RPM_set1: ");
    Serial.print(RPM_set1);
    Serial.print(" RPM_set2 :");
    Serial.print(RPM_set2);
    break;

  //4
    case 52:// 4 ON SERIAL MONITOR
    RPM_set2 = RPM_set2 - 100;
    Serial.print("motor 2 :-100");
    Serial.print("RPM_set1: ");
    Serial.print(RPM_set1);
    Serial.print(" RPM_set2 :");
    Serial.print(RPM_set2);
    break;

  //5
    case 53:// 5 ON SERIAL MONITOR
    shoot = 1;
    shootmillis = millis();

    Serial.print("shooting");
    
    //FORWARD MOVEMENT OF PISTON
    digitalWrite(39,HIGH);
    digitalWrite(35,LOW);

    // delay(300);

    // //BACKWARD MOVEMENT OF PISTON
    // digitalWrite(6,LOW);
    // digitalWrite(5,HIGH);

    // delay(200);

    // //BOTH LOW AS THE TIP BOARD GETS HOT
    // digitalWrite(6,LOW);
    // digitalWrite(5,LOW);
    break;

    default:
    break;

  }
  
  read = 0;//RESETTING READ

}

double RPM_calc(int pulses, int PPR){
  time = millis() - previousmillis;// CALCULATING TIME AGAIN FOR BETTER ACCURACY
  countcopy = pulses;// USING A COUNTCOPY BECAUSE PULSES GETS UPDATED WITH THE INTERRUPT PIN. CANNOT USE IT AS A NORMAL VARIABLE
  pulses = 0;//RESETTING THE COUNTER FOR NEXT SAMPLE TIME
  RPM = (countcopy*60000) / (time * PPR);//FORMULA FOR RPM CALCULATION
  RPM = abs(RPM);/*_______________________________ RPM IS COMING OUT TO BE NEGATIVE FOR UNKNOWN REASON _______________________________*/
  
  return RPM;
}

int PID(double rpm,double KP,double KD,double KI, int motor,int RPM_set){
  error = RPM_set - rpm;// PRESENT ERROR
  
  if(rpm > RPM_set - 200){ // THIS IS TO GET RID OF INTEGRAL WINDUP WHICH CAN CAUSE THE MOTOR TO SPIN UP TO A REALLY HIGH RPM BEFORE COMING DOWN TO THE SETPOINT
      KI = KI;
      KP = 0;

    if(motor ==1){
      errorsum1 = errorsum1 + error;//INTEGRAL ERROR FOR MOTOR1
      
      errorsum1 = constrain(errorsum1,0,3500);// I HAVE CONSTRAINED THE ERROR SUM BECAUSE IT WAS STILL SPINNING UP TO A HIGH RPM AND THEN COMING DOWN TO SETPOINT
    }

    else{
      errorsum2 = errorsum2 + error;//INTEGRAL ERROR FOR MOTOR2
      errorsum2 = constrain(errorsum2,0,3500);// I HAVE CONSTRAINED THE ERROR SUM BECAUSE IT WAS STILL SPINNING UP TO A HIGH RPM AND THEN COMING DOWN TO SETPOINT
    }
  }

  else{
  KI = 0;
  }

  //BELOW I HAVE USED A IF ELSE STATEMENT TO DETERMINE WHICH MOTOR I AM CALCULATING PID FOR BECAUSE I HAVE USED THE SAME FUNCTION TO CALCULATE PID.
  //THIS IS MAINLY DONE BECAUSE I AM CALCULATING ERROR SUM AND ERROR DIFFERENCE IN THIS FUNCTION AS WELL.
  //IF NOT USED THE ERROR SUM BECOMES THE SAME FOR BOTH THE MOTORS.
  if(motor ==1){
    errordiff1 = error - pre_error1;//DIFFERENTIAL ERROR FOR MOTOR1
    pre_error1 = error;//RESETTING pre_error1
    Base_PWM = 160;
    PWM = Base_PWM + (KP*error) + (KI*errorsum1) + (KD*errordiff1);//CALCULATING THE FINAL PWM FOR MOTOR1
  }

  else{
    errordiff2 = error - pre_error2;//DIFFERENTIAL ERROR FOR MOTOR2
    pre_error2 = error;//RESETTING pre_error2
    Base_PWM = 200;
    PWM = Base_PWM + (KP*error) + (KI*errorsum2) + (KD*errordiff2);//CALCULATING THE FINAL PWM FOR MOTOR2
  }
  
  PWM = constrain(PWM,0,254);// CONSTRAINT ON PWM AS YOU CANNOT GIVE MORE PWM THAN 255 ON MEGA OR UNO. 
  //I HAVE USED 254 HERE BECAUSE FOR UNKNOWN REASON MOTOR1 DOES NOT SPIN ON 255./
  return PWM;
}

void count(){
  counter1++;//COUNTING PULSES RECEIVED FROM ENCODER FOR MOTOR1
}

void count2(){
  counter2++;//COUNTING PULSES RECEIVED FROM ENCODER FOR MOTOR2
}