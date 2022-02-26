#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "integrate1D.h"

int main(){

  const int nRand = 10000;        // number of random integers to draws
  const float lowerLimitX = 0.0;  // lower limit
  const float upperLimitX = 1.0;  // upper integral
  const float lowerLimitY = 0.0;  // lower limit
  const float upperLimitY = 1.0;  // upper integral

  float area = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);

  int nAccept = integrate1D(nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY);

  printf("*********************************\n");
  printf("%f\n", float((nAccept)/float(nRand))*area);

  return 0;
}
