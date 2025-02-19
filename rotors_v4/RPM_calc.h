void RPM_calc1(){

  time_RPM1 = millis() - previousmillis_RPM1;
  if(time_RPM1>= RPM_sample1){
  countcopy1 = pulses1;
  pulses1 = 0;
  RPM1 = (countcopy1*60000) / (RPM_sample1 * 360);
  
  RPM1 = abs(RPM1);/*_______________________________ RPM IS COMING OUT TO BE NEGATIVE FOR UNKNOWN REASON _______________________________*/
  // Serial.print("Pulses for RPM1: ");
  // Serial.print(countcopy1);
  Serial.print("RPM1: ");
  Serial.print(RPM1);
  Serial.print("PWM1 ");
  Serial.print(PWM1);
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
  RPM2 = (countcopy2*60000) / (RPM_sample2 * 360);
  RPM2 = abs(RPM2);/*_______________________________ RPM IS COMING OUT TO BE NEGATIVE FOR UNKNOWN REASON _______________________________*/
  // Serial.print("Pulses for RPM2: ");
  // Serial.print(countcopy2);
  Serial.print("  RPM2: ");
  Serial.println(RPM2);
  
  previousmillis_RPM2 = millis();
  }
}

void enc2(){

  pulses2++;
}