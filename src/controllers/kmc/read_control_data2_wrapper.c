

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include<stdio.h>
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 
#define y_width 1
#define mexPrintf printf
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
void read_control_data2_Outputs_wrapper(real_T *y0)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
int i; static int kl;
double y[17];
FILE*f;char b[256];


	mexPrintf("---control_data2.dat \n");

if(kl==0){

f=fopen("control_data2.dat","r");
fgets(b,255,f);
for(i=0;i<=8;i++) fscanf(f,"%lf",&y[i]);

fscanf(f,"\n");
fgets(b,255,f);
for(i=9;i<=15;i++) fscanf(f,"%lf",&y[i]);
fclose(f);
mexPrintf("+++control_data2.dat \n");

mexPrintf("---tt_kavin.dat \n");

f=fopen("tt_kavin.dat","r");
fgets(b,255,f);

mexPrintf("1 ---tt_kavin.dat \n");

fscanf(f,"%lf",&y[16]);

mexPrintf("2 +++tt_kavin.dat \n");

fclose(f);

for(i=0;i<=15;i++) y0[i]=y[i]; y0[16]=y[16]*1e-3;

mexPrintf("3 +++tt_kavin.dat \n");

kl=1;}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
