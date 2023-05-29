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
#include "integrateMean2DAlpha.h"
#include "integrateMean2DSPAlpha.h"
#include "integrate3DAlpha.h"
#include "integrateMean3DAlpha.h"

#include "alphaExtended.h"
#include "alphaAnalytic.h"
#include "perturberExtended.h"
#include "constants.h"

int main(int argc, char *argv[]){

  /* setup limits of integration region */
  const int nRand = 1e6;            // number of random integers to draws
  const float lowerLimitX = -1.5;      // lower limit x
  const float upperLimitX = 1.5;    // upper limt x
  const float lowerLimitY = 0.0;      // lower limit y
  const float upperLimitY = 1.5;    // upper limit y
  const float lowerLimitZ = -1.5;      // lower limit z
  const float upperLimitZ = 1.5;    // upper limit z
  const float lowerLimitRho = 0.0;  // lower limit 4th dim
  const float upperLimitRho = 2000.0; // upper limit 4th dim

  /* setup 1D, 2D, and 3D volumes for integration regions */
  float area    = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY);                                                              // 2D volume
  float vol     = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ);                                  // 3D volume       
  float fourVol = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitZ - lowerLimitZ)*(upperLimitRho - lowerLimitRho);  // 4D volume
  float fourVol2D = (upperLimitX - lowerLimitX)*(upperLimitY - lowerLimitY)*(upperLimitRho - lowerLimitRho);                            // 3D volume for alpha(s,R)
  float funcMean;
  int nAccept = 0;                                                                                                                      // number of accepted random samples

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




  // /* setup alpha integration for multiple z-position samples to form profile */
  // int nPoints = 199;                                                           // number of z-samples
  // float xp = 0.0, yp = 0.0, zp, lowerLimitZp = -0.5, upperLimitZp = 1.5;       // x,y position of profile, lower and upper limits of profile sample range
  // FILE * pFile;                                                               // output file
  // pFile = fopen("zAlphaXYZ.txt","w");

  // /* call integration at all z sample position */
  // for(int i=0; i<nPoints; i++){
  //   zp = (upperLimitZp - (lowerLimitZp))*float(i)/float(nPoints) + (lowerLimitZp);
  //   nAccept = integrate3DAlpha(xp,yp,zp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ,lowerLimitRho,upperLimitRho);
  //   funcMean = integrateMean3DAlpha(xp,yp,zp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitZ,upperLimitZ);
  //   printf("%f\t%i\t%f\t%f\t%f\t%f\n", zp, nAccept, fourVol*float(nAccept)/float(nRand),alphaAnalytic(xp,yp,zp),alphaAnalytic(xp,yp,zp)*perturberExtended(xp,yp,zp),funcMean);
  //   fprintf(pFile, "%f\t%f\t%f\t%f\n", zp, fourVol*float(nAccept)/float(nRand),alphaAnalytic(xp,yp,zp),funcMean);
  // }

  // /* setup alpha integration for multiple z-position samples to form profile */
  // int nPoints = 199;                                                       // number of z-samples
  // float sp, Rp = 0.0, lowerLimitZp = -1.3, upperLimitZp = 0.2;            // s,R position of profile, lower and upper limits of profile sample range
  // FILE * pFile;                                                           // output file
  // pFile = fopen("zAlphaSR.txt","w");

  // /* call integration at all z sample position */
  // for(int i=0; i<nPoints; i++){
  //   sp = (upperLimitZp - (lowerLimitZp))*float(i)/float(nPoints) + (lowerLimitZp);
  //   // nAccept = integrate2DAlpha(sp,Rp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,lowerLimitRho,upperLimitRho);
  //   for (int j=0; j<1; j++){
  //     funcMean = integrateMean2DAlpha(sp,Rp,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY);
  //     printf("%f\t%i\t%f\t%f\t%f\n", sp, j, 2.0*3.14159*fourVol2D*float(nAccept)/float(nRand), alphaAnalytic(sp,Rp),2.0*3.14159*funcMean);
  //     fprintf(pFile, "%f\t%f\t%f\t%f\n", sp, 2.0*3.14159*fourVol2D*float(nAccept)/float(nRand), alphaAnalytic(sp,Rp),2.0*3.14159*funcMean);
  //   }
  // }

  /* setup alpha integration for multiple z-position samples to form profile */
  int nPoints = 100;                                                       // number of z-samples
  float sp, Rp = 0.0, lowerLimitZp = -1.2, upperLimitZp = 1.2, fRandX;            // s,R position of profile, lower and upper limits of profile sample range
  FILE *pFile, *testFile;                                                           // output file
  pFile = fopen("zAlphaSR.txt","w");
  testFile = fopen("zAlphaTest.txt","w");

  /* call integration at all z sample position */
  for(int i=0; i<nPoints; i++){
    sp = (upperLimitZp - (lowerLimitZp))*float(i)/float(nPoints) + (lowerLimitZp);
    float rp = sqrt(Rp*Rp + sp*sp);
    float phip = acos(sp/rp);
    for (int j=0; j<1; j++){
      funcMean = 0.0;
      // fprintf(pFile,"%f\t%f\t%f\n",-1.0*sp,alphaAnalytic(sp,3.141529,1),alphaAnalytic(-1.0*sp,Rp));
      funcMean = integrateMean2DSPAlpha(sp,Rp,sp + vv*tt,nRand,lowerLimitX,upperLimitX,lowerLimitY,upperLimitY,testFile);
      printf("%f\t%f\t%f\t%f\n", rp, phip, alphaAnalytic(sp,Rp),2.0*3.141593*funcMean);
      fprintf(pFile, "%f\t%f\t%f\n", sp, alphaAnalytic(sp,Rp),2.0*3.141593*funcMean);
    }
  }

  // float rr, phi;

  // for (int i = 0; i < 100; i++){
  //   rr = (upperLimitX - (lowerLimitX))*float(i)/float(100) + (lowerLimitX);
  //   phi = -3.141593;
  //   alphaAnalytic(1.0-rr, 0.0-phi, 1, testFile);
  // }

  // for (int i = 0; i < 100; i++){
  //   rr = (upperLimitX - (lowerLimitX))*float(i)/float(100) + (lowerLimitX);
  //   phi = 0.0;
  //   alphaAnalytic(1.0-rr, 0.0-phi, 1, testFile);
  // }

  fclose(pFile); 
  fclose(testFile);
 
  return 0;
}
