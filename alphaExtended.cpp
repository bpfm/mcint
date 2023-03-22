// alphaExtended.cpp
#include "alphaAnalytic.h"
#include "perturberExtended.h"

float alphaExtended(float xp, float yp, float zp, float xx, float yy, float zz){

  float alpha = alphaAnalytic(xp - xx, yp - yy, zp - zz) * perturberExtended(xx, yy, zz);

  return alpha;

}

float alphaExtended(float sp, float Rp, float ss, float RR){

  float alpha = alphaAnalytic(sp - ss, Rp - RR) * perturberExtended(ss, RR);

  return alpha;

}

float alphaExtended(float rp, float phip, int sphericalPolar, float rr, float phi){

  float alpha = alphaAnalytic(rp - rr, phip - phi, sphericalPolar) * perturberExtended(rr, phi, sphericalPolar);

  return alpha;

}
