#include "variables.h"
#include "RPM_calc.h"
#include "PID_calc.h"
#include "shoot.h"
#include "rotors.h"
#include "rotor_setup.h"
#include "Setpoint_calc.h"

void setup() {
  rotor_setup();
}

void loop() {
  if (Serial.available() > 0) {
    read = Serial.read();
    if (isAlpha(read)) {
      x = read;
    }
    else {
      x = x;
    }
  }
  
  switch (x) {
    case 'R':
      feeding_set();
      x = 'S';
      break;

    case 'S':
      rotors();
      break;

    default:
      rotors();
      // Setpoint_calc();
  }

  if(millis() - printmillis > 85){
  Serial.print("RPM_upper: ");
  Serial.print(Motor_lower_RPM);
  Serial.print("  upper PWM: ");
  Serial.print(Motor_upper_PWM);
  Serial.print("  lower PWM: ");
  Serial.print(Motor_lower_PWM);
  Serial.print("  RPM_lower: ");
  Serial.print(Motor_upper_RPM);
  Serial.println();
  printmillis = millis();
  }
  
  // Setpoint_calc();
}