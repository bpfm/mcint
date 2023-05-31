#include <stdio.h> 
#include <omp.h>
#include "math.h"

#include "alphaExtended.h"

float integrateMean2DSPAlpha(float sp, float Rp, float zp, long int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY, FILE *testFile){
  float fRandX,fRandY,funcTot,funcMean;          // random samples
  float area = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);

  // convert to spherical polar coordinates

  float rp = sqrt(Rp*Rp + sp*sp);
  float phip = acos(sp/rp);

  // srand(123456);                                // initialise random seed

  // #pragma omp parallel for
  for(int i=0; i<nRand; i++){
    fRandX   = lowerLimitX   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitX   - lowerLimitX)));
    fRandY   = lowerLimitY   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitY   - lowerLimitY)));
    // funcTot += alphaExtended(rp,phip,1,fRandX,fRandY,testFile);
    funcTot += alphaExtended(sp,Rp,1,fRandX,fRandY,testFile);
  }

  funcMean = funcTot/float(nRand);

  return funcMean*area;
}
