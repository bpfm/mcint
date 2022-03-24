#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "func1D.h"
#include "func2D.h"
#include "func3D.h"
#include "integrate1D.h"
#include "integrate2D.h"
#include "integrate3D.h"
#include "integrate3DAlpha.h"

#include "alphaExtended.h"

int main(int argc, char *argv[]){

  const int nRand = 1e8;        // number of random integers to draws
  const float lowerLimitX = -1.0;  // lower limit
  const float upperLimitX = 1.0;  // upper limt
  const float lowerLimitY = -1.0;  // lower limit
  const float upperLimitY = 1.0;  // upper limit
  const float lowerLimitZ = -1.0;  // lower limit
  const float upperLimitZ = 1.0;  // upper limit
  const float lowerLimitRho = 0.0;  // lower limit
  const float upperLimitRho = 100.0;  // upper limit

  float area    = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);
  float vol     = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ);
  float fourVol = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ)*(upperLimitRho - lowerLimitRho);
  int nAccept;

  // nAccept = integrate1D(nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,func1D);
  //
  // printf("*********************************\n");
  // printf("%f\n", float((nAccept)/float(nRand))*area);

  // nAccept = integrate2D(nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,func2D);
  //
  // printf("*********************************\n");
  // printf("%f\n", float((nAccept)/float(nRand))*vol);

  // nAccept = integrate3D(nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,lowerLimitRho,upperLimitRho,func3D);
  //
  // printf("*********************************\n");
  // printf("%f\n", float((nAccept)/float(nRand))*fourVol);

  // nAccept = integrate3D(xp,yp,zp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,lowerLimitRho,upperLimitRho,alphaExtended);
  //
  // printf("*********************************\n");
  // printf("%f\n", float((nAccept)/float(nRand))*fourVol);

  float xp = 0.1, yp = 0.0,zp;
  FILE * pFile;
  pFile = fopen("zAlpha.txt","w");

  for(int i; i<50; i++){
    zp = (upperLimitZ - lowerLimitZ)*float(i)/float(50) + lowerLimitZ;
    nAccept = integrate3DAlpha(xp,yp,zp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,lowerLimitRho,upperLimitRho);
    fprintf(pFile, "%f\t%f\n", zp, float((nAccept)/float(nRand))*fourVol);
  }

  return 0;
}
