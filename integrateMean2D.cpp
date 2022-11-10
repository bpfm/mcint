// integrateMean2D.cpp
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <omp.h>

float integrateMean2D(int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY, float (*func2D)(float, float)){
  float fRandX,fRandY,funcTot = 0.0,funcMean;           // random samples
  float area = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);

  srand(123456);      // initialise random seed

  #pragma omp parallel for
  for(int i=0; i<nRand; i++){
    fRandX = lowerLimitX + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitX - lowerLimitX)));
    fRandY = lowerLimitY + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitY - lowerLimitY)));
    funcTot += func2D(fRandX,fRandY);
  }

  funcMean = funcTot/float(nRand);

  return funcMean*area;
}