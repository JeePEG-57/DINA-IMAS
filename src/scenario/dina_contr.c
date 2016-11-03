
#define NINPUTS       3
#define NOUTPUTS      4

#define NINPUTARGS	2

#define KEYMATARG	0

#define VECMATARG	1


#define N_MAT 		100	/* maximum number of elts in key_mat */


static long key_mat[N_MAT];

static double *vec_mat_in;

static double vec_mat[N_MAT];

static long n_port1;
static long n_port2;
static long n_port3;

static long out_port1;
static long out_port2;
static long out_port3;
static long out_port4;



#define S_FUNCTION_NAME      dina_contr    /* Model name */
#define S_FUNCTION_LEVEL     2

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include "simstruc.h"

#if      0
#include "matrix.h"
#endif

#ifdef   MATLAB_MEX_FILE
#include "mex.h"
#endif

#define U1(element) (*uPtrs1[element])
#define U2(element) (*uPtrs2[element])
#define U3(element) (*uPtrs3[element])


static double max_dt;
static double min_dt; 
static double tlast;


static double t_mat;
static double dt_mat;
static double ttt;

#if defined (_MSC_VER)

#define eq_ech_ EQ_ECH

#endif


#if !defined(_MSC_VER)

#define eq_ech_ eq_ech_

#endif



/* 
#define eq_ech_ EQ_ECH

#define eq_ech_ eq_ech__

*/

extern void eq_ech_(double	*t_mat,
					   double	*ttt,
					   double	*dt_mat,
					   long		*key_mat,
					   double	*vec_mat,
					   double	*p_input1,
					   double	*p_input2,
					   double	*p_input3,
					   double	*output_1,
					   double	*output_2,
					   double	*output_3,
					   double	*output_4,
					   long		*ng);


/******************************************************************************/
/*                        MDL checking                                        */
/******************************************************************************/

#define MDL_CHECK_PARAMETERS
#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

static void mdlCheckParameters(SimStruct *S)
{ 
	char    *msg = NULL;
   
	double *temp;

	long m,n;

	temp = mxGetPr(ssGetSFcnParam(S,KEYMATARG));

	m = mxGetM(ssGetSFcnParam(S,KEYMATARG));

	n = mxGetN(ssGetSFcnParam(S,KEYMATARG));

	mexPrintf("mdlCheckParameters key_mat m  n  %d %d\n",m,n);


	if(m!=1 && n!=1)
	{
		mexPrintf(" key_mat must be vector m  n  %d %d\n",m,n);
	
		msg = "key_mat must be vector";

		goto EXIT_POINT;
	}


	vec_mat_in = mxGetPr(ssGetSFcnParam(S,VECMATARG));

	m = mxGetM(ssGetSFcnParam(S,VECMATARG));

	n = mxGetN(ssGetSFcnParam(S,VECMATARG));

	mexPrintf("mdlCheckParameters vec_mat m  n  %d %d\n",m,n);



	if(m!=1 && n!=1)
	{
		msg = "vec_mat must be a vector";

		goto EXIT_POINT;
	}

	EXIT_POINT:

	if(msg != NULL) 
	{

		ssSetErrorStatus(S,msg);

	}

}

#endif 

/******************************************************************************/
/*                MDL initialized sizes                                       */
/******************************************************************************/
static void mdlInitializeSizes(SimStruct *S)
{
	long m,n;

	long k;

	long in_port1, in_port2;
	long in_port3;
	long out_port1, out_port2, out_port3, out_port4;

	double *temp;

	real_T ts;

	tlast  = 0.0;

   
	/* Load ts for input and output ports */

	ts     = INHERITED_SAMPLE_TIME;

	
	ssSetNumSFcnParams(S,NINPUTARGS);

	temp = mxGetPr(ssGetSFcnParam(S,KEYMATARG));

	m = mxGetM(ssGetSFcnParam(S,KEYMATARG));

	n = mxGetN(ssGetSFcnParam(S,KEYMATARG));

	for (k=0; k < 25; k++) { 

		key_mat[k]	= (long)temp[k];

	}
	in_port1=key_mat[5];
	in_port2=key_mat[6];
	in_port3=key_mat[7];

	out_port1=key_mat[10];
	out_port2=key_mat[11];
	out_port3=key_mat[12];
	out_port4=key_mat[13];


	vec_mat_in = mxGetPr(ssGetSFcnParam(S,VECMATARG));

	m = mxGetM(ssGetSFcnParam(S,VECMATARG));

    n = mxGetN(ssGetSFcnParam(S,VECMATARG));

	for (k=0; k < 30; k++) { 

	vec_mat[k]	= vec_mat_in[k];

	}


	ssSetNumContStates (S, 0);   /* number of continuous states */
	
	ssSetNumDiscStates (S, 0);   /* number of discrete states */
 
	
	if(!ssSetNumInputPorts(S,NINPUTS)) return;

	ssSetInputPortWidth (S, 0, in_port1); 
	ssSetInputPortDirectFeedThrough (S,0,1); /* it was (S,0,0) */

	ssSetInputPortWidth (S, 1, in_port2); 
	ssSetInputPortDirectFeedThrough (S,1,1); 

	ssSetInputPortWidth (S, 2, in_port3); 
	ssSetInputPortDirectFeedThrough (S,2,1); 


 
	if(!ssSetNumOutputPorts(S,NOUTPUTS)) return;

	ssSetOutputPortWidth(S,0,out_port1);       /* d_pf_mat */

	ssSetOutputPortWidth(S,1,out_port2);       

	ssSetOutputPortWidth(S,2,out_port3);       

	ssSetOutputPortWidth(S,3,out_port4);       

   
	ssSetNumDWork (S, 4);  
   
	ssSetDWorkWidth   (S, 0, out_port1);
	ssSetDWorkDataType(S, 0, SS_DOUBLE);

	ssSetDWorkWidth   (S, 1, out_port2);
	ssSetDWorkDataType(S, 1, SS_DOUBLE);

	ssSetDWorkWidth   (S, 2, out_port3);
	ssSetDWorkDataType(S, 2, SS_DOUBLE);

	ssSetDWorkWidth   (S, 3, out_port4);
	ssSetDWorkDataType(S, 3, SS_DOUBLE);

	ssSetNumRWork(S, 0);      /* size of real work array */

	ssSetNumIWork(S, 0);       /* number of integer work vector elements */
	
	ssSetNumPWork(S, 0);
	
	ssSetNumModes(S, 0);
	
	ssSetNumNonsampledZCs(S, 0);

}

/******************************************************************************/
/*                MDL set input port sample time                              */
/******************************************************************************/

#if defined(MDL_SET_INPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)

static void mdlSetInputPortSampleTime(SimStruct *S,
                                      int_T     portIdx,
                                      real_T    sampleTime,
                                      real_T    offsetTime)
{

#ifdef DEBUG
fprintf(stderr,"mdlSetInputPortSampleTime, sampleTime=%g, offsetTime=%g\n",
        sampleTime,offsetTime);
#endif

   ssSetInputPortSampleTime(S, portIdx, sampleTime);
   
   ssSetInputPortOffsetTime(S, portIdx, offsetTime);

#if 0
   for(i=0; i<NOUTPUTS; ++i)
   {
      ssSetOutputPortSampleTime(S, i, sampleTime);

      ssSetOutputPortOffsetTime(S, i, offsetTime);
   }
#endif
}
#endif


/******************************************************************************/
/*                MDL set output port sample time                             */
/******************************************************************************/

#if defined(MDL_SET_OUTPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)

static void mdlSetOutputPortSampleTime(SimStruct *S,
                                      int_T     portIdx,
                                      real_T    sampleTime,
                                      real_T    offsetTime)
{
#ifdef DEBUG
fprintf(stderr,"mdlSetOutputPortSampleTime, sampleTime=%g, offsetTime=%g\n",
        sampleTime,offsetTime);
#endif

   ssSetOutputPortSampleTime(S, portIdx, sampleTime);
   
   ssSetOutputPortOffsetTime(S, portIdx, offsetTime);
}
#endif


/******************************************************************************/
/*                MDL initialize sample timesime                              */
/******************************************************************************/

static void mdlInitializeSampleTimes(S)

SimStruct *S;
{
    const char_T *bpath = ssGetPath(S);

    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME); 
   
	ssSetOffsetTime(S, 0, 0.0); 
}


/******************************************************************************/
/*                MDL initialize condiations                                  */
/******************************************************************************/
#define MDL_INITIALIZE_CONDITIONS
#ifdef MDL_INITIALIZE_CONDITIONS  

static void mdlInitializeConditions(S)
SimStruct *S;
{
    InputRealPtrsType uPtrs1 = ssGetInputPortRealSignalPtrs(S,0);

    InputRealPtrsType uPtrs2 = ssGetInputPortRealSignalPtrs(S,1);

    InputRealPtrsType uPtrs3 = ssGetInputPortRealSignalPtrs(S,2);



    long	k;

	
	real_T *output_1  = (real_T *)ssGetOutputPortRealSignal(S,0);

    real_T *output_2  = (real_T *)ssGetOutputPortRealSignal(S,1);

    real_T *output_3  = (real_T *)ssGetOutputPortRealSignal(S,2);

    real_T *output_4 = (real_T *)ssGetOutputPortRealSignal(S,3);

	/* real_T *d_pf_mat4 = (real_T *)ssGetOutputPortRealSignal(S,3); */

    double *c_0 = (double *) ssGetDWork(S, 0);

    double *c_1 = (double *) ssGetDWork(S, 1);

    double *c_2 = (double *) ssGetDWork(S, 2);

    double *c_3 = (double *) ssGetDWork(S, 3);	

    double *p_input_1;  
    
	double *p_input_2;  
    
	double *p_input_3;

	

    real_T t,dt;
   
    min_dt = 0.1;

    max_dt = 2.0;
      

    p_input_1     = (double *)&(U1(0)); 
	
	p_input_2     = (double *)&(U2(0)); 
	
	p_input_3     = (double *)&(U3(0)); 



	for (k=0; k < 30; k++) { 

	vec_mat[k]	= vec_mat_in[k];

	}
	

	min_dt = vec_mat_in[9];

	if(vec_mat_in[10]==0.0)
		
		max_dt = 5e-3;

	else

		max_dt = vec_mat_in[10];
	

	t = ssGetT(S);

    dt = t - tlast;

    if(dt<min_dt)

       dt=0.0;

    else

       tlast = t;


	if(dt < max_dt)
		
		vec_mat[9] = dt;

    else

        vec_mat[9] = max_dt;


    vec_mat[9]=vec_mat_in[9]; 


	/* vec_mat[10]=min_dt;

	vec_mat[17]=t; */


	t_mat=t;

	dt_mat=vec_mat[9]; /* time step is extructed from vec(10) */ 

/*	printf("mdlInit vec_mat(10-12)= %g %g %g \n", vec_mat[9],vec_mat[10],vec_mat[11]);  

*/
    printf("mdlInit t_mat dt_mat= %g %g \n", t_mat, dt_mat);  

/*
	equil_mit_(&t_mat,&ttt,&dt_mat,key_mat,vec_mat,p_input_1,p_input_2,p_input_3,d_pf_mat,d_pf_mat2,d_pf_mat3,&ng);

*/

/*    printf(" mdlInit ng= %d \n", ng);

    printf("mdlInit ttt %g \n", ttt); */

/*
    d_pf_mat3[0]=p_input_3[0]+1.;

    printf(" mdlInit ttt= %g \n", ttt);
 
    for (k=0; k<ssGetDWorkWidth(S,0); k++)  c_0[k]=d_pf_mat[k];
    for (k=0; k<ssGetDWorkWidth(S,1); k++)  c_1[k]=d_pf_mat2[k];
    for (k=0; k<ssGetDWorkWidth(S,2); k++)  c_2[k]=d_pf_mat3[k];
*/
 
}
#endif  

/******************************************************************************/
/*                MDL update                                                  */
/******************************************************************************/
#define MDL_UPDATE

static void mdlUpdate(SimStruct *S, int_T tid)
{
    

 }


/******************************************************************************/
/*                MDL Outputs                                                 */
/******************************************************************************/
static void mdlOutputs (S, tid)
SimStruct * S;
int_T     tid;
{



    InputRealPtrsType uPtrs1 = ssGetInputPortRealSignalPtrs(S,0);

    InputRealPtrsType uPtrs2 = ssGetInputPortRealSignalPtrs(S,1);

    InputRealPtrsType uPtrs3 = ssGetInputPortRealSignalPtrs(S,2);



    real_T *output_1     = (real_T *)ssGetOutputPortRealSignal(S,0);
    
	real_T *output_2    = (real_T *)ssGetOutputPortRealSignal(S,1);

    real_T *output_3    = (real_T *)ssGetOutputPortRealSignal(S,2);

    real_T *output_4    = (real_T *)ssGetOutputPortRealSignal(S,3);

    double *c_0 = (double *) ssGetDWork(S, 0);

    double *c_1 = (double *) ssGetDWork(S, 1);
    
	double *c_2 = (double *) ssGetDWork(S, 2);

	double *c_3 = (double *) ssGetDWork(S, 3);


    long k;

	long	ng;	

	long in_port3;

    double *p_input_1;  
    
	double *p_input_2;  
    
	double *p_input_3;
	    



	real_T time_T;

    real_T t,dt;


    p_input_1      = (double *)&(U1(0)); 
	
	p_input_2     = (double *)&(U2(0)); 
	
	p_input_3     = (double *)&(U3(0)); 


	min_dt=1000.;

	dt=min_dt;

	t  = ssGetT(S);
	dt = t - tlast;
	tlast = t;


/*
	printf(" Input_1(1-5)= %g %g %g %g %g \n", p_input_1[0],p_input_1[1],p_input_1[2],p_input_1[3],p_input_1[4]);
	printf(" Input_1(6-10)= %g %g %g %g %g \n", p_input_1[5],p_input_1[6],p_input_1[7],p_input_1[8],p_input_1[9]);
	printf(" Input_1(11-15)= %g %g %g %g %g \n", p_input_1[10],p_input_1[11],p_input_1[12],p_input_1[13],p_input_1[14]);
	printf(" Input_1(16-20)= %g %g %g %g %g \n", p_input_1[15],p_input_1[16],p_input_1[17],p_input_1[18],p_input_1[19]);
	printf(" Input_1(20-25)= %g %g %g %g %g \n", p_input_1[20],p_input_1[21],p_input_1[22],p_input_1[23],p_input_1[24]);
	printf(" Input_1(26-30)= %g %g %g %g %g \n", p_input_1[25],p_input_1[26],p_input_1[27],p_input_1[28],p_input_1[29]);
*/

	t_mat=t;

	dt_mat=dt;
      
/*    printf("dina-ech t_mat dt_mat= %g %g \n", t_mat, dt_mat);   */


	eq_ech_(&t_mat,&ttt,&dt_mat,key_mat,vec_mat,
		p_input_1,p_input_2,p_input_3,
		output_1,output_2,output_3,output_4,&ng);

/*    printf(" dina-ech Output ttt= %g \n", ttt); */
	
	printf(" dina-contr ng= %d \n", ng);

/*
	c_1[0]=p_input_2[0]-10.;

    c_2[0]=p_input_3[0]+10.; */

/*
	for (k=0; k<384; k++)      
		printf(" dina_ech: input2 %g \n", p_input_2[k]);

	in_port3=key_mat[7];

	printf(" dina-ech in_port3= %d \n", in_port3);

    for (k=0; k<in_port3; k++)      
		printf(" dina_ech: input3 %g \n", p_input_3[k]);
*/
}

/******************************************************************************/
/*                MDL derivatives                                             */
/******************************************************************************/
static void mdlDerivatives(S)
SimStruct *S;
{
}

/******************************************************************************/
/*                MDL terminate                                               */
/******************************************************************************/
static void mdlTerminate(SimStruct *S)
{
}

#ifdef MATLAB_MEX_FILE                  /* Compiled as MEX-file?*/
#include "simulink.c"                   /* Mex file interface */
#else
#include "cg_sfun.h"                    /* Code generation registration */
#endif
