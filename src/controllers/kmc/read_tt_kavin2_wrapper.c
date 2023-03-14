

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
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

extern FILE*f;
extern FILE*f2;

/*
 * Output functions
 *
 */
void read_tt_kavin2_Outputs_wrapper(real_T *y0)
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
double y[43],ttt;
char b[256];


if(kl==0){
	printf("---tt_kavin2.dat \n");

//f2=fopen("tt_kavin2.dat","r");
fgets(b,255,f2);
fscanf(f2,"%lf ",&y[0]); y[0]=y[0]*1e-3;

fscanf(f2,"\n");
fgets(b,255,f2);
/*for(i=1;i<4;i++) fscanf(f,"%lf %lf %lf",&y[i],&y[i]+1,&y[i]+2);*/
for(i=1;i<=3;i++) fscanf(f2,"%lf",&y[i]);

fscanf(f2,"\n");
fgets(b,255,f2);

fgets(b,255,f2);

for(i=4;i<5;i++) {
sscanf(b,"%lf" "%lf",&y[i],&y[i+1]);
printf("--- i y[i] y[i+1] %d  %g %g ",i,y[i],y[i+1]);
}
printf("--\n ");

y0[0]=y[0];y0[1]=y[2];y0[2]=y[3];y0[3]=y[1];
y0[4]=y[4];y0[5]=y[5];
//fclose(f2);
	printf("---control_data.dat \n");

//f3=fopen("control_data.dat","r");
//fgets(b,255,f3);
fgets(b,255,f);

	printf("-1--control_data.dat \n");

//for(i=0; i<=13; i++) fscanf(f3,"%lf",&y[i]);
for(i=0; i<=13; i++) fscanf(f,"%lf",&y[i]);

printf(" y[0] y[13] %g  %g  \n",y[0],y[13]);

//fscanf(f3,"\n");
fscanf(f,"\n");
//fgets(b,255,f3);
fgets(b,255,f);

//for(i=14; i<=25; i++) fscanf(f3,"%lf",&y[i]);
for(i=14; i<=25; i++) fscanf(f,"%lf",&y[i]);

printf(" y[14] y[25] %g  %g  \n",y[14],y[25]);

//fclose(f3);
fscanf(f,"\n");

for(i=6;i<=31;i++) y0[i]=y[i-6];

printf("---turn.dat \n");

//f=fopen("turn.dat","r");
fgets(b,255,f);
for(i=26; i<=37; i++) fscanf(f,"%lf",&y[i]);
fgets(b,255,f);
//for(i=26; i<=37; i++) sscanf(b,"%lf",&y[i]);

printf(" y[26] y[37] %g  %g  \n",y[26],y[37]);

for(i=32;i<=43;i++) y0[i]=y[i-6];

kl=1;}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}
