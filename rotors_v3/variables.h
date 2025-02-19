volatile unsigned int counter1 = 0;//MOTOR1
volatile unsigned int counter2 = 0;//MOTOR2
double previousmillis = 0;
double previousmillisPID = 0;
double RPM = 0;
double RPM1 = 0;//MOTOR1
double RPM2 = 0;//MOTOR2
double delaymillis = 0;
double shootmillis = 0;
int shoot = 0;

const int PWM_pin2 = 10;//MOTOR2
const int PWM_right = 9;
const int en2 = 32;
const int en1 = 30;

const int PWM_pin1 = 12;//MOTOR1
const int dir1 = 36;

int PWM = 0;
int PWM1 = 0;
int PWM2 = 0;
int read = 0;
int flag = 0;
double error = 0;
double pre_error1 = 0;
double pre_error2 = 0;
double errorsum1 = 0;
double errorsum2 = 0;
double errordiff1 = 0;
double errordiff2 = 0;
double kp = 0;
double kd = 0;
double ki = 0;
int time = 0;
int timePID = 0;
double RPM_sample = 20;
double PID_sample = 25;
int countcopy = 0;

double RPM_set1 = 2500;
double RPM_set2 = 2500;
int Base_PWM = 120;