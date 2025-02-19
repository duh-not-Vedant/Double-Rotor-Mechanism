void debug(){
  Serial.print("RPM_upper: ");
  Serial.print(Motor_upper_RPM_val);
  Serial.print("  upper PWM: ");
  Serial.print(Motor_upper_PID_PWMval);
  Serial.print("  RPM_lower: ");
  Serial.print(Motor_upper_RPM_val);
  Serial.print("  lower PWM: ");
  Serial.print(Motor_lower_PID_PWMval);

  Serial.println();
}
