#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "func1D.h"
#include "func2D.h"
#include "func3D.h"
#include "integrate1D.h"
#include "integrate2D.h"
#include "integrate3D.h"
#include "integrate3DAlpha.h"

#include "alphaExtended.h"
#include "alphaAnalytic.h"
#include "perturberExtended.h"

int main(int argc, char *argv[]){

  const int nRand = 5e7;        // number of random integers to draws
  const float lowerLimitX = -1.0;  // lower limit
  const float upperLimitX = 1.0;  // upper limt
  const float lowerLimitY = -1.0;  // lower limit
  const float upperLimitY = 1.0;  // upper limit
  const float lowerLimitZ = -1.0;  // lower limit
  const float upperLimitZ = 3.0;  // upper limit
  const float lowerLimitRho = 0.0;  // lower limit
  const float upperLimitRho = 1000.0;  // upper limit

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

  int nPoints = 99;
  float xp = 0.0, yp = 0.0,zp;
  FILE * pFile;
  pFile = fopen("zAlpha.txt","w");

  for(int i=0; i<nPoints; i++){
    // zp = (upperLimitZ - lowerLimitZ)*float(i)/float(nPoints) + lowerLimitZ;
    zp = (1.5 - (-0.5))*float(i)/float(nPoints) + (-0.5);
    printf("%f\t%f\t%f\n",xp,yp,zp);
    nAccept = integrate3DAlpha(xp,yp,zp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,lowerLimitRho,upperLimitRho);
    printf("%f\t%i\t%f\t%f\n", zp, nRand, float((nAccept)/float(nRand))*fourVol, alphaAnalytic(xp,yp,zp));
    printf("%f\t%f\t%f\n",xp,yp,zp);
    fprintf(pFile, "%f\t%f\t%f\t%f\n", zp, float((nAccept)/float(nRand))*fourVol, alphaAnalytic(xp,yp,zp),perturberExtended(xp,yp,zp));
  }

  return 0;
}
