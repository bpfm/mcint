#include <stdio.h>      /* printf, scanf, puts, NULL */
#include "math.h"
#include "func1D.h"
#include "func2D.h"
#include "func3D.h"
#include "integrate1D.h"
#include "integrateMean1D.h"
#include "integrate2D.h"
#include "integrateMean2D.h"
#include "integrate3D.h"
#include "integrateMean3D.h"
#include "integrate2DAlpha.h"
#include "integrate3DAlpha.h"
#include "integrateMean3DAlpha.h"

#include "alphaExtended.h"
#include "alphaAnalytic.h"
#include "perturberExtended.h"

int main(int argc, char *argv[]){

  /* setup limits of integration region */
  const int nRand = 2e8;            // number of random integers to draws
  const float lowerLimitX = -1.0;      // lower limit x
  const float upperLimitX = 1.0;    // upper limt x
  const float lowerLimitY = -1.0;      // lower limit y
  const float upperLimitY = 1.0;    // upper limit y
  const float lowerLimitZ = -1.0;      // lower limit z
  const float upperLimitZ = 3.0;    // upper limit z
  const float lowerLimitRho = 0.0;  // lower limit 4th dim
  const float upperLimitRho = 2000.0; // upper limit 4th dim

  /* setup 1D, 2D, and 3D volumes for integration regions */
  float area    = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);                                                              // 2D volume
  float vol     = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ);                                  // 3D volume       
  float fourVol = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ)*(upperLimitRho - lowerLimitRho);  // 4D volume
  float fourVol2D = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitRho - lowerLimitRho);                            // 3D volume for alpha(s,R)
  float funcMean;
  int nAccept;                                                                                                                          // number of accepted random samples


  // /* 1D test integral */
  // nAccept = integrate1D(nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,func1D);
  // printf("*********************************\n");
  // printf("%f\n", float((nAccept)/float(nRand))*area);

  /* 1D Mean test integral */
  // for (int i = 0; i < 5; i++){
  //   nAccept = integrate1D(pow(10,i)*nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,func1D);
  //   funcMean = integrateMean1D(pow(10,i)*nRand,lowerLimitX,upperLimitX,func1D);
  //   printf("%i\t%f\t%f\n",int(pow(10,i)*nRand),abs(funcMean-(1.0/3.0)),abs(float((nAccept)/float(pow(10,i)*nRand))*area-(1.0/3.0)));
  // }

  // /* 2D test integral */
  // nAccept = integrate2D(nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,func2D);
  // printf("*********************************\n");
  // printf("%f\n", float((nAccept)/float(nRand))*vol);

  /* 2D Mean test integral */
  // for (int i = 0; i < 5; i++){
  //   nAccept = integrate2D(pow(10,i)*nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,func2D);
  //   funcMean = integrateMean2D(pow(10,i)*nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,func2D);
  //   printf("%i\t%f\t%f\n",int(pow(10,i)*nRand),abs(funcMean-1.0),abs(float((nAccept)/float(pow(10,i)*nRand))*vol-1.0));
  // }

  // /* 3D test integral */
  // nAccept = integrate3D(nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,lowerLimitRho,upperLimitRho,func3D);
  // printf("*********************************\n");
  // printf("%f\n", float((nAccept)/float(nRand))*fourVol);

  /* 3D Mean test integral */
  // for (int i = 0; i < 5; i++){
  //   nAccept = integrate3D(pow(10,i)*nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,lowerLimitRho,upperLimitRho,func3D);
  //   funcMean = integrateMean3D(pow(10,i)*nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,func3D);
  //   printf("%i\t%f\t%f\n",int(pow(10,i)*nRand),abs(funcMean-4.0),abs(float((nAccept)/float(pow(10,i)*nRand))*fourVol-4.0));
  // }





  /* setup alpha integration for multiple z-position samples to form profile */
  int nPoints = 199;                                                           // number of z-samples
  float xp = 0.0, yp = 0.0, zp, lowerLimitZp = -0.5, upperLimitZp = 1.5;       // x,y position of profile, lower and upper limits of profile sample range
  FILE * pFile;                                                               // output file
  pFile = fopen("zAlpha.txt","w");

  /* call integration at all z sample position */
  for(int i=0; i<nPoints; i++){
    zp = (upperLimitZp - (lowerLimitZp))*float(i)/float(nPoints) + (lowerLimitZp);
    nAccept = integrate3DAlpha(xp,yp,zp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,lowerLimitRho,upperLimitRho);
    funcMean = integrateMean3DAlpha(xp,yp,zp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ);
    printf("%f\t%i\t%f\t%f\t%f\t%f\n", zp, nAccept, fourVol*float(nAccept)/float(nRand),alphaAnalytic(xp,yp,zp),alphaAnalytic(xp,yp,zp)*perturberExtended(xp,yp,zp),funcMean);
    fprintf(pFile, "%f\t%f\t%f\t%f\n", zp, fourVol*float(nAccept)/float(nRand),alphaAnalytic(xp,yp,zp),funcMean);
  }

  // /* setup alpha integration for multiple z-position samples to form profile */
  // int nPoints = 99;                                                       // number of z-samples
  // float sp, Rp = 0.0, lowerLimitZp = -1.0, upperLimitZp = 0.5;            // s,R position of profile, lower and upper limits of profile sample range
  // FILE * pFile;                                                           // output file
  // pFile = fopen("zAlpha.txt","w");

  // /* call integration at all z sample position */
  // for(int i=0; i<nPoints; i++){
  //   sp = (upperLimitZp - (lowerLimitZp))*float(i)/float(nPoints) + (lowerLimitZp);
  //   nAccept = integrate2DAlpha(sp,Rp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitRho,upperLimitRho);
  //   printf("%f\t%i\t%f\t%f\n", sp, nAccept, 2.0*3.14159*fourVol2D*float(nAccept)/float(nRand), alphaAnalytic(sp,Rp));
  //   fprintf(pFile, "%f\t%f\t%f\t%f\n", sp, 2.0*3.14159*fourVol2D*float(nAccept)/float(nRand), alphaAnalytic(sp,Rp),perturberExtended(sp,Rp));
  // }


  fclose(pFile);

  return 0;
}
