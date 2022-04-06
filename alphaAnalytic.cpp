// alphaAnalytic.cpp
#include <stdlib.h>
#include <math.h>

float alphaAnalytic(float xx, float yy, float zz){
  float gg = 1.0;
  float mp = 1.0;
  float cs = 1.0;
  float tt = 0.5;
  float tt2 = tt*tt;
  float cs2 = cs*cs;

  float xOffset = 0.0;
  float yOffset = 0.0;
  float zOffset = 0.0;

  xx = xx - xOffset;
  yy = yy - yOffset;
  zz = zz - zOffset;

  float xx2 = xx*xx;
  float yy2 = yy*yy;
  float zz2 = zz*zz;
  float mach = 1.3;
  float mach2 = mach*mach;
  float vv = mach*cs;
  float rad2 = xx2 + yy2;
  float rad = sqrt(rad2);
  float ss = zz - mach*cs*tt;
  float ss2 = ss*ss;
  float preFactor = ((gg*mp)/cs2)/sqrt(ss2 + rad2*(1.0 - mach2));
  float alpha;

  if(rad2 + zz2 < cs2*tt2){
    alpha = 1.0*preFactor;
  }else if((mach > 1.0) && (rad2 + zz2 > cs2*tt2) && (ss/rad < -1.0*sqrt(mach2 - 1.0)) && (zz > cs*tt/mach)){
    alpha = 2.0*preFactor;
  }else{
    alpha = 0.0;
  }
  return alpha;
}
