// testConvolve.cpp
#include "test1.h"
#include "test2.h"

float testConvolve(float xp, float yp, float zp, float xx, float yy, float zz){

  float product = test1(xx, yy, zz) * test2(xx, yy, zz);

  return product;

}
