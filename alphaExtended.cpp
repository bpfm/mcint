// alphaExtended.cpp
#include <stdio.h>
#include <stdlib.h>
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

  // printf("***\t%f\t%f\t%f\t%f\n",rp,phip,rr,phi);

  float alpha = alphaAnalytic(rp - rr, phip - phi, sphericalPolar) * perturberExtended(rr, phi, sphericalPolar);

  // if(alpha>0.0001){
  //   printf("***\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",rp,phip,rr,phi,alpha,alphaAnalytic(rp - rr, phip - phi, sphericalPolar),perturberExtended(rr, phi, sphericalPolar));
  //   exit(0);
  // }

  return alpha;

}
