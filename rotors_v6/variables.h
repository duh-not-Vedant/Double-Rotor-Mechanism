int Motor_upper_Setpoint = 0;
int Motor_lower_Setpoint = 0;

//Upper Motor
const int Motor_upper_EncoderPin = 2;
double Motor_upper_PID_sampletime = 85;
volatile unsigned long Motor_upper_PID_premillis = 0;
volatile unsigned long Motor_upper_RPM_premillis = 0;
int Motor_upper_PID_before_range_Kp = 0;
int Motor_upper_PID_before_range_Kd = 0;
int Motor_upper_PID_before_range_Ki = 0;
int Motor_upper_PID_after_range_Kp = 0;
int Motor_upper_PID_after_range_Kd = 0;
int Motor_upper_PID_after_range_Ki = 0;
double Motor_upper_RPM_sampletime = 80;
const int Motor_upper_PWMpin = 12;
const int Motor_upper_dirpin = 36;
volatile unsigned long Motor_upper_RPM_Pulses = 0;
int Motor_upper_RPM_PulseCopy = 0;
double Motor_upper_RPM_val = 0;
int Motor_upper_PID_BasePWM = 100;
int Motor_upper_PID_currerror = 0;
int Motor_upper_PID_prerror = 0;
int Motor_upper_PID_errdiff = 0;
int Motor_upper_PID_errsum = 0;
int Motor_upper_PID_PWMval = 0;

//Lower Motor
const int Motor_lower_EncoderPin = 3;
double Motor_lower_PID_sampletime = 85;
volatile unsigned long Motor_lower_PID_premillis = 0;
volatile unsigned long Motor_lower_RPM_premillis = 0;
int Motor_lower_PID_before_range_Kp = 0;
int Motor_lower_PID_before_range_Kd = 0;
int Motor_lower_PID_before_range_Ki = 0;
int Motor_lower_PID_after_range_Kp = 0;
int Motor_lower_PID_after_range_Kd = 0;
int Motor_lower_PID_after_range_Ki = 0;
double Motor_lower_RPM_sampletime = 80;
const int Motor_lower_PWMpin = 10;
const int Motor_lower_dirpin = 32;
volatile unsigned long Motor_lower_RPM_Pulses = 0;
int Motor_lower_RPM_PulseCopy = 0;
double Motor_lower_RPM_val = 0;
int Motor_lower_PID_BasePWM = 100;
int Motor_lower_PID_currerror = 0;
int Motor_lower_PID_prerror = 0;
int Motor_lower_PID_errdiff = 0;
int Motor_lower_PID_errsum = 0;
int Motor_lower_PID_PWMval = 0;

volatile unsigned long Piston_millis_extend = 0;
volatile unsigned long Piston_millis_retract = 0;
int flag_extract = 0;
int flag_retract = 0;
int Extract_Piston_pin = 39;
int Retract_Piston_pin = 37;

char read = 'S';
char x = 'S';