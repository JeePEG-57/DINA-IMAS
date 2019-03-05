/*		modified chopper model code 

#define DEBUG
*/
#include <math.h>
#include <float.h>
#include <stdio.h>

x_voltage(y,u)
/*************************************************************************
PURPOSE:  c code implementation of the X_voltage.m function.  Implemented
to be compatible with codegen, so that correct code will be generated.
This code is just C version of matlab implementation 

INPUT:
  u[0] = nominal coil current (IL)
  u[1] = power supply nominal voltage (Vps)
  u[2] = chopper command signal (Vc)
  u[3] = number of choppers on coil (N)

OUTPUT:
   y = voltage out of X chopper

RESTRICTIONS:

METHOD:  

WRITTEN BY:  Mike Walker        ON      5/6/94

		     COPYRIGHT 1994 GENERAL ATOMICS 	
			RESTRICTED RIGHTS NOTICE
UNPUBLISHED-RIGHTS RESERVED UNDER THE COPYRIGHT LAWS OF THE UNITED STATES.

(a) This computer software is submitted with restricted rights under
    Government Contract No. DE-AC03-89ER51114.  It may not be used,
    reproduced, or disclosed by the Government except as provided in
    paragraph (b) of this Notice or as otherwise expressly stated in the
    contract.
(b) This MIMO computer software shall be used exclusively in the
    DIII-D Program and may be --
   (1) Used or copied for use in or with the computer or computers for
       which it was acquired, including use at any Government installation to 
       which the DIII-D fusion reactor may be transferred;
   (2) Used or copied for use in a backup computer if any computer for
       which it was acquired is inoperative;
   (3) Reproduced for safekeeping (archives) or backup purposes;
   (4) Modified, adapted, or combined with other computer software,
       provided that the modified, combined, or adapted portions of the
       derivative software are made subject to the same restricted rights;
   (5) Disclosed to and reproduced for use by support service Contractors
       in accordance with subparagraphs (b)(1) through (4) of this clause,
       provided the Government makes such disclosure or reproduction
       subject to these restricted rights; and
   (6) Used or copied for use in or transferred to a replacement computer.
(c) Notwithstanding the foregoing, if this computer software is published
    copyrighted computer software, it is licensed to the Government without
    disclosure prohibitions, with the minimum rights set forth in paragraph
    (b) of this clause.
(d) Any other rights or limitations regarding the use, duplication, or
    disclosure of this computer software are to be expressly stated in, or
    incorporated in, the contract.
(e) This Notice shall be marked on any reproduction of this computer
    software, in whole, or in part.
****************************************************************************/

double *y,*u;
{

static double k2=.9;
static double C=120e-6;

static double D0 = 0.69396209197924;
static double D1 = 0.02012305951575;
static double D2 = -0.00275471081131;
static double D3 =  0.00031359950146;
static double D4 = 0.00001433852974;
static double D5 = -0.00000223786343;

static double   f0 = 2943.95306812786;
static double   f2 = -76.97472599419;
static double   f4 = 2.96925799392;
static double   f6 = -0.07791403591;
static double   f8 = 0.00089792387;
static double   f10 = -0.00000361243;

static double second = 2.0;
static double third = 3.0;
static double fourth = 4.0;
static double fifth = 5.0;
static double sixth = 6.0;
static double eighth = 8.0;
static double tenth = 10.0;

double D, model_f, V01, V02, V02avg;
double Dtemp, Dtemp2, I;

model_f = f0 + f2*pow(u[2],second)
        + f4*pow(u[2],fourth) +  f6*pow(u[2],sixth)
        + f8*pow(u[2],eighth) +  f10*pow(u[2],tenth);


/* Make sure to put in decimal points when converting from m-file to C */
V01 = 0.9584*u[1]*(1.+.146*(1-u[1]/600)*(u[0]+1500)/((u[0]+300)));

D=D0+D1*u[2]+ D2*pow(u[2],second) +D3*pow(u[2],third) +D4*pow(u[2],fourth)
	+ D5*pow(u[2],fifth);

#ifdef DEBUG

printf(" N = %f\n",u[3]);
printf(" model_f = %f\n",model_f);
printf(" V01 = %f\n",V01);

printf(" D = %f\n",D);

printf(" Dtemp = %f\n",Dtemp);
printf(" Dtemp2 = %f\n",Dtemp2);
printf(" D = %f\n",D);

#endif

V02 = -94.5*pow(u[0]/u[3],(double).25);

#ifdef DEBUG
printf(" V02 = %f\n",V02);
#endif

/* avoid zero currents blowing this up */
if (u[0]>0)
   I = u[0];
else
   I=1;

#ifdef DEBUG
printf(" I = %f\n",I);
#endif

V02avg = V02*(1+(k2*0.5*C*u[3]*V02*model_f)/((1-D)*I));
#ifdef DEBUG
printf(" V02avg = %f\n",V02avg);
#endif
if (V02avg > 0) V02avg=0;				/* KLUGE */

*y = V01*D + V02avg*(1-D);
#ifdef DEBUG
printf(" y = %f\n",*y);
#endif

return;

}



hx_voltage(y,u)
/*************************************************************************
PURPOSE: C code implementation of the HX_voltage.m function.  Implemented
to be compatible with codegen, so that correct code will be generated.


INPUT:
  u[0] = nominal coil current (IL)
  u[1] = power supply nominal voltage (Vps)
  u[2] = chopper command signal (Vc)
  u[3] = number of choppers on coil (N)
 
OUTPUT:
   y = voltage out of HX chopper
 
RESTRICTIONS:
 
METHOD:  
 
WRITTEN BY:  Mike Walker 	ON 	5/6/94
 
		     COPYRIGHT 1994 GENERAL ATOMICS 	
			RESTRICTED RIGHTS NOTICE
UNPUBLISHED-RIGHTS RESERVED UNDER THE COPYRIGHT LAWS OF THE UNITED STATES.

(a) This computer software is submitted with restricted rights under
    Government Contract No. DE-AC03-89ER51114.  It may not be used,
    reproduced, or disclosed by the Government except as provided in
    paragraph (b) of this Notice or as otherwise expressly stated in the
    contract.
(b) This MIMO computer software shall be used exclusively in the
    DIII-D Program and may be --
   (1) Used or copied for use in or with the computer or computers for
       which it was acquired, including use at any Government installation to 
       which the DIII-D fusion reactor may be transferred;
   (2) Used or copied for use in a backup computer if any computer for
       which it was acquired is inoperative;
   (3) Reproduced for safekeeping (archives) or backup purposes;
   (4) Modified, adapted, or combined with other computer software,
       provided that the modified, combined, or adapted portions of the
       derivative software are made subject to the same restricted rights;
   (5) Disclosed to and reproduced for use by support service Contractors
       in accordance with subparagraphs (b)(1) through (4) of this clause,
       provided the Government makes such disclosure or reproduction
       subject to these restricted rights; and
   (6) Used or copied for use in or transferred to a replacement computer.
(c) Notwithstanding the foregoing, if this computer software is published
    copyrighted computer software, it is licensed to the Government without
    disclosure prohibitions, with the minimum rights set forth in paragraph
    (b) of this clause.
(d) Any other rights or limitations regarding the use, duplication, or
    disclosure of this computer software are to be expressly stated in, or
    incorporated in, the contract.
(e) This Notice shall be marked on any reproduction of this computer
    software, in whole, or in part.
****************************************************************************/

double *y,*u;
{

static double C=60e-6;

static double D0 = 0.62817231151521;
static double D1 = 0.01769932659536;
static double D2 = -0.00196451403351;
static double D3 = 0.00042527696158;
static double D4 = 0.00001026788059;
static double D5 = -0.00000290102398;

static double   f0 = 3039.11738058144;
static double   f2 = -69.32564780093;
static double   f4 = 2.43961202588;
static double   f6 = -0.06193295984;
static double   f8 = 0.00069005995;
static double   f10 = -0.00000269069;

static double second = 2.0;
static double third = 3.0;
static double fourth = 4.0;
static double fifth = 5.0;
static double sixth = 6.0;
static double eighth = 8.0;
static double tenth = 10.0;

double D, model_f, V01, V02, V02avg;
double N, Dtemp, Dtemp2, I;

N = u[3];

model_f = f0 + f2*pow(u[2],second) 
	+ f4*pow(u[2],fourth) +  f6*pow(u[2],sixth)
	+ f8*pow(u[2],eighth) +  f10*pow(u[2],tenth);

V01 = u[1];

D = D0 +D1*u[2] + D2*pow(u[2],second) 
		+ D3*pow(u[2],third) +  D4*pow(u[2],fourth)
		+ D5*pow(u[2],fifth);

#ifdef DEBUG

printf(" N = %f\n",N);
printf(" model_f = %f\n",model_f);
printf(" V01 = %f\n",V01);

printf(" D = %f\n",D);

#endif

I = u[0]/N;	
#ifdef DEBUG
printf(" I = %f\n",I);
#endif

if (I<700)
   V02 = -.75*I;
else
   V02 = -pow((1575*I - 6e5),(double)0.476);

#ifdef DEBUG
printf(" V02 = %f\n",V02);
#endif

V02avg = V02*(1+ (.55*1.8*C*V02*N*model_f)/((1-D)*u[0]));
#ifdef DEBUG
printf(" V02avg = %f\n",V02avg);
#endif
if (V02avg > 0) V02avg=0;				/* KLUGE */

*y = V01*D + V02avg*(1-D);
#ifdef DEBUG
printf(" y = %f\n",*y);
#endif

return;

}










