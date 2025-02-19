int RPM_set1 = 1780;
int RPM_set2 = 3000;

//distance


//3000    RPM_set1 = 307.5 * d + 366.67;
  //RPM_set2 = -90 * d + 3121.5;
//2520

double time_PID1 = 80;
double RPM_sample1 = 85;


double time_PID2 = 80;
double RPM_sample2 = 85;


const int Motor_upper_PWMPin = 12;
const int Motor_upper_dir = 36;
int PWM1_Base = 63;
volatile unsigned long pulses1 = 0;
double Motor_upper_RPM = 0;
int Motor_upper_PWM = 0;
int countcopy1 = 0;
double Motor_upper_error = 0;
double Motor_upper_preerror = 0;
double Motor_upper_errordiff = 0;
double Motor_upper_errorsum = 0;
double kp1 = 0, kd1 = 0, ki1 = 0;
double time_RPM1 = 0;
double previousmillisPID1 = 0;
double previousmillis_RPM1 = 0;
double printmillis = 0;

const int Motor_lower_PWMPin = 10;
int PWM2_Base = 70;
const int Motor_lower_dir = 32;
volatile unsigned long pulses2 = 0;
double Motor_lower_RPM = 0;
int Motor_lower_PWM = 0;
int Motor_lower_PPR = 360;
int countcopy2 = 0;
double Motor_lower_error = 0;
double Motor_lower_preerror = 0;
double Motor_lower_errordiff = 0;
double Motor_lower_errorsum = 0;
double kp2 = 0, kd2 = 0, ki2 = 0;
double time_RPM2 = 0;
double previousmillisPID2 = 0;
double previousmillis_RPM2 = 0;


char read = 'S';
char x = 'S';
double shootmillis = 0;
int shoot = 0;
double shootmillis2 = 0;
int flag = 0;