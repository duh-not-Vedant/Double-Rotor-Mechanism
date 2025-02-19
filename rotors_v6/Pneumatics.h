void feeder(){
  if(millis() - Piston_millis_extend >= 1500 && flag_extract == 1){
    digitalWrite(Extract_Piston_pin,LOW);
    digitalWrite(Retract_Piston_pin,HIGH);
    
    if(flag_retract == 1){
      Piston_millis_retract = millis();
      flag_retract = 0;
    }
    
    if(millis() - Piston_millis_retract >= 200){
    digitalWrite(Extract_Piston_pin,LOW);
    digitalWrite(Retract_Piston_pin,LOW);
    flag_extract = 0;
    }
  }
}

void flag_set(){
  flag_extract = 1;
  flag_retract = 1;
  Piston_millis_extend = millis();

  digitalWrite(Extract_Piston_pin, HIGH);
  digitalWrite(Retract_Piston_pin, LOW);
}