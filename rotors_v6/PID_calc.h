Motor_upper_PID_calc(){

  if(millis() - Motor_upper_PID_premillis >= Motor_upper_PID_sampletime){

    Motor_upper_PID_currerror = Motor_upper_Setpoint - Motor_upper_RPM_val;
    Motor_upper_PID_errdiff = Motor_upper_PID_currerror - Motor_upper_PID_prerror;
    Motor_upper_PID_errsum += Motor_upper_PID_currerror;
    Motor_upper_PID_errsum = constrain(Motor_upper_PID_errsum, 0 , 3500);

    if(Motor_upper_RPM_val >= Motor_upper_Setpoint - 200){
      Motor_upper_PID_PWMval = Motor_upper_PID_BasePWM + Motor_upper_PID_before_range_Kp * Motor_upper_PID_currerror + Motor_upper_PID_before_range_Kd * Motor_upper_PID_errdiff + Motor_upper_PID_before_range_Ki * Motor_upper_PID_errsum;
      Motor_upper_PID_PWMval = constrain(Motor_upper_PID_PWMval, 0, 254);
    }
    else{
      Motor_upper_PID_PWMval = Motor_upper_PID_BasePWM + Motor_upper_PID_after_range_Kp * Motor_upper_PID_currerror + Motor_upper_PID_after_range_Kd * Motor_upper_PID_errdiff + Motor_upper_PID_after_range_Ki * Motor_upper_PID_errsum;
    }

    analogWrite(Motor_upper_PWMpin,Motor_upper_PID_PWMval);
  }
}

Motor_lower_PID_calc(){

  if(millis() - Motor_lower_PID_premillis >= Motor_lower_PID_sampletime){

    Motor_lower_PID_currerror = Motor_lower_Setpoint - Motor_lower_RPM_val;
    Motor_lower_PID_errdiff = Motor_lower_PID_currerror - Motor_lower_PID_prerror;
    Motor_lower_PID_errsum += Motor_lower_PID_currerror;
    Motor_lower_PID_errsum = constrain(Motor_lower_PID_errsum, 0 , 3500);

    if(Motor_lower_RPM_val >= Motor_lower_Setpoint - 200){
      Motor_lower_PID_PWMval = Motor_lower_PID_BasePWM + Motor_lower_PID_before_range_Kp * Motor_lower_PID_currerror + Motor_lower_PID_before_range_Kd * Motor_lower_PID_errdiff + Motor_lower_PID_before_range_Ki * Motor_lower_PID_errsum;
      Motor_lower_PID_PWMval = constrain(Motor_upper_PID_PWMval, 0, 254);
    }
    else{
      Motor_lower_PID_PWMval = Motor_lower_PID_BasePWM + Motor_lower_PID_after_range_Kp * Motor_lower_PID_currerror + Motor_lower_PID_after_range_Kd * Motor_lower_PID_errdiff + Motor_lower_PID_after_range_Ki * Motor_lower_PID_errsum;
    }

    analogWrite(Motor_lower_PWMpin,Motor_lower_PID_PWMval);
  }
}