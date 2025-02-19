int RPM_set1 = 3000;
int RPM_set2 = 2100;

//3000
//2510

double time_PID1 = 80;
double RPM_sample1 = 85;



double time_PID2 = 80;
double RPM_sample2 = 85;


const int PWM_pin1 = 12;
const int dir1 = 36;
int PWM1_Base = 163;
volatile unsigned long pulses1 = 0;
double RPM1 = 0;
int PWM1 = 0;
int PPR1 = 360;
int countcopy1 = 0;
double error1 = 0;
double pre_error1 = 0;
double errordiff1 = 0;
double error_sum1 = 0;
double kp1 = 0, kd1 = 0, ki1 = 0;
double time_RPM1 = 0;
double previousmillisPID1 = 0;
double previousmillis_RPM1 = 0;


const int PWM_pin2 = 10;
int PWM2_Base = 70;
const int PWM_right = 32;
volatile unsigned long pulses2 = 0;
double RPM2 = 0;
int PWM2 = 0;
int PPR2 = 360;
int countcopy2 = 0;
double error2 = 0;
double pre_error2 = 0;
double errordiff2 = 0;
double error_sum2 = 0;
double kp2 = 0, kd2 = 0, ki2 = 0;
double time_RPM2 = 0;
double previousmillisPID2 = 0;
double previousmillis_RPM2 = 0;


int read = 0;
double shootmillis = 0;
int shoot = 0;
double shootmillis2 = 0;
int flag = 0;