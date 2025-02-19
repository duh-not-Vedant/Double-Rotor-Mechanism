void rotors(){

  feeder();
  Motor_upper_RPMcalc();
  Motor_lower_RPMcalc();
  Motor_upper_PID_calc();
  Motor_lower_PID_calc();
  debug();
}