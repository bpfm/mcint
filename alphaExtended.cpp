// alphaExtended.cpp
#include "alphaAnalytic.h"
#include "perturberExtended.h"

float alphaExtended(float xp, float yp, float zp, float xx, float yy, float zz){
  float cs = 1.0;
  float tt = 0.5;
  float mach = 1.3;
  
  float alpha = alphaAnalytic(xp - xx, yp - yy, zp - zz + mach*cs*tt) * perturberExtended(xx, yy, zz);

  return alpha;

}
