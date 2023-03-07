// alphaAnalytic.cpp
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "constants.h"

float alphaAnalytic(float xx, float yy, float zz){
  float xOffset = 0.0;
  float yOffset = 0.0;
  float zOffset = 0.0;

  xx = xx - xOffset;
  yy = yy - yOffset;
  zz = zz - zOffset;

  float xx2 = xx*xx;
  float yy2 = yy*yy;
  float zz2 = zz*zz;
  float mach2 = mach*mach;
  
  float tt2 = tt*tt;
  float cs2 = cs*cs;
  float vv = mach*cs;
  float rad2 = xx2 + yy2;
  float rad = sqrt(rad2);
  float ss = zz - mach*cs*tt;
  float ss2 = ss*ss;
  float preFactor = ((gg*mp)/cs2)/sqrt(ss2 + rad2*(1.0 - mach2));
  float alpha;

  if(rad2 + zz2 < cs2*tt2){
    alpha = 1.0*preFactor;
  }else if((mach > 1.0) && (rad2 + zz2 >= cs2*tt2) && (ss/rad < -1.0*sqrt(mach2 - 1.0)) && (zz > cs*tt/mach)){
    alpha = 2.0*preFactor;
  }else{
    alpha = 0.0;
  }
  return alpha;
}

float alphaAnalytic(float ss, float RR){
  RR = abs(RR);

  float tt2 = tt*tt;
  float cs2 = cs*cs;
  float ss2 = ss*ss;
  float RR2 = RR*RR;
  float mach2 = mach*mach;
  float vv = mach*cs;
  float zz = ss + mach*cs*tt;
  float zz2 = zz*zz;
  float eps = 0.0001;
  float eps2 = eps*eps;
  float preFactor = ((gg*mp)/cs2)/sqrt(ss2 + RR2*(1.0 - mach2) + eps2);
  float alpha;

  if(RR2 + zz2 < cs2*tt2){
    alpha = 1.0*preFactor;
  }else if((mach > 1.0) && (RR2 + zz2 > cs2*tt2) && (ss/RR < -1.0*sqrt(mach2 - 1.0)) && (zz > cs*tt/mach)){
    alpha = 2.0*preFactor;
  }else{
    alpha = 0.0;
  }

  return alpha;
}

float alphaAnalytic(float rr, float phi, int sphericalPolar){
  float tt2 = tt*tt;
  float cs2 = cs*cs;
  float mach2 = mach*mach;
  float rr2 = rr*rr;
  float sin2 = sin(phi)*sin(phi);
  float cos2 = cos(phi)*cos(phi);
  float vv = mach*cs;
  float preFactor = ((gg*mp)/cs2)/(rr*sqrt(cos(phi)*cos(phi) + *(1.0 - mach2)));
  float alpha;

  if((rr2*sin2 + (rr*cos(phi)+vv*tt)*(rr*cos(phi)+vv*tt)) < cs2*tt2){
    alpha = 1.0*preFactor;
  }else if((mach > 1.0) && ((rr2*sin2 + (rr*cos(phi)+vv*tt)*(rr*cos(phi)+vv*tt)) > cs2*tt2) && (cos(phi)/sin(phi) < -1.0*sqrt(mach2 - 1.0)) && ((cos(phi) + vv*tt) > cs*tt/mach)){
    alpha = 2.0*preFactor;
  }else{
    alpha = 0.0;
  }

  return alpha;
}
