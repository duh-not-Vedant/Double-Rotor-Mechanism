double d = 0;//distance

void Setpoint_calc(){

  // RPM_set1 = 432.5 - 60 * d * d - 570 * d;
  // RPM_set2 = -20 * d * d + 467.58 * d + 60;

  Motor_lower_Setpoint = 307.5 * d + 366.67;
  Motor_upper_Setpoint = -90 * d + 3121.5;

  // RPM_set1 = 13.696 * d * d + 204.67 * d + 551.96;
  // RPM_set2 = 21.25 * d * d * d - 195 * d * d + 428.75 * d + 2857.5; 
}