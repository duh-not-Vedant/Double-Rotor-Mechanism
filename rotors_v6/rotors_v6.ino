#include "variables.h"
#include "RPM_calc.h"
#include "PID_calc.h"
#include "Pneumatics.h"
#include "Setpoint_calc.h"
#include "Printing.h"
#include "rotors_setup.h"
#include "rotors.h"

void setup() {

  Rotor_setup();
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
      flag_set();
      x = 'S';
      break;

    case 'S':
      rotors();
      break;      
  }
}
