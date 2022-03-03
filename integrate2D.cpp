// integrate2D.cpp
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include "func2D.h"
#include "integrate2D.h"

int integrate2D(int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY, float lowerLimitZ, float upperLimitZ){
  float fRandX,fRandY,fRandZ;           // random integer
  float vol = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ);
  int nAccept = 0;

  srand(123456);      // initialise random seed

  #pragma omp parallel
  for(int i=0; i<nRand; i++){
    fRandX = lowerLimitX + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(upperLimitX - lowerLimitX)));
    fRandY = lowerLimitY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(upperLimitY - lowerLimitY)));
    fRandZ = lowerLimitZ + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(upperLimitZ - lowerLimitZ)));
    if(fRandZ<=func2D(fRandX,fRandY)){
      nAccept++;
    }
    if(i % (nRand/100) == 0){printf("%i\t%f\t%f\n",i,vol,vol*float(nAccept)/float(i));}
  }
  return nAccept;
}
