#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include "func1D.h"

int main(){

  srand(123456);      // initialise random seed

  const int nRand = 10;          // number of random integers to draw

  int iRand;                     // random integer

  for(int i=0; i<nRand; i++){
    iRand = rand() % 100;
    printf("%i\t%i\n", iRand,i);
  }

  return 0;
}
