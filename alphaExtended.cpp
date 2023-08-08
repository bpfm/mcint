// alphaExtended.cpp
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

float alphaExtended(float sp, float Rp, int sphericalPolar, float ss, float RR){

  float rr = sqrt(RR*RR + ss*ss);
  float phi = acos(ss/rr);

  float sShift = sp - ss;
  float RShift = Rp - RR;

  float rShift = sqrt(RShift*RShift + sShift*sShift);
  float phiShift = acos(sShift/rShift);

  float alpha = rr*rr*sin(phi) * alphaAnalytic(rShift, phiShift, sphericalPolar) * perturberExtended(rr, phi, sphericalPolar);

  return alpha;

}
