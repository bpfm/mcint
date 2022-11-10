// integrate3DAlpha.cpp
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <omp.h>

#include "alphaAnalytic.h"
#include "perturberExtended.h"
#include "alphaExtended.h"

int integrate3DAlpha(float xp, float yp, float zp, int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY, float lowerLimitZ, float upperLimitZ, float lowerLimitRho, float upperLimitRho){
  float fRandX,fRandY,fRandZ,fRandRho;          // random samples
  float fourVol = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ)*(upperLimitRho - lowerLimitRho); // 4D volume
  int nAccept = 0;                              // number of accepted random samples

  srand(123456);                                // initialise random seed

  #pragma omp parallel for
  for(int i=0; i<nRand; i++){
    fRandX   = lowerLimitX   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitX   - lowerLimitX)));
    fRandY   = lowerLimitY   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitY   - lowerLimitY)));
    fRandZ   = lowerLimitZ   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitZ   - lowerLimitZ)));
    fRandRho = lowerLimitRho + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitRho - lowerLimitRho)));

    // printf("%f\t%f\t%f\t%f\t%f\t%f\t%f\n",fRandX,fRandY,fRandZ,fRandRho,alphaExtended(xp,yp,zp,fRandX,fRandY,fRandZ),alphaAnalytic(0.0-fRandX,0.0-fRandY,zp-fRandZ),perturberExtended(fRandX,fRandY,fRandZ));
    // exit(0);

    if(fRandRho <= alphaExtended(xp,yp,zp,fRandX,fRandY,fRandZ)){
      nAccept++;
    }
    // if(i % (nRand/10) == 0){printf("%f\t%i\t%f\n",zp,nAccept,fourVol*float(nAccept)/float(i));}
  }
  return nAccept;
}
