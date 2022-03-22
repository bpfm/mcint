// alphaExtended.cpp
#include "alphaAnalytic.h"
#include "perturberExtended.h"

float alphaExtended(float xx, float yy, float zz){
  float xp = 0.1;
  float yp = 0.0;
  float zp = -0.1;

  alpha = alphaAnalytic(xp - xx, yp - yy, zp - zz)*perturberExtended(xx, yy, zz);

  return alpha;

}
