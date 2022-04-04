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

  /* setup limits of integration region */
  const int nRand = 2e7;        // number of random integers to draws
  const float lowerLimitX = -1.0;  // lower limit x
  const float upperLimitX = 1.0;  // upper limt x
  const float lowerLimitY = -1.0;  // lower limit y
  const float upperLimitY = 1.0;  // upper limit y
  const float lowerLimitZ = -1.0;  // lower limit z
  const float upperLimitZ = 3.0;  // upper limit z
  const float lowerLimitRho = 0.0;  // lower limit 4th dim
  const float upperLimitRho = 100.0;  // upper limit 4th dim

  /* setup 1D, 2D, and 3D volumes for integration regions */
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

  /* setup alpha integration for multiple z-position samples to form profile */
  int nPoints = 200;                                                       // number of z-samples
  float xp = 0.0, yp = 0.0, zp, lowerLimitZp = -0.5, upperLimitZp = 1.5;   // x,y position of profile, lower and upper limits of profile sample range
  FILE * pFile;                                                            // output file
  pFile = fopen("zAlpha.txt","w");

  /* call integration at all z sample position */
  for(int i=0; i<nPoints; i++){
    zp = (upperLimitZp - (lowerLimitZp))*float(i)/float(nPoints) + (lowerLimitZp); // iterate sample position
    nAccept = integrate3DAlpha(xp,yp,zp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,lowerLimitRho,upperLimitRho);
    printf("%f\t%i\t%f\t%f\n", zp, nAccept, fourVol*float(nAccept)/float(nRand), alphaAnalytic(xp,yp,zp));
    fprintf(pFile, "%f\t%f\t%f\t%f\n", zp, fourVol*float(nAccept)/float(nRand), alphaAnalytic(xp,yp,zp),perturberExtended(xp,yp,zp));
  }

  return 0;
}
