void feeder(){
  if(millis() - shootmillis > 1500 && shoot == 1){
    digitalWrite(39,LOW);
    digitalWrite(37,HIGH);
    
    if(flag == 1){
      shootmillis2 = millis();
      flag = 0;
    }
    
    if(millis() - shootmillis2 > 200){
    digitalWrite(39,LOW);
    digitalWrite(37,LOW);
    shoot = 0;
    }
  }
}

void feeding_set(){
  shoot = 1;
  flag = 1;
  shootmillis = millis();
      
  //FORWARD MOVEMENT OF PISTON
  digitalWrite(39,HIGH);
  digitalWrite(37,LOW);
}