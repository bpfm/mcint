// integrate3D.cpp
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <omp.h>

int integrate3D(int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY, float lowerLimitZ, float upperLimitZ, float lowerLimitRho, float upperLimitRho, float (*func3D)(float,float,float)){
  float fRandX,fRandY,fRandZ,fRandRho;          // random samples
  float fourVol = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ)*(upperLimitRho - lowerLimitRho);
  int nAccept = 0;

  srand(123456);      // initialise random seed

  #pragma omp parallel for
  for(int i=0; i<nRand; i++){
    fRandX   = lowerLimitX   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitX   - lowerLimitX)));
    fRandY   = lowerLimitY   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitY   - lowerLimitY)));
    fRandZ   = lowerLimitZ   + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitZ   - lowerLimitZ)));
    fRandRho = lowerLimitRho + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitRho - lowerLimitRho)));
    if(fRandRho <= func3D(fRandX,fRandY,fRandZ)){
      nAccept++;
    }
    // if(i % (nRand/100) == 0){printf("%i\t%f\t%f\n",i,fourVol,fourVol*float(nAccept)/float(i));}
  }
  return nAccept;
}
