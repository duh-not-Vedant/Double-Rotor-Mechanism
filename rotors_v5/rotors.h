void rotors(){
  feeder();
  RPM_calc1();
  RPM_calc2();
  PID1();
  PID2();
  
  analogWrite(Motor_lower_PWMPin,Motor_lower_PWM);
  digitalWrite(Motor_lower_dir, LOW);

  analogWrite(Motor_upper_PWMPin,Motor_upper_PWM);
  digitalWrite(Motor_upper_dir,HIGH);
}