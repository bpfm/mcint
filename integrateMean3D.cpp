// integrateMean3D.cpp
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <omp.h>

float integrateMean3D(int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY, float lowerLimitZ, float upperLimitZ, float (*func3D)(float, float, float)){
  float fRandX,fRandY,fRandZ,funcTot = 0.0,funcMean;           // random samples
  float volume = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ);

  srand(123456);      // initialise random seed

  #pragma omp parallel for
  for(int i=0; i<nRand; i++){
    fRandX = lowerLimitX + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitX - lowerLimitX)));
    fRandY = lowerLimitY + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitY - lowerLimitY)));
    fRandZ = lowerLimitZ + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitZ - lowerLimitZ)));
    funcTot += func3D(fRandX,fRandY,fRandZ);
  }

  funcMean = funcTot/float(nRand);

  return funcMean*volume;
}