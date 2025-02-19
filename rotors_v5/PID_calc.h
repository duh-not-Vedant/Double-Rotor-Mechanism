void PID1() {

  time_PID1 = millis() - previousmillisPID1;
  if(time_PID1 >= RPM_sample1){

    Motor_lower_error = RPM_set1 - Motor_lower_RPM;
    Motor_lower_errordiff = Motor_lower_error - Motor_lower_preerror;
    if(Motor_lower_RPM >= RPM_set1 - 200){

      ki1 = 0.35;
      kp1 = 0.2;
      kd1 = 0.5;

      // values after reaching ki range
      Motor_lower_errorsum += Motor_lower_error;
      Motor_lower_errorsum = constrain(Motor_lower_errorsum, 0, 3500);
    }

    else{

      //values before ki range
      kp1 = 0.7;
      kd1 = 0;
      ki1 = 0;
      
    }

    Motor_lower_PWM = PWM1_Base + (kp1*Motor_lower_error) + (kd1*Motor_lower_errordiff) + (ki1*Motor_lower_errorsum);
    Motor_lower_PWM = abs(Motor_lower_PWM);
    Motor_lower_PWM = constrain(Motor_lower_PWM, 0, 254);
    Motor_lower_preerror = Motor_lower_error;
    // Serial.print("  PWM1: ");
    // Serial.print(PWM1);
    previousmillisPID1 = millis();
  }
}

void PID2(){

  time_PID2 = millis() - previousmillisPID2; 
  if(time_PID2 >= RPM_sample2){

    Motor_upper_error = RPM_set2 - Motor_upper_RPM;
    Motor_upper_errordiff = Motor_upper_error - Motor_upper_preerror;
    if(Motor_upper_RPM >= RPM_set2 - 200){

      // values after reaching ki range
      ki2 = 0.3;
      kp2 = 0.2;
      kd2 = 0.5;

      Motor_upper_errorsum += Motor_upper_error;
      Motor_upper_errorsum = constrain(Motor_upper_errorsum, 0, 3500);

      
    }
    else{

      //values before ki range
      kp2 = 0.7;
      kd2 = 0;
      ki2 = 0; 
    }

    Motor_upper_PWM = PWM2_Base +(kp2*Motor_upper_error) + (kd2*Motor_upper_errordiff) + (ki2*Motor_upper_errorsum);
    Motor_upper_PWM = abs(Motor_upper_PWM);
    Motor_upper_PWM = constrain(Motor_upper_PWM,0,254);
    Motor_upper_preerror = Motor_upper_error;

    
    previousmillisPID2 = millis();
  }
}