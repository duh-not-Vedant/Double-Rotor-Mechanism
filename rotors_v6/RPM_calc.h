void Motor_upper_RPMcalc(){
  if(millis() - Motor_upper_RPM_premillis >= Motor_upper_RPM_sampletime){
    Motor_upper_RPM_PulseCopy = Motor_upper_RPM_Pulses;
    Motor_upper_RPM_Pulses = 0;
    
    Motor_upper_RPM_val = (Motor_upper_RPM_PulseCopy * 60000) / (Motor_upper_RPM_sampletime * 360);
    Motor_upper_RPM_val = abs(Motor_upper_RPM_val);
    Motor_upper_RPM_premillis = millis();
  }
}

void Motor_upper_Encoder(){
  Motor_upper_RPM_Pulses++;
}

void Motor_lower_RPMcalc(){
  if(millis() - Motor_lower_RPM_premillis >= Motor_lower_RPM_sampletime){
    Motor_lower_RPM_PulseCopy = Motor_lower_RPM_Pulses;
    Motor_lower_RPM_Pulses = 0;
    Motor_lower_RPM_val = (Motor_lower_RPM_PulseCopy * 60000) / (Motor_lower_RPM_sampletime * 360);
    Motor_lower_RPM_val = abs(Motor_lower_RPM_val);
    Motor_lower_RPM_premillis = millis();
  }
}

void Motor_lower_Encoder(){
  Motor_lower_RPM_Pulses++;
}
