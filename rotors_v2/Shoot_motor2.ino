int time = 0;
double sample_time = 20;
int countcopy = 0;
int Base_PWM = 50;
int ki = 0;

double previousmillis = 0;
//MOTOR1
const int PWM_pin1 = 9;
const int dir1 = 7;
int PWM1 = 0;
double RPM1 = 0;
volatile unsigned int counter1 = 0;

//PID function for motor1
double error1 = 0;
double pre_error1 = 0;
double errorsum1 = 0;
double errordiff1 = 0;
int kp1 = 0.25;
int kd1 = 0.05;
int ki1 = 0.02;

//MOTOR2
const int PWM_pin2 = 10;
const int PWM_right = 11;
int PWM2 = 0;
double RPM2 = 0;
volatile unsigned int counter2 = 0;

//PID function for motor2
double error2 = 0;
double pre_error2 = 0;
double errorsum2 = 0;
double errordiff2 = 0;
int kp2 = 0.1;
int kd2 = 0.02;
int ki2 = 0.1;

//Set point for both the motors
double RPM_set1 = 2900;
double RPM_set2 = 2500;

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2),counter1,RISING);
  attachInterrupt(digitalPinToInterrupt(3),counter2,RISING);  
  pinMode(PWM_pin1,OUTPUT);//MOTOR1
  pinMode(PWM_pin2,OUTPUT);//MOTOR2
  pinMode(PWM_right,OUTPUT);

}

void loop() {
  time = millis() - previousmillis;
  if(time >= sample_time){

    //RPM for MOTOR1
    time = millis() - previousmillis;
    countcopy = counter1;
    counter1 = 0;
    RPM1 = (countcopy*60000) / (time * 600);
    RPM1 = abs(RPM1);

    //PID for MOTOR1
    error1 = RPM_set1 - RPM1;
    errorsum1 = errorsum1 + error1;
    errordiff1 = error1 - pre_error1;

    if(RPM1 >= RPM_set1 - 300){
      ki = ki1;
    }
    else{
      ki = 0;
    }
    PWM1 = Base_PWM + (kp1*error1) + (kd1*errorsum1) - (ki*errordiff1);
    PWM1 = constrain(PWM1, 0, 127);//127 for 24V battery
    pre_error1 = error1;

    analogWrite(PWM_pin1,PWM1);
    digitalWrite(dir1,HIGH);

    //RPM for MOTOR2
    time = millis() - previousmillis;
    countcopy = counter2;
    counter2 = 0;
    RPM2 = (countcopy*60000) / (time * 360);
    RPM2 = abs(RPM2);

    //PID for MOTOR2
    error2 = RPM_set2 - RPM2;
    errorsum2 = errorsum2 + error2;
    errordiff2 = error2 - pre_error2;

    if(RPM2 >= RPM_set2 - 300){
      ki = ki2;
    }
    else{
      ki = 0;
    }
    PWM2 = Base_PWM + (kp2*error2) + (kd2*errorsum2) - (ki*errordiff2);
    PWM2 = constrain(PWM2, 0, 127);//127 for 24V battery
    pre_error2 = error2;
    
    analogWrite(PWM_pin2,PWM2);
    
    previousmillis = millis();

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

void count1(){
  counter1++;
}

void count2(){
  counter2++;
}