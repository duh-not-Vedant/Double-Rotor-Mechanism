void PID1() {

  time_PID1 = millis() - previousmillisPID1;
  if(time_PID1 >= RPM_sample1){

    error1 = RPM_set1 - RPM1;
    errordiff1 = error1 - pre_error1;
    if(RPM1 >= RPM_set1 - 200){

      ki1 = 0.3;
      kp1 = 0.2;
      kd1 = 0.5;

      // values after reaching ki range
      error_sum1 += error1;
      error_sum1 = constrain(error_sum1, 0, 3500);
      
    }

    else{

      //values before ki range
      kp1 = 0.5;
      kd1 = 0;
      ki1 = 0;
      
    }

    PWM1 = PWM1_Base + (kp1*error1) + (kd1*errordiff1) + (ki1*error_sum1);
    PWM1 = abs(PWM1);
    PWM1 = constrain(PWM1, 0, 254);
    pre_error1 = error1;
    // Serial.print("  PWM1: ");
    // Serial.print(PWM1);
    previousmillisPID1 = millis();
  }
}

void PID2(){

  time_PID2 = millis() - previousmillisPID2; 
  if(time_PID2 >= RPM_sample2){

    error2 = RPM_set2 - RPM2;
    errordiff2 = error2 - pre_error2;
    if(RPM2 >= RPM_set2 - 200){

      // values after reaching ki range
      ki2 = 0.03;
      kp2 = 0.02;
      kd2 = 0.02;

      error_sum2 += error2;
      error_sum2 = constrain(error_sum2, 0, 3500);

      
    }
    else{

      //values before ki range
      kp2 = 0.5;
      kd2 = 0;
      ki2 = 0; 
    }

    PWM2 = PWM2_Base +(kp2*error2) + (kd2*errordiff2) + (ki2*error_sum2);
    PWM2 = abs(PWM2);
    PWM2 = constrain(PWM2,0,254);
    pre_error2 = error2;

    
    previousmillisPID2 = millis();
  }
}