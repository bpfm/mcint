// alphaExtended.cpp
#include "alphaAnalytic.h"
#include "perturberExtended.h"

float alphaExtended(float xp, float yp, float zp, float xx, float yy, float zz){

  float alpha = alphaAnalytic(xp - xx, yp - yy, zp - zz) * perturberExtended(xx, yy, zz);

  return alpha;

}
