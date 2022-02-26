// integrate1D.cpp
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include "func1D.h"
#include "integrate1D.h"

int integrate1D(int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY){
  float fRandX,fRandY;           // random integer
  float area = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);
  int nAccept = 0;

  srand(123456);      // initialise random seed

  for(int i=0; i<nRand; i++){
    fRandX = lowerLimitX + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(upperLimitX - lowerLimitX)));
    fRandY = lowerLimitY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(upperLimitY - lowerLimitY)));
    if(fRandY<=func1D(fRandX)){
      nAccept++;
    }
    printf("%i\t%i\n",i ,nAccept);
  }
  return nAccept;
}
