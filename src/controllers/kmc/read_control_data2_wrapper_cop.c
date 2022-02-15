

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

FILE *prob1, *f;
	char b[256];

      int i,j,ii,jj,kk,kpr;
	  double tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref,c_a_tpl1_eob;
      double c_a_tpl2,c_a_tpl_min,t_tran2d,y_0,c1_y0,c2_y0,g2_ramp;
	  static int kl;

	  kpr=0;

	  if(kl==0){

	  if( kpr == 1)printf("---t15_2_initialize \n");

f=fopen("control_data2.dat","r");
	fgets(b,255,f);
	fscanf(f,"%lf",&tcont2);
	fscanf(f,"%lf",&Ip_div);
	fscanf(f,"%lf",&ref_ramp);
	fscanf(f,"%lf ",&Ip_rd);
	fscanf(f,"%lf \n",&trd_ref);
	  if( kpr == 1)printf("  tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref \n");
  	  if( kpr == 1)printf("%g   %g   %g  %g   %g \n ",tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref);

fgets(b,255,f);
fscanf(f,"%lf",&c_a_tpl1_eob);
fscanf(f,"%lf",&c_a_tpl2);
fscanf(f,"%lf",&c_a_tpl_min);
fscanf(f,"%lf",&y_0);
fscanf(f,"%lf \n",&c2_y0);

	  if( kpr == 1)printf("  c_a_tpl1_eob,c_a_tpl2,c_a_tpl_min,y0,c2_y0 \n");
  	  if( kpr == 1)printf("%g   %g   %g  %g %g\n ",c_a_tpl1_eob,c_a_tpl2,c_a_tpl_min,y_0,c2_y0);


fclose(f);

y0[0]=tcont2;
y0[1]=Ip_div;
y0[2]=ref_ramp;
y0[3]=Ip_rd;
y0[4]=trd_ref;
y0[5]=c_a_tpl1_eob;
y0[6]=c_a_tpl2;
y0[7]=c_a_tpl_min;
y0[8]=y_0;
y0[9]=c2_y0;

kl=1;}

}
