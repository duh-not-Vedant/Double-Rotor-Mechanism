void rotor_setup(){

  Serial.begin(38400);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), enc1, FALLING);  //MOTOR1
  attachInterrupt(digitalPinToInterrupt(3), enc2, FALLING);  //MOTOR2

  //MOTOR1
  pinMode(Motor_lower_PWMPin, OUTPUT);
  pinMode(Motor_lower_dir, OUTPUT);
  //MOTOR2
  pinMode(Motor_upper_PWMPin, OUTPUT);
  pinMode(Motor_upper_dir, OUTPUT);

  //FEEDING MECHANISM
  pinMode(39, OUTPUT);
  pinMode(37, OUTPUT);
  
}