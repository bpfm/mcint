#include <stdio.h> 
#include <omp.h>
#include "math.h"

#include "alphaExtended.h"

float integrateMean2DSPAlpha(float sp, float Rp, float zp, int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY){
  float fRandX,fRandY,funcTot,funcMean;          // random samples
  float area = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);

  // convert to spherical polar coordinates

  float rp = sqrt(Rp*Rp + sp*sp);
  float phip = acos(sp/rp);

  srand(123456);                                // initialise random seed

  // #pragma omp parallel for
  for(int i=0; i<nRand; i++){
    fRandX   = lowerLimitX   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitX   - lowerLimitX)));
    fRandY   = lowerLimitY   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitY   - lowerLimitY)));
    funcTot += alphaExtended(rp,phip,1,fRandX,fRandY);
    // if(alphaExtended(rp,phip,1,fRandX,fRandY)>100000.0){
    //   printf("%f\t%f\t%f\t%f\t%f\t%f\n",rp,phip,fRandX,fRandY,alphaExtended(rp,phip,1,fRandX,fRandY),funcTot);
    // }
  }

  funcMean = funcTot/float(nRand);

  // printf("%f\n",funcMean);
  // exit(0);

  return funcMean*area;
}