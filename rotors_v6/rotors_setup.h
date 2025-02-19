#include "pins_arduino.h"
#include "Arduino.h"
void Rotor_setup(){

  Serial.begin(38400);

  pinMode(Motor_lower_EncoderPin, INPUT_PULLUP);
  pinMode(Motor_upper_EncoderPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Motor_lower_EncoderPin), Motor_lower_Encoder, FALLING);
  attachInterrupt(digitalPinToInterrupt(Motor_upper_EncoderPin), Motor_upper_Encoder, FALLING);

  pinMode(Motor_upper_PWMpin, OUTPUT);
  pinMode(Motor_upper_dirpin, OUTPUT);

  pinMode(Motor_lower_PWMpin, OUTPUT);
  pinMode(Motor_lower_dirpin, OUTPUT);

  pinMode(Extract_Piston_pin, OUTPUT);
  pinMode(Retract_Piston_pin, OUTPUT);

}