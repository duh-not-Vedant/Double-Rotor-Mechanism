#include<math.h>
double k = 9.81;
float d = 0;//metres
float h = 2.43;//metres
float x = 0;//radians

void Setpoint_calc(){

  RPM = (k * d*d) / (2 * (d * tan(x) - h) * pow(cos(x),2));
  RPM_set1 = RPM;
  RPM_set2 = RPM;

}