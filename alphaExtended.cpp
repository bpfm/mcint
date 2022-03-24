// alphaExtended.cpp
#include "alphaAnalytic.h"
#include "perturberExtended.h"

#define position
#ifdef position
  float xp = 0.1;
  float yp = 0.0;
  float zp = -0.01;
#endif

float alphaExtended(float xx, float yy, float zz){

  float alpha = alphaAnalytic(xp - xx, yp - yy, zp - zz)*perturberExtended(xx, yy, zz);

  return alpha;

}
