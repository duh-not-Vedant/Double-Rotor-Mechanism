void RPM_calc1(){

  time_RPM1 = millis() - previousmillis_RPM1;
  if(time_RPM1>= RPM_sample1){
  countcopy1 = pulses1;
  pulses1 = 0;
  Motor_upper_RPM = (countcopy1*60000) / (RPM_sample1 * 360);
  
  Motor_upper_RPM = abs(Motor_upper_RPM);/*_______________________________ RPM IS COMING OUT TO BE NEGATIVE FOR UNKNOWN REASON _______________________________*/
  previousmillis_RPM1 = millis(); 
  }
}
void enc1(){
  pulses1++;
}


void RPM_calc2(){

  time_RPM2 = millis() - previousmillis_RPM2;
  if(time_RPM2 >= RPM_sample2){
  countcopy2 = pulses2;
  pulses2 = 0;
  Motor_lower_RPM = (countcopy2*60000) / (RPM_sample2 * 360);
  Motor_lower_RPM = abs(Motor_lower_RPM);/*_______________________________ RPM IS COMING OUT TO BE NEGATIVE FOR UNKNOWN REASON _______________________________*/
  // Serial.print("Pulses for RPM2: ");
  // Serial.print(countcopy2);
  
  
  previousmillis_RPM2 = millis();
  }
}

void enc2(){

  pulses2++;
}