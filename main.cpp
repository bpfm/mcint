#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include "func1D.h"

int main(){

  srand(123456);      // initialise random seed

  const int nRand = 10000;          // number of random integers to draws
  const float lowerLimitX = 0.0;  // lower limit
  const float upperLimitX = 1.0;  // upper integral
  const float lowerLimitY = 0.0;  // lower limit
  const float upperLimitY = 1.0;  // upper integral

  float fRandX,fRandY;           // random integer
  float area = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);
  int nAccept = 0;

  for(int i=0; i<nRand; i++){
    fRandX = lowerLimitX + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(upperLimitX - lowerLimitX)));
    fRandY = lowerLimitY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(upperLimitY - lowerLimitY)));
    if(fRandY<=func1D(fRandX)){
      nAccept++;
    }
    printf("%i\t%i\n",i ,nAccept);
  }

  printf("*********************************\n");
  printf("%f\n", float((nAccept)/float(nRand))*area);

  return 0;
}
