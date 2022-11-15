// integrate1D.cpp
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <omp.h>

int integrate1D(int nRand, float lowerLimitX, float upperLimitX, float lowerLimitY, float upperLimitY, float (*func1D)(float)){
  float fRandX,fRandY;           // random samples
  float area = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);
  int nAccept = 0;

  srand(123456);      // initialise random seed

  //#pragma omp parallel for
  for(int i=0; i<nRand; i++){
    fRandX = lowerLimitX + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitX - lowerLimitX)));
    fRandY = lowerLimitY + static_cast <float> (rand()) / (static_cast <float> (float(RAND_MAX)/(upperLimitY - lowerLimitY)));
    if(fRandY<=func1D(fRandX)){
      nAccept++;
    }
    // if(i % (nRand/100) == 0){printf("%i\t%f\n",i,area*float(nAccept)/float(i));}
  }
  return nAccept;
}
