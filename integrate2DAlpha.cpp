// integrate2DAlpha.cpp
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <omp.h>

#include "alphaExtended.h"

int integrate2DAlpha(float sp, float Rp, int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY, float lowerLimitRho, float upperLimitRho){
  float fRandX,fRandY,fRandRho;          // random samples
  float Vol = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitRho - lowerLimitRho); // 4D volume
  int nAccept = 0;                              // number of accepted random samples

  srand(123456);                                // initialise random seed

  #pragma omp parallel for
  for(int i=0; i<nRand; i++){
    fRandX   = lowerLimitX   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitX   - lowerLimitX)));
    fRandY   = lowerLimitY   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitY   - lowerLimitY)));
    fRandRho   = lowerLimitRho   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitRho   - lowerLimitRho)));
    
    if(fRandRho <= alphaExtended(sp,Rp,fRandX,fRandY)){
      nAccept++;
    }
    // if(i % (nRand/10) == 0){printf("%i\t%f\n",nAccept,Vol*float(nAccept)/float(i));}
  }
  return nAccept;
}