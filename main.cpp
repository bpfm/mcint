#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include "func1D.h"

int main(){

  srand(123456);      // initialise random seed

  const int nRand = 10;          // number of random integers to draws
  const float lowerLimit = 0.0;  // lower limit
  const float upperLimit = 1.0;  // upper integral

  float fRand;                   // random integer

  for(int i=0; i<nRand; i++){
    fRand = lowerLimit + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(upperLimit - lowerLimit)));
    printf("%i\t%f\n",i ,fRand);
  }

  return 0;
}
