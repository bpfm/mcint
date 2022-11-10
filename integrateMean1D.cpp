// integrateMean1D.cpp
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <omp.h>

float integrateMean1D(int nRand, float lowerLimitX, float upperLimitX, float (*func1D)(float)){
  float fRandX,funcTot = 0.0,funcMean;           // random samples
  float length = (upperLimitX - lowerLimitX);

  srand(123456);      // initialise random seed

  #pragma omp parallel for
  for(int i=0; i<nRand; i++){
    fRandX = lowerLimitX + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitX - lowerLimitX)));
    funcTot += func1D(fRandX);
  }

  funcMean = funcTot/float(nRand);

  return funcMean*length;
}