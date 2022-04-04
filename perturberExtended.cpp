// perturberExtended.cpp
#include <stdlib.h>
#include <math.h>

float perturberExtended(float xx, float yy, float zz){
  float xx2 = xx*xx;
  float yy2 = yy*yy;
  float zz2 = zz*zz;
  
  float pi = 3.14159;
  float cs = 1.0;
  float mach = 1.3;
  float tt = 0.5;
  float mp = 1.0;
  float rs = 0.001;

  float rs2 = rs*rs;
  float rad2 = xx2 + yy2;
  // float rad = sqrt(rad2);

  float rho = 3.0*mp*rs2/(4.0*pi*pow(rad2 + rs2 + (zz - cs*mach*tt)*(zz - cs*mach*tt), 2.5));

  return rho/mp;
}
