/* @(#)dina.c	1.1 07/13/00 */



/*************************************************************************

PURPOSE:  Compute one DINA iteration.

Variable names are kept consistent with DINA code whenever possible.



This was built to work seamlessly with SIMULINK simulations and to generate

the proper C-code with RTW.  



********************* ALL UNITS ARE MKS ********************************



INPUT(u):

   pf_mat    = PF coils current (Amps) (length npf_mat)

   tcam_mat  = vessel filaments current (Amps) (length ncam_mat)

   contpts_mat = npts_mat inputs of (R,Z) of measurement points



ARGUMENTS:

   key_mat = vector of keys to control simulation (only 1 entry right now)

		Entries:

		1: values=0,1,2: "standard" current density profiles (see below)

		2: if=1, t_e, t_i calculated, =0, t_e,t_i are given

		3: =n, n is time steps, after which plasma current is calculated

		4: value for kpr = flag to turn on debug printing (1=on,0=off)

		5: nr = number of grid points in r coordinate

		6: nz = number of grid points in z coordinate

			(number of grid pts nwnh = nr * nz)

		7: key to control equilibrium (0-iteration with transport, 

		        1- one times transport for each quilibrium)

		8: npf_mat = PF coils number

		9: ncam_mat = Vessel filaments number

		10: kloop_mat = Psi loops number

		11: kprobe_mat = Bprobes number

		12: npts_mat = number of control points to compute output for

		13: key to control average density if=0, no; if=1,yes

		14: key to control T-11 scaling 

   vec_mat = vector of parameters:

		1->4 = current density profile coefficients (set by the code?)

			If key_mat(1) = 0, ??

			If key_mat(1) = 1, EFIT parametrization:

				vec_mat(1) = alpha1

				vec_mat(2) = alpha2

				vec_mat(3) = beta1 

				vec_mat(4) = beta2

			If key_mat(1) = 2, Strickler:

				vec_mat(1) = beta

				vec_mat(2) = alfa1

		5    = RMAG [m] is mag axis coordinate 

		6    = ZMAG [m] is mag axis coordinate 

		7    = RS0 [m] is Geomeric Centre

		8    = bt0 [T] Toroidal field at RS0 

		9    = I_pl [A] Plasma current

		10   = tay [sec] min time step value 

		11   = tay [sec] max time step value 

		12   = power_ech [MW]

		13   = y0 [cm] ECH power deposition point ( 0-a),a-minor radius

		14   = te_mat [ eV] Electron temperature at axis



   gridrange = [z_l, z_r, r_l, r_r], where

		z_l = Z of lower point of grid

		z_r = Z of upper point of grid

		r_l = R of left point of grid

		r_r = R of right point of grid

   fluxarr_mat  = are Mutuals PF to grid (size nwnh x npf_mat)

   vesarr_mat   = Mutuals vessel to grid (size nwnh x ncam_mat)

   pslgreen_mat = Mutuals flux loops to grid (size nwnh x kloop_mat)

   bprgreen_mat = greens magnetic probes to grid (size nwnh x kprobe_mat)

   pfind_mat    = mutuals PF to PF (size npf_mat x npf_mat)

   pmj_mat      = mutuals ves to ves (size ncam_mat x ncam_mat)

   pfc_mat      = mutuals ves to PF (size ncam_mat x npf_mat)

   pfres_mat    = PF coils resistance (npf_mat)

   rcam_mat     = vessel filaments resistance (ncam_mat)

   xu_mat,yu_mat= R and Z of limiter points (ke_mat), monotonic 

			distribution in angle



OUTPUT(y):

   d_pf_mat     = change in PF coils current after call to DINA (size npf_mat)

   d_tcam_mat   = change in Vessel current after DINA (size ncam_mat)

   pl_loop_mat  = plasma to Loops signal (size kloop_mat)

   pl_probe_mat = plasma to probes signal (size kprobe_mat)

   pl_pf_mat    = plasma to PF signal (size npf_mat)

   pl_ves_mat   = plasma to ves signal (size ncam_mat)

   shape_out    = shape parameters during evolution:

   		  1) PLASMA CURRENT [A]

   		  2) RMAG [m]

   		  3) ZMAG [m]

   		  4) a [m]

   		  5) elong

   		  6) elong_upper

   		  7) elong_down

   		  8) triangularity

   		  9) triangularity_upper

   		  10) triangularity_down

   		  11) beta_pol

   		  12) li(3)

   		  13) q_axis

   		  14) q_bound

   		  15) T_e axis [ Ev]

                  16) Xpt R

                  17) Xpt Z

                  18) number of points N defining plasma boundary (to follow)

          19 to 19+N) r-coordinates of boundary [m]

       19+N to 19+2N) z-coordinates of boundary [m]

  contvals  = npts_mat output of (psi,B_r B_z) at measurement points



RESTRICTIONS:  Data objects for plasma grid are fixed in size.  All other

objects are limited by maximum dimensions:

	npf_mat < KF_MAT 

	ncam_mat < MU_MAT 

	kloop_mat < NLOOP_MAT

	kprobe_mat < NPROBE_MAT

	ke_mat < MU_L_MAT

(See definitions of sizes below.)  



METHOD:  



WRITTEN BY:  Mike Walker        ON      6/21/00

****************************************************************************/

#define DEBUG

#undef DEBUG



/*

These definitions must be maintained to be consistent with parameter 

statements in file parf2.

*/

#if 0

#define NZ 65		/* number of grid points in z direction */

#define NR 33		/* number of grid points in r direction */

#define NWNH NR*NZ



#define NN 33

#define MM 65

#define MU1 400

#define NGRID 196 

#define NWH NZ*NWNH

#endif

#define n_prof 26


#define NINPUTS		5

#define NOUTPUTS       12

#define N_SHAPE_OUT	32 	/* Defined internally to DINA */
#define N_BOUND_OUT	1000 	/* Defined internally to DINA */
#define N_SURF_OUT	100*90 	/* Defined internally to DINA */


#define n_port1       14
#define n_port2       54
#define n_port3       19
#define n_port4       12


/*

These definitions must be maintained to be consistent with parameter 

statements in file n_dina.f.

*/

#define K_AUX		6	/* maximum number of auxiliary heating points*/


#define N_MAT 		100	/* maximum number of elts in key_mat */

#define KF_MAT		120	/* maximum number of F-coils */

#define MU_MAT		401	/* maximum number of vessel filaments */

#define NLOOP_MAT	50	/* maximum number of flux loops */

#define NPROBE_MAT	80	/* maximum number of B probes */

#define MU_L_MAT	403



#define NINPUTARGS	25

#define KEYMATARG	0

#define VECMATARG	1

#define RANGEARG	2

#define FLUXARRARG	3

#define VESARRARG	4

#define PSLGREENARG	5

#define BPRGREENARG	6

#define PFINDARG	7

#define PMJARG		8

#define PFCARG		9

#define PFRESARG	10

#define RCAMARG		11

#define XUARG		12

#define YUARG		13

#define PF_MAT0ARG	14

#define TCAM_MAT0ARG    15

#define PFGREENARG	16

#define VESGREENARG	17

#define PFPROBEARG	18

#define VESPROBEARG	19


#define BP_EXPARG	20


#define PS_EXPARG	21


#define PF_EXPARG	22

#define INDPF_MATARG	23

#define EXT_TRANSP_MATARG	24




static int npf_mat;		/* actual number of PF coils */

static int ncam_mat;		/* actual number of vessel elts */

static int nprof_mat;		/* actual number output profiles */

static int n_inp_prof;		/* actual number output profiles */

static int n_aux_prof;		/* actual number aux profiles */


static int n_surf;		/* actual number of output surfaces */

static int n_surf_psi;		/* actual number of psi- surfaces */

static int n_surf_cur;		/* actual number of cur-surfaces */

static int n_polar_cur;		/* actual number of polar-cur-surfaces */


static int kloop_mat;		/* actual number of flux loops */

static int kprobe_mat;		/* actual number of B probes   */

static int npts_mat;		/* number of control points */

static int ke_mat;		/* number of points in limiter */

static int kf_mat = KF_MAT;

static int mu_mat = MU_MAT;

static double z_l;

static double z_r;

static double r_l;

static double r_r;

static int key_mat[N_MAT];

static double *vec_mat_in;

static double *pf_mat0;

static double *tcam_mat0;



static double *rcam_mat; 

static double *xu_mat; 

static double *yu_mat; 

static double *pfres_mat; 

static double *pfc_mat;

static double *pmj_mat; 

static double *pfind_mat; 

static double *bprgreen_mat; 

static double *pslgreen_mat;

static double *vesarr_mat; 

static double *fluxarr_mat; 



static double *pfgreen_mat;

static double *vesgreen_mat;

static double *pfprobe_mat;

static double *vesprobe_mat;

static double *bp_exp_mat;

static double *ps_exp_mat;

static double *pf_exp_mat;

static double *indpf_mat;

static double *ext_transp_mat;


static double aux_heat[K_AUX];

static int nr,nz,nwnh;



#define S_FUNCTION_NAME      dina_v90 /* Model name */

#define S_FUNCTION_LEVEL	2


#include <stdio.h>

#include <stdlib.h>

#include <float.h>

#include <math.h>

#include "simstruc.h"

#if 0

#include "matrix.h"

#endif



#define U1(element) (*uPtrs1[element])

#define U2(element) (*uPtrs2[element])

#define U3(element) (*uPtrs3[element])

#define U4(element) (*uPtrs4[element])

#define U5(element) (*uPtrs5[element])


static double vec_mat[N_MAT];

static double max_dt;

static double min_dt; 

static double tlast;



#ifdef MATLAB_MEX_FILE

#include "mex.h"

#endif

#include "dina.h"


/* This patch is added for PC186 version */ 

#if !defined(_MSC_VER)

#define dina_ dina_

#define tran_to_dina_ tran_to_dina__

#define time_iterp_ time_iterp__

#endif



extern void time_iterp_(

			  double    *time,

			  double    *pl_loop_mat,

			  double    *pl_probe_mat,

			  double    *d_pf_mat,

			  double    *shape_out);



extern void tran_to_dina_(int		*ncam_mat,

			  int		*npf_mat,

			  int		*kloop_mat,

			  int		* kprobe_mat,

			  double	*z_l,

			  double	*z_r,

			  double	*r_l,

			  double	*r_r,

			  int		*kf_mat,

			  int		*mu_mat,

			  double	*fluxarr_mat,

			  double	*vesarr_mat,

			  double	*pslgreen_mat,

			  double	*bprgreen_mat,

			  double	*pfind_mat,

			  double	*pmj_mat,

			  double	*pfc_mat,

			  double	*pfres_mat,

			  double	*rcam_mat,

			  double	*xu_mat,

			  double	*yu_mat,

			  int		*ke_mat,

			  int		*key_mat,

              double    *pfgreen_mat,

			  double    *vesgreen_mat,

              double    *pfprobe_mat,

              double    *vesprobe_mat);





extern void dina_(int *key_mat,

		  double	*vec_mat,

		  double	*pf_mat0,

		  double	*tcam_mat0, 

		  double	*d_pf_mat,

		  double	*d_tcam_mat,

		  double	*pl_loop_mat,

		  double	*pl_probe_mat,

		  double	*pl_pf_mat,

		  double	*pl_ves_mat,

		  double	*shape_out,

		  int		*k_out_dina,

		  double	*contpts_mat,

		  double	*contvals_mat,

		  int		* npts_mat,

		  double	*ech_data,

                  double * bp_exp_mat,

                  double *  ps_exp_mat,

                  double *   pf_exp_mat,

                  double    *   indpf_mat,

                  double    *   ext_transp_mat,

                  double     *c_prof_mat,

                  double     *aux_heat,

                  double     *aux_prof,

                  double     *surf_mat,

                  double     *surf_psi,

                  double     *surf_cur,

                  double     *polar_cur);

/*========================================================*/





#define MDL_CHECK_PARAMETERS

#if defined(MDL_CHECK_PARAMETERS) && defined(MATLAB_MEX_FILE)

  /* Function: mdlCheckParameters =============================================

   * Abstract:

   *    Validate our parameters to verify they are okay.

   *    If the parameter matrices are not all vectors of the same length

   *    report error back to Simulink

   */

  static void mdlCheckParameters(SimStruct *S)

{

   int m,n;

   char *msg = NULL;

   double *temp;



   temp = mxGetPr(ssGetSFcnParam(S,KEYMATARG));

   nr = (int)temp[4];

   nz = (int)temp[5];

   nwnh = nr*nz;	/* number of grid points */



   



   

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



   pf_mat0 = mxGetPr(ssGetSFcnParam(S,PF_MAT0ARG));

   m = mxGetM(ssGetSFcnParam(S,PF_MAT0ARG));

   n = mxGetN(ssGetSFcnParam(S,PF_MAT0ARG));

   mexPrintf("mdlCheckParameters pf_mat0 m  n  %d %d\n",m,n);



   tcam_mat0 = mxGetPr(ssGetSFcnParam(S,TCAM_MAT0ARG));

   m = mxGetM(ssGetSFcnParam(S,TCAM_MAT0ARG));

   n = mxGetN(ssGetSFcnParam(S,TCAM_MAT0ARG));

   mexPrintf("mdlCheckParameters tcam_mat0 m  n  %d %d\n",m,n);


   bp_exp_mat = mxGetPr(ssGetSFcnParam(S,BP_EXPARG));

   m = mxGetM(ssGetSFcnParam(S,BP_EXPARG));

   n = mxGetN(ssGetSFcnParam(S,BP_EXPARG));

   mexPrintf("mdlCheckParameters bp_exp_mat m  n  %d %d\n",m,n);


   ps_exp_mat = mxGetPr(ssGetSFcnParam(S,PS_EXPARG));

   m = mxGetM(ssGetSFcnParam(S,PS_EXPARG));

   n = mxGetN(ssGetSFcnParam(S,PS_EXPARG));



   mexPrintf("mdlCheckParameters ps_exp_mat m  n  %d %d\n",m,n);

   pf_exp_mat = mxGetPr(ssGetSFcnParam(S,PF_EXPARG));

   m = mxGetM(ssGetSFcnParam(S,PF_EXPARG));

   n = mxGetN(ssGetSFcnParam(S,PF_EXPARG));

   mexPrintf("mdlCheckParameters pf_exp_mat m  n  %d %d\n",m,n);



   indpf_mat = mxGetPr(ssGetSFcnParam(S,INDPF_MATARG));


   m = mxGetM(ssGetSFcnParam(S,INDPF_MATARG));

   n = mxGetN(ssGetSFcnParam(S,INDPF_MATARG));

   mexPrintf("mdlCheckParameters indpf_mat m  n  %d %d\n",m,n);

   ext_transp_mat = mxGetPr(ssGetSFcnParam(S,EXT_TRANSP_MATARG));

   m = mxGetM(ssGetSFcnParam(S,EXT_TRANSP_MATARG));

   n = mxGetN(ssGetSFcnParam(S,EXT_TRANSP_MATARG));

   mexPrintf("mdlCheckParameters ext_transp_mat m  n  %d %d\n",m,n);


   m = mxGetM(ssGetSFcnParam(S,FLUXARRARG));

   if(m != nwnh) 

   {

      msg = "First dimension of fluxarr must be exactly 33*65";

      goto EXIT_POINT;

   }


   /*
   npf_mat = mxGetN(ssGetSFcnParam(S,FLUXARRARG));

   */



   if(npf_mat > KF_MAT)

   {

      msg = "Second dimension of fluxarr must be less than KF_MAT";

      goto EXIT_POINT;

   }



   m = mxGetM(ssGetSFcnParam(S,VESARRARG));

   if(m != nwnh) 

   {

      msg = "First dimension of vesarr must be exactly 33*65";

      goto EXIT_POINT;

   }

   ncam_mat = mxGetN(ssGetSFcnParam(S,VESARRARG));

   if(ncam_mat > MU_MAT)

   {

      msg = "Second dimension of vesarr must be less than MU_MAT";

      goto EXIT_POINT;

   }



   m = mxGetM(ssGetSFcnParam(S,PSLGREENARG));

   if(m != nwnh) 

   {

      msg = "First dimension of pslgreenarr must be exactly 33*65";

      goto EXIT_POINT;

   }

   kloop_mat = mxGetN(ssGetSFcnParam(S,PSLGREENARG));

   if(kloop_mat > NLOOP_MAT)

   {

      msg = "Second dimension of pslgreenarr must be less than NLOOP_MAT";

      goto EXIT_POINT;

   }



   m = mxGetM(ssGetSFcnParam(S,BPRGREENARG));

   if(m != nwnh) 

   {

      msg = "First dimension of bprgreenarr must be exactly 33*65";

      goto EXIT_POINT;

   }

   kprobe_mat = mxGetN(ssGetSFcnParam(S,BPRGREENARG));

   if(kprobe_mat > NPROBE_MAT)

   {

      msg = "Second dimension of pslgreenarr must be less than NPROBE_MAT";

      goto EXIT_POINT;

   }



   m = mxGetM(ssGetSFcnParam(S,PFINDARG));

   n = mxGetN(ssGetSFcnParam(S,PFINDARG));

   if(m!= npf_mat || n!= npf_mat)

   {

      msg = "Both dimensions of of pfindarg must equal npf_mat ";

      goto EXIT_POINT;

   }



   m = mxGetM(ssGetSFcnParam(S,PMJARG));

   n = mxGetN(ssGetSFcnParam(S,PMJARG));

   if(m != ncam_mat || n!= ncam_mat)

   {

      msg = "Both dimensions of of pmjarg must equal ncam_mat ";

      goto EXIT_POINT;

   }



   m = mxGetM(ssGetSFcnParam(S,PFCARG));

   n = mxGetN(ssGetSFcnParam(S,PFCARG));

   if(m != ncam_mat || n!= npf_mat)

   {

      msg = "Matrix pfc must be ncam_mat by npf_mat ";

      goto EXIT_POINT;

   }



   m = mxGetM(ssGetSFcnParam(S,PFRESARG));

   n = mxGetN(ssGetSFcnParam(S,PFRESARG));

   if(m==1)

      if(n!=npf_mat)

      {

         msg = "Object pfres must be length npf_mat vector";

         goto EXIT_POINT;

      }

   else if(n==1)

      if(m!=npf_mat)

      {

         msg = "Object pfres must be length npf_mat vector";

         goto EXIT_POINT;

      }

   else

   {

         msg = "Object pfres must be length npf_mat vector";

         goto EXIT_POINT;

   }



   m = mxGetM(ssGetSFcnParam(S,RCAMARG));

   n = mxGetN(ssGetSFcnParam(S,RCAMARG));

   if(m==1)

      if(n!=ncam_mat)

      {

         msg = "Object rcam must be length ncam_mat vector";

         goto EXIT_POINT;

      }

   else if(n==1)

      if(m!=ncam_mat)

      {

         msg = "Object rcam must be length ncam_mat vector";

         goto EXIT_POINT;

      }

   else

   {

         msg = "Object rcam must be length ncam_mat vector";

         goto EXIT_POINT;

   }



/*   ke_mat = number of limiter points  */

   m = mxGetM(ssGetSFcnParam(S,XUARG));

   n = mxGetN(ssGetSFcnParam(S,XUARG));

   if(m==1)

      if(n > MU_L_MAT)

      {

         msg = "Length of xu_mat must be less than MU_L_MAT";

         goto EXIT_POINT;

      }

      else

	 ke_mat = n;

   else if(n==1)

      if(m > MU_L_MAT)

      {

         msg = "Length of xu_mat must be less than MU_L_MAT";

         goto EXIT_POINT;

      }

      else

	 ke_mat = m;

   else

   {

         msg = "Length of xu_mat must be less than MU_L_MAT";

         goto EXIT_POINT;

   }



   m = mxGetM(ssGetSFcnParam(S,YUARG));

   n = mxGetN(ssGetSFcnParam(S,YUARG));

   if(m==1)

      if(n!=ke_mat)

      {

         msg = "Length of yu_mat must be less than MU_L_MAT";

         goto EXIT_POINT;

      }

   else if(n==1)

      if(m!=ke_mat)

      {

         msg = "Length of yu_mat must be less than MU_L_MAT";

         goto EXIT_POINT;

      }

   else

   {

         msg = "Length of yu_mat must be less than MU_L_MAT";

         goto EXIT_POINT;

   }



EXIT_POINT:

   if(msg != NULL) 

   {

	ssSetErrorStatus(S,msg);

   }

}

#endif /* MDL_CHECK_PARAMETERS */

 

static void copymat(double *mat_in, int indim1, int indim2,

			double *mat_out, int outdim1, int outdim2)

/*

Copy a double matrix into a float matrix, with appropriate

first dimension in output matrix.

*/

{

   int k,j;



   for(k=0; k<indim2; ++k)

      for(j=0; j<indim1; ++j)

	 mat_out[k*outdim1 + j] = mat_in[k*indim1 + j];

}



/* Function to set up sizes information */

static void mdlInitializeSizes(SimStruct *S)

{

   double *temp;

   double *rcam_mat_in, *xu_mat_in, *yu_mat_in, *pfres_mat_in, *pfc_mat_in;

   double *pmj_mat_in, *pfind_mat_in, *bprgreen_mat_in, *pslgreen_mat_in;

   double *vesarr_mat_in, *fluxarr_mat_in; 



   double *pfgreen_mat_in;

   double *vesgreen_mat_in;

   double *pfprobe_mat_in;

   double *vesprobe_mat_in;



   int m,n,i,k;

   real_T ts;



   tlast = 0.0;



/* Load ts for input and output ports */

   ts = INHERITED_SAMPLE_TIME;



   ssSetNumSFcnParams(S,NINPUTARGS);



   temp = mxGetPr(ssGetSFcnParam(S,KEYMATARG));





   m = mxGetM(ssGetSFcnParam(S,KEYMATARG));

   n = mxGetN(ssGetSFcnParam(S,KEYMATARG));








   for (k=0; k < 25; k++) { 

   key_mat[k]	= (int)temp[k];

   }



   nr = key_mat[4];

   nz = key_mat[5];

   nwnh = nr*nz;	/* number of grid points */



   if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes key_mat m  n  %d %d\n",m,n);
   }

   npf_mat = key_mat[7];

   ncam_mat = key_mat[8];

   kloop_mat = key_mat[9];

   kprobe_mat = key_mat[10];

   npts_mat = key_mat[11];

   npts_mat = N_BOUND_OUT;

   nprof_mat = key_mat[16]; 

   /*   nprof_mat = key_mat[15]*12; */


   /*   n_inp_prof = key_mat[17]; */

   n_inp_prof = key_mat[15]*6;

   /*   n_aux_prof = key_mat[15]*4; */

   n_aux_prof = key_mat[15]*6;

   n_surf = key_mat[15]*2*90;

   n_surf_psi = nwnh;

   n_surf_cur = nwnh;

   n_polar_cur = key_mat[15]*90;

  if(key_mat[3]==1) {

   mexPrintf("mdlInitializeSizes n_surf n_polar_cur %d %d  \n",

   n_surf,n_polar_cur);

   mexPrintf("mdlInitializeSizes n_surf_psi n_surf_cur %d %d  \n",

   n_surf_psi,n_surf_cur);

  }


   if(key_mat[3]==1) {

   mexPrintf("mdlInitializeSizes key_mat:0-4 %d %d %d %d %d  \n",

   key_mat[0],key_mat[1],key_mat[2],key_mat[3],key_mat[4]);



   mexPrintf("mdlInitializeSizes key_mat:5-9 %d %d %d %d %d  \n",

   key_mat[5],key_mat[6],key_mat[7],key_mat[8],key_mat[9]);



   mexPrintf("mdlInitializeSizes key_mat:10-13 %d %d %d %d \n",

   key_mat[10],key_mat[11],key_mat[12],key_mat[13]);

   mexPrintf("mdlInitializeSizes key_mat:14-16 %d  %d %d \n",

   key_mat[14],key_mat[15],key_mat[16]);

   mexPrintf("mdlInitializeSizes key_mat:17-18 %d   \n",

   key_mat[17],key_mat[18]);

  

   mexPrintf("mdlInitializeSizes key_mat:17 %d   \n",

   key_mat[17]);
 }

   pf_mat0 = mxGetPr(ssGetSFcnParam(S,PF_MAT0ARG));

   m = mxGetM(ssGetSFcnParam(S,PF_MAT0ARG));

   n = mxGetN(ssGetSFcnParam(S,PF_MAT0ARG));

   if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes pf_mat0 m  n  %d %d\n",m,n);
   }


   tcam_mat0 = mxGetPr(ssGetSFcnParam(S,TCAM_MAT0ARG));

   m = mxGetM(ssGetSFcnParam(S,TCAM_MAT0ARG));

   n = mxGetN(ssGetSFcnParam(S,TCAM_MAT0ARG));

   if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes tcam_mat0 m  n  %d %d\n",m,n);
   }

   bp_exp_mat = mxGetPr(ssGetSFcnParam(S,BP_EXPARG));

   m = mxGetM(ssGetSFcnParam(S,BP_EXPARG));

   n = mxGetN(ssGetSFcnParam(S,BP_EXPARG));

   if(key_mat[3]==1) {
   mexPrintf("mdlCheckParameters bp_exp_mat m  n  %d %d\n",m,n);
   }

   ps_exp_mat = mxGetPr(ssGetSFcnParam(S,PS_EXPARG));

   m = mxGetM(ssGetSFcnParam(S,PS_EXPARG));

   n = mxGetN(ssGetSFcnParam(S,PS_EXPARG));

   if(key_mat[3]==1) {
   mexPrintf("mdlCheckParameters ps_exp_mat m  n  %d %d\n",m,n);
   }

   pf_exp_mat = mxGetPr(ssGetSFcnParam(S,PF_EXPARG));

   m = mxGetM(ssGetSFcnParam(S,PF_EXPARG));

   n = mxGetN(ssGetSFcnParam(S,PF_EXPARG));

   if(key_mat[3]==1) {
   mexPrintf("mdlCheckParameters pf_exp_mat m  n  %d %d\n",m,n);
   }


   indpf_mat = mxGetPr(ssGetSFcnParam(S,INDPF_MATARG));

   m = mxGetM(ssGetSFcnParam(S,INDPF_MATARG));

   n = mxGetN(ssGetSFcnParam(S,INDPF_MATARG));

   if(key_mat[3]==1) {
   mexPrintf("mdlCheckParameters indpf_mat m  n  %d %d\n",m,n);
   }
   
   ext_transp_mat = mxGetPr(ssGetSFcnParam(S,EXT_TRANSP_MATARG));

   m = mxGetM(ssGetSFcnParam(S,EXT_TRANSP_MATARG));

   n = mxGetN(ssGetSFcnParam(S,EXT_TRANSP_MATARG));

    if(key_mat[3]==1) {
		mexPrintf("mdlCheckParameters ext_transp_mat m  n  %d %d\n",m,n);
    }

   vec_mat_in = mxGetPr(ssGetSFcnParam(S,VECMATARG));


   m = mxGetM(ssGetSFcnParam(S,VECMATARG));

   n = mxGetN(ssGetSFcnParam(S,VECMATARG));



   if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes vec_mat m  n  %d %d\n",m,n);
   }




   if(key_mat[3]==1) {
   mexPrintf("mxGetPr vec_mat_in %g %g %g %g %g \n",
   vec_mat_in[0],vec_mat_in[1],vec_mat_in[2],vec_mat_in[3],vec_mat_in[4]);
   }


   temp = mxGetPr(ssGetSFcnParam(S,RANGEARG));

   z_l = temp[0];

   z_r = temp[1];

   r_l = temp[2];

   r_r = temp[3];



   fluxarr_mat_in = mxGetPr(ssGetSFcnParam(S,FLUXARRARG));
   m = mxGetM(ssGetSFcnParam(S,FLUXARRARG));
   n = mxGetN(ssGetSFcnParam(S,FLUXARRARG));

if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes fluxarr_mat m  n  %d %d\n",m,n);
	}

   vesarr_mat_in = mxGetPr(ssGetSFcnParam(S,VESARRARG));
   m = mxGetM(ssGetSFcnParam(S,VESARRARG));
   n = mxGetN(ssGetSFcnParam(S,VESARRARG));

if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes vesarr_mat m  n  %d %d\n",m,n);
	}

   pslgreen_mat_in = mxGetPr(ssGetSFcnParam(S,PSLGREENARG));
   m = mxGetM(ssGetSFcnParam(S,PSLGREENARG));
   n = mxGetN(ssGetSFcnParam(S,PSLGREENARG));

if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes pslgreen_mat m  n  %d %d\n",m,n);
	}


   bprgreen_mat_in = mxGetPr(ssGetSFcnParam(S,BPRGREENARG));
   m = mxGetM(ssGetSFcnParam(S,BPRGREENARG));
   n = mxGetN(ssGetSFcnParam(S,BPRGREENARG));

if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes bprgreen_mat m  n  %d %d\n",m,n);
	}



   pfind_mat_in = mxGetPr(ssGetSFcnParam(S,PFINDARG));
   m = mxGetM(ssGetSFcnParam(S,PFINDARG));
   n = mxGetN(ssGetSFcnParam(S,PFINDARG));

if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes pfind_mat m  n  %d %d\n",m,n);
   }

   pmj_mat_in = mxGetPr(ssGetSFcnParam(S,PMJARG));
   m = mxGetM(ssGetSFcnParam(S,PMJARG));
   n = mxGetN(ssGetSFcnParam(S,PMJARG));

if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes pmj_mat m  n  %d %d\n",m,n);
   }

   pfc_mat_in = mxGetPr(ssGetSFcnParam(S,PFCARG));
   m = mxGetM(ssGetSFcnParam(S,PFCARG));
   n = mxGetN(ssGetSFcnParam(S,PFCARG));

if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes pfc_mat m  n  %d %d\n",m,n);
   }


   pfres_mat_in = mxGetPr(ssGetSFcnParam(S,PFRESARG));

   rcam_mat_in = mxGetPr(ssGetSFcnParam(S,RCAMARG));

   xu_mat_in = mxGetPr(ssGetSFcnParam(S,XUARG));

   yu_mat_in = mxGetPr(ssGetSFcnParam(S,YUARG));



   pfgreen_mat_in = mxGetPr(ssGetSFcnParam(S,PFGREENARG));

   m = mxGetM(ssGetSFcnParam(S,PFGREENARG));

   n = mxGetN(ssGetSFcnParam(S,PFGREENARG));

   if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes pfgreen_mat m  n  %d %d\n",m,n);
   }


   vesgreen_mat_in = mxGetPr(ssGetSFcnParam(S,VESGREENARG));

   m = mxGetM(ssGetSFcnParam(S,VESGREENARG));

   n = mxGetN(ssGetSFcnParam(S,VESGREENARG));

   if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes vesgreen_mat m  n  %d %d\n",m,n);
   }


   pfprobe_mat_in = mxGetPr(ssGetSFcnParam(S,PFPROBEARG));

   m = mxGetM(ssGetSFcnParam(S,PFPROBEARG));

   n = mxGetN(ssGetSFcnParam(S,PFPROBEARG));

   if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes pfprobe_mat m  n  %d %d\n",m,n);
   }
   vesprobe_mat_in = mxGetPr(ssGetSFcnParam(S,VESPROBEARG));

   m = mxGetM(ssGetSFcnParam(S,VESPROBEARG));

   n = mxGetN(ssGetSFcnParam(S,VESPROBEARG));

   

   if(key_mat[3]==1) {
   mexPrintf("mdlInitializeSizes vesprobe_mat m  n  %d %d\n",m,n);
   }


/*

The routine mdlCheckParameters doesn't run until after here, so we need

to get sizes - correct or not here. 

*/

   m = mxGetM(ssGetSFcnParam(S,XUARG));

   n = mxGetN(ssGetSFcnParam(S,XUARG));

   if(m>n)

      ke_mat = m;

   else

      ke_mat = n;

/*

   npf_mat = mxGetN(ssGetSFcnParam(S,FLUXARRARG));

   ncam_mat = mxGetN(ssGetSFcnParam(S,VESARRARG));

   kloop_mat = mxGetN(ssGetSFcnParam(S,PSLGREENARG));

   kprobe_mat = mxGetN(ssGetSFcnParam(S,BPRGREENARG));

*/



   ssSetNumContStates (S, 0);		/* number of continuous states */

   ssSetNumDiscStates (S, 0);		/* number of discrete states */

   if(!ssSetNumInputPorts(S,NINPUTS)) return;



   ssSetInputPortWidth (S, 0, n_port1);	

   ssSetInputPortDirectFeedThrough (S,0,1);	/* it was (S,0,0) */



   ssSetInputPortWidth (S, 1, n_port2);	

   ssSetInputPortDirectFeedThrough (S,1,1);



   /* ssSetInputPortWidth (S, 2, n_port3);	*/

   ssSetInputPortWidth (S, 2, npf_mat);	

   ssSetInputPortDirectFeedThrough (S,2,1); /* it was (S,2,0) */

   /*   ssSetInputPortWidth (S, 3, n_port4);	*/

   ssSetInputPortWidth (S, 3, n_inp_prof);	

   ssSetInputPortDirectFeedThrough (S,3,1); /* it was (S,3,0) */

   ssSetInputPortWidth (S, 4, n_aux_prof);	

   ssSetInputPortDirectFeedThrough (S,4,1); /* it was (S,4,0) */




   if(!ssSetNumOutputPorts(S,NOUTPUTS)) return;

   ssSetOutputPortWidth(S,0,npf_mat);		/* d_pf_mat */

   ssSetOutputPortWidth(S,1,ncam_mat);		/* d_tcam_mat */

   ssSetOutputPortWidth(S,2,kloop_mat);		/* pl_loop_mat */

   ssSetOutputPortWidth(S,3,kprobe_mat);	/* pl_probe_mat */

/*   ssSetOutputPortWidth(S,4,npf_mat);		*/

   ssSetOutputPortWidth(S,4,n_port4);		

   ssSetOutputPortWidth(S,5,nprof_mat);		/* kinetics */

   ssSetOutputPortWidth(S,6,N_SHAPE_OUT);	/* shape_out */

   ssSetOutputPortWidth(S,7,N_BOUND_OUT);	/* shape_bound */

/*   ssSetOutputPortWidth(S,8,N_SURF_OUT); */ 

   ssSetOutputPortWidth(S,8,n_surf);	/* SURFACES */

   ssSetOutputPortWidth(S,9,n_surf_psi);  /* psi */

   ssSetOutputPortWidth(S,10,n_surf_cur);  /* currents */

   ssSetOutputPortWidth(S,11,n_polar_cur);  /* polar currents */



/*   ssSetNumSampleTimes (S, PORT_BASED_SAMPLE_TIMES); */



/*	ssSetNumDWork (S, 11); */ 

    ssSetNumDWork (S, 12); 

   
    ssSetDWorkWidth(     S, 0, npf_mat);

    ssSetDWorkDataType(  S, 0, SS_DOUBLE);

    ssSetDWorkWidth(     S, 1, ncam_mat);

    ssSetDWorkDataType(  S, 1, SS_DOUBLE);

    ssSetDWorkWidth(     S, 2, kloop_mat);

    ssSetDWorkDataType(  S, 2, SS_DOUBLE);

    ssSetDWorkWidth(     S, 3, kprobe_mat);

    ssSetDWorkDataType(  S, 3, SS_DOUBLE); 

    ssSetDWorkWidth(     S, 4, npf_mat);

    ssSetDWorkDataType(  S, 4, SS_DOUBLE); 

    ssSetDWorkWidth(     S, 5, nprof_mat);

    ssSetDWorkDataType(  S, 5, SS_DOUBLE); 

    ssSetDWorkWidth(     S, 6, N_SHAPE_OUT);

    ssSetDWorkDataType(  S, 6, SS_DOUBLE); 

    ssSetDWorkWidth(     S, 7, N_BOUND_OUT);

    ssSetDWorkDataType(  S, 7, SS_DOUBLE); 

/*    ssSetDWorkWidth(     S, 8, N_SURF_OUT); */

    ssSetDWorkWidth(     S, 8, n_surf);

    ssSetDWorkDataType(  S, 8, SS_DOUBLE); 

    ssSetDWorkWidth(     S, 9, n_surf_psi);
    ssSetDWorkDataType(  S, 9, SS_DOUBLE); 

    ssSetDWorkWidth(     S, 10, n_surf_cur);
    ssSetDWorkDataType(  S, 10, SS_DOUBLE); 

    ssSetDWorkWidth(     S, 11, n_polar_cur);
    ssSetDWorkDataType(  S, 11, SS_DOUBLE); 



/*------------- to allocate memory for mdlUpdate ---- */

/*

    ssSetDWorkWidth(     S, 8, ssGetInputPortWidth(S,0));

    ssSetDWorkDataType(  S, 8, SS_DOUBLE); 

    ssSetDWorkWidth(     S, 9, ssGetInputPortWidth(S,1));

    ssSetDWorkDataType(  S, 9, SS_DOUBLE); 

    ssSetDWorkWidth(     S, 10, ssGetInputPortWidth(S,2));

    ssSetDWorkDataType(  S, 10, SS_DOUBLE); 

*/	



   ssSetNumRWork (S, 0);			/* size of real work array */

   ssSetNumIWork(S, 0);      /* number of integer work vector elements */

   ssSetNumPWork(S, 0);

   ssSetNumModes(S, 0);

   ssSetNumNonsampledZCs(S, 0);



/*

   for(i=0; i<NINPUTS; ++i)

   {

      ssSetInputPortSampleTime(S, i, ts);

      ssSetInputPortOffsetTime(S, i, 0.0);

   }

   for(i=0; i<NOUTPUTS; ++i)

   {

      ssSetOutputPortSampleTime(S, i, ts);

      ssSetOutputPortOffsetTime(S, i, 0.0);

   }



*/



#if 0

/* 

Allocate space for arrays.  The work array should be used if there were

any chance of this S-function being used multiple times.  Otherwise, it 

doesn't really buy you anything.  The reason we cannot simply use the pointers

as brought in from simulink in all cases is because the FORTRAN code expects

fixed first dimension arrays.  The arrays fluxarr_mat,vesarr_mat,

pslgreen_mat, and bprgreen_mat could be used as is because the first dimension 

must be the fixed value = NWNH, and matlab stores its arrays column first as 

FORTRAN does.

*/



fluxarr_mat = malloc(NWNH*npf_mat*sizeof(double)); 

copymat(fluxarr_mat_in, NWNH, npf_mat, fluxarr_mat, NWNH, KF_MAT);



vesarr_mat = malloc(NWNH*ncam_mat*sizeof(double)); 

copymat(vesarr_mat_in, NWNH, ncam_mat, vesarr_mat, NWNH, MU_MAT);



rcam_mat = malloc(ncam_mat*sizeof(double)); 

copymat(rcam_mat_in, ncam_mat, 1, rcam_mat, MU_MAT, 1);



xu_mat = malloc(ke_mat*sizeof(double)); 

copymat(xu_mat_in, ke_mat, 1, xu_mat, MU_L_MAT, 1);



yu_mat = malloc(ke_mat*sizeof(double)); 

copymat(yu_mat_in, ke_mat, 1, yu_mat, MU_L_MAT, 1);



pfres_mat = malloc(npf_mat*sizeof(double)); 

copymat(pfres_mat_in, npf_mat, 1,  pfres_mat, KF_MAT, 1);







pfc_mat = malloc(MU_MAT*npf_mat*sizeof(double));

copymat(pfc_mat_in, ncam_mat, npf_mat, pfc_mat, MU_MAT, KF_MAT);



pmj_mat = malloc(MU_MAT*ncam_mat*sizeof(double)); 

copymat(pmj_mat_in, ncam_mat, ncam_mat, pmj_mat, MU_MAT, MU_MAT);



pfind_mat = malloc(KF_MAT*npf_mat*sizeof(double)); 

copymat(pfind_mat_in, npf_mat, npf_mat, pfind_mat, KF_MAT, KF_MAT);



bprgreen_mat = malloc(NWNH*kprobe_mat*sizeof(double)); 

copymat(bprgreen_mat_in, NWNH, kprobe_mat, bprgreen_mat, NWNH, NPROBE_MAT);



pslgreen_mat = malloc(NWNH*kloop_mat*sizeof(double));

copymat(pslgreen_mat_in, NWNH, kloop_mat, pslgreen_mat, NWNH, NLOOP_MAT);

#endif



fluxarr_mat = fluxarr_mat_in;

vesarr_mat = vesarr_mat_in;

rcam_mat = rcam_mat_in;

xu_mat = xu_mat_in;

yu_mat = yu_mat_in;

pfres_mat = pfres_mat_in;





   pfc_mat = malloc(MU_MAT*npf_mat*sizeof(double));

   copymat(pfc_mat_in, ncam_mat, npf_mat, pfc_mat, MU_MAT, KF_MAT);



   pmj_mat = malloc(MU_MAT*ncam_mat*sizeof(double)); 

   copymat(pmj_mat_in, ncam_mat, ncam_mat, pmj_mat, MU_MAT, MU_MAT);



   pfind_mat = malloc(KF_MAT*npf_mat*sizeof(double)); 

   copymat(pfind_mat_in, npf_mat, npf_mat, pfind_mat, KF_MAT, KF_MAT);




/*
pfc_mat = pfc_mat_in;

pmj_mat = pmj_mat_in;

pfind_mat = pfind_mat_in;

*/

bprgreen_mat = bprgreen_mat_in;

pslgreen_mat = pslgreen_mat_in;



pfgreen_mat = pfgreen_mat_in;

vesgreen_mat = vesgreen_mat_in;

pfprobe_mat = pfprobe_mat_in;

vesprobe_mat = vesprobe_mat_in;



}



/* #define MDL_SET_INPUT_PORT_SAMPLE_TIME */



#if defined(MDL_SET_INPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)

/* Function: mdlSetInputPortSampleTime =========================================

 * Abstract:

 *	When asked by Simulink, set the sample time of the enable or

 *	signal port. If we know both sample times, also set the output

 *	port sample times.

 */

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



} /* end mdlSetInputPortSampleTime */

#endif







/* e#define MDL_SET_OUTPUT_PORT_SAMPLE_TIME */



#if defined(MDL_SET_OUTPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)

/* Function: mdlSetOutputPortSampleTime ========================================

 * Abstract:

 *	When asked by Simulink, set the sample time of the specified output

 *	port. This occurs when back propagating sample times (see sfuntmpl.doc).

 *

 */

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



} /* end mdlSetOutputPortSampleTime */

#endif



/*

* mdlInitializeSampleTimes - initialize the sample times array

*

* This function is used to specify the sample time(s) for your S-function.

* If your S-function is continuous, you must specify a sample time of 0.0.

* Sample times must be registered in ascending order.

*/



static void mdlInitializeSampleTimes(S)

SimStruct *S;

{



    const char_T *bpath = ssGetPath(S);

    int_T        i;



    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME); 

/*    ssSetSampleTime(S, 0, 0.0001); */

    ssSetOffsetTime(S, 0, 0.0); 



/*    for (i = 0; i < NINPUTS; i++) {

        mexPrintf("%s input port %d sample time = [%g, %g]\n", bpath, i,

                  ssGetInputPortSampleTime(S,i),

                  ssGetInputPortOffsetTime(S,i));



    }

*/

/*    for (i = 0; i < NOUTPUTS; i++) {

        mexPrintf("%s output port %d sample time = [%g, %g]\n", bpath, i,

                  ssGetOutputPortSampleTime(S,i),

                  ssGetOutputPortOffsetTime(S,i));

    }

*/



}



/* Function to set initial conditions */

#define MDL_INITIALIZE_CONDITIONS

#ifdef MDL_INITIALIZE_CONDITIONS  

static void mdlInitializeConditions(S)

SimStruct *S;

{

/*   int k; */



   InputRealPtrsType uPtrs1 = ssGetInputPortRealSignalPtrs(S,0);

   InputRealPtrsType uPtrs2 = ssGetInputPortRealSignalPtrs(S,1);

   InputRealPtrsType uPtrs3 = ssGetInputPortRealSignalPtrs(S,2);

   InputRealPtrsType uPtrs4 = ssGetInputPortRealSignalPtrs(S,3);

   InputRealPtrsType uPtrs5 = ssGetInputPortRealSignalPtrs(S,4);


   int k, maxk;



   real_T *d_pf_mat = (real_T *)ssGetOutputPortRealSignal(S,0);

   real_T *d_tcam_mat = (real_T *)ssGetOutputPortRealSignal(S,1);

   real_T *pl_loop_mat = (real_T *)ssGetOutputPortRealSignal(S,2);

   real_T *pl_probe_mat = (real_T *)ssGetOutputPortRealSignal(S,3);

   real_T *pl_pf_mat = (real_T *)ssGetOutputPortRealSignal(S,4);

   real_T *pl_ves_mat = (real_T *)ssGetOutputPortRealSignal(S,5);

   real_T *shape_out = (real_T *)ssGetOutputPortRealSignal(S,6);

   real_T *contvals_mat = (real_T *)ssGetOutputPortRealSignal(S,7);

   real_T *surf_mat = (real_T *)ssGetOutputPortRealSignal(S,8);

   real_T *surf_psi = (real_T *)ssGetOutputPortRealSignal(S,9);

   real_T *surf_cur = (real_T *)ssGetOutputPortRealSignal(S,10);

   real_T *polar_cur = (real_T *)ssGetOutputPortRealSignal(S,11);


    double *c_0 = (double *) ssGetDWork(S, 0);

    double *c_1 = (double *) ssGetDWork(S, 1);

    double *c_2 = (double *) ssGetDWork(S, 2);

    double *c_3 = (double *) ssGetDWork(S, 3);

    double *c_4 = (double *) ssGetDWork(S, 4);

    double *c_5 = (double *) ssGetDWork(S, 5);

    double *c_6 = (double *) ssGetDWork(S, 6);

    double *c_7 = (double *) ssGetDWork(S, 7);

    double *c_8 = (double *) ssGetDWork(S, 8);

    double *c_9 = (double *) ssGetDWork(S, 9);

    double *c_10 = (double *) ssGetDWork(S, 10);

    double *c_11 = (double *) ssGetDWork(S, 11);



       double *pf_mat, *tcam_mat, *contpts_mat, *c_prof_mat;  

       double *ech_data;  
       double *aux_prof;


/*
	double *pf_mat		=	(double *)ssGetDWork(S,8);	

	double *tcam_mat	=	(double *)ssGetDWork(S,9);	

	double *contpts_mat	=	(double *)ssGetDWork(S,10);	

*/

	

	int k_out_dina;

	real_T t,dt;





   if(key_mat[3]==3) {
   mexPrintf("before tran_to_dina\n");
   }




   tran_to_dina_(&ncam_mat,&npf_mat,&kloop_mat,&kprobe_mat,

		&z_l,&z_r,&r_l,&r_r, &kf_mat,&mu_mat,

		fluxarr_mat,vesarr_mat, pslgreen_mat,bprgreen_mat,

		pfind_mat,pmj_mat,pfc_mat, pfres_mat,rcam_mat,

		xu_mat,yu_mat,&ke_mat,key_mat,

        pfgreen_mat,vesgreen_mat,pfprobe_mat,

        vesprobe_mat);



   if(key_mat[3]==3) {
   mexPrintf("after tran_to_dina\n");
   }


   for (k=0; k < 30; k++) { 

   vec_mat[k]	= vec_mat_in[k];

   }

   
   if(key_mat[3]==1) {
   mexPrintf("mdl vec_mat_in %g %g %g %g %g \n",

   vec_mat_in[0],vec_mat_in[1],vec_mat_in[2],vec_mat_in[3],vec_mat_in[4]);
   }


   if(key_mat[3]==1) {
   mexPrintf("mdl vec_mat %g %g %g %g %g \n",

   vec_mat[5],vec_mat[6],vec_mat[7],vec_mat[8],vec_mat[9]);
   }


   if(key_mat[3]==1) {
   mexPrintf("mdl vec_mat %g %g %g %g %g \n",

   vec_mat[10],vec_mat[11],vec_mat[12],vec_mat[13],vec_mat[14]);
   }


   if(key_mat[3]==1) {
   mexPrintf("mdl vec_mat %g %g %g %g %g \n",

   vec_mat[15],vec_mat[16],vec_mat[17],vec_mat[18],vec_mat[19]);
   }

   if(key_mat[3]==1) {
   mexPrintf("mdl vec_mat %g %g %g %g %g %g \n",

   vec_mat[20],vec_mat[21],vec_mat[22],vec_mat[23],vec_mat[24],vec_mat[25]);
   }

   min_dt = vec_mat_in[9];

   if(vec_mat_in[10]==0.0)

      max_dt = 5e-3;

   else

      max_dt = vec_mat_in[10];





   pf_mat = (double *)&(U1(0)); 

   tcam_mat = (double *)&(U2(0));

   contpts_mat = (double *)&(U3(0));

   c_prof_mat = (double *)&(U4(0));

   aux_prof = (double *)&(U5(0));



/*

   for (k=0; k<ssGetDWorkWidth(S,8); k++) { 

   pf_mat[k] = (double)(*uPtrs1[k]); 

   }



   for (k=0; k<ssGetDWorkWidth(S,9); k++) { 

   tcam_mat[k] = (double)(*uPtrs2[k]); 

   }



   for (k=0; k<ssGetDWorkWidth(S,10); k++) { 

   contpts_mat[k] = (double)(*uPtrs3[k]); 

   }


*/


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


/*
	vec_mat[10]=min_dt;
*/

	vec_mat[17]=t;


   if(key_mat[3]==1) {
mexPrintf("mdlInitializeConditions t=%g min_dt=%g max_dt=%g\n",t,min_dt,max_dt);
   }


   if(key_mat[3]==1) {
   mexPrintf("mdlInitialize before dina\n");
   }


 


   if(key_mat[3]==1) {
   mexPrintf(" pf_mat0 %g %g %g %g %g \n",

   pf_mat0[0],pf_mat0[1],pf_mat0[2],pf_mat0[3],pf_mat0[4]);

   }

   if(key_mat[3]==1) {

   mexPrintf(" tcam_mat0 %g %g %g %g %g \n",

   tcam_mat0[0],tcam_mat0[1],tcam_mat0[2],tcam_mat0[3],tcam_mat0[4]);


   mexPrintf(" bp_exp_mat %g %g \n",
   bp_exp_mat[0],bp_exp_mat[1]);

   mexPrintf(" ps_exp_mat %g %g \n",
   ps_exp_mat[0],ps_exp_mat[1]);

   mexPrintf(" pf_exp_mat %g %g \n",
   pf_exp_mat[0],pf_exp_mat[1]);

   mexPrintf(" indpf_mat %g %g \n",
   indpf_mat[0],indpf_mat[1]);

   mexPrintf(" ext_transp_mat %g %g \n",
   ext_transp_mat[0],ext_transp_mat[1]);


 



   }



 /* vec_mat[15]=pf_mat[0]*1.e-19; n_e -density */ 
 vec_mat[15]=pf_mat[0];   /* n_e -density */

  mexPrintf(" Density %g \n",
   vec_mat[15]);


    if(key_mat[3]==1) {

  mexPrintf(" vec_mat %g \n",
   vec_mat[15]);


  mexPrintf(" pf_mat %g %g %g \n",
   pf_mat[0],pf_mat[1],pf_mat[2]);

mexPrintf(" aux_prof_mat %g %g %g \n",
   aux_prof[0],aux_prof[1],aux_prof[2]);

	}

/*
    dina_(key_mat,vec_mat, pf_mat0,tcam_mat0,d_pf_mat,d_tcam_mat,

	pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat,shape_out,&k_out_dina,

	  contpts_mat,contvals_mat,npts_mat,tcam_mat,

	  bp_exp_mat,ps_exp_mat,pf_exp_mat,indpf_mat,ext_transp_mat,

         c_prof_mat,aux_heat,aux_prof,surf_mat,surf_psi,surf_cur,
	  polar_cur);
 

*/



   for (k=0; k<ssGetDWorkWidth(S,0); k++) { 

	c_0[k]=d_pf_mat[k];

   }



   for (k=0; k<ssGetDWorkWidth(S,1); k++) { 

	c_1[k]=d_tcam_mat[k];

   }



   for (k=0; k<ssGetDWorkWidth(S,2); k++) { 

	c_2[k]=pl_loop_mat[k];

   }



   for (k=0; k<ssGetDWorkWidth(S,3); k++) { 

	c_3[k]=pl_probe_mat[k];

   }



   for (k=0; k<ssGetDWorkWidth(S,4); k++) { 

	c_4[k]=pl_pf_mat[k];

   }



   for (k=0; k<ssGetDWorkWidth(S,5); k++) { 

	c_5[k]=pl_ves_mat[k];

   }



   for (k=0; k<ssGetDWorkWidth(S,6); k++) { 

	c_6[k]=shape_out[k];

	if(k==1&& key_mat[3]==1)mexPrintf(" -mdlInit RMAG=%g\n",c_6[1]); 

	if(k==2&& key_mat[3]==1)mexPrintf(" -mdlInit ZMAG=%g\n",c_6[2]); 

 

   }



   for (k=0; k<ssGetDWorkWidth(S,7); k++) { 

	c_7[k]=contvals_mat[k];

   }


   for (k=0; k<ssGetDWorkWidth(S,8); k++) { 

	c_8[k]=surf_mat[k];

   }

   for (k=0; k< ssGetDWorkWidth(S,9); k++) { 

	c_9[k]=surf_psi[k];

   }

   for (k=0; k< ssGetDWorkWidth(S,10); k++) { 

	c_10[k]=surf_cur[k];

   }

   for (k=0; k< ssGetDWorkWidth(S,11); k++) { 

	c_11[k]=polar_cur[k];

   }




}

#endif   /* MDL_INITIALIZE_CONDITIONS */  



/* Function to compute outputs */



#define MDL_UPDATE
static void mdlUpdate(SimStruct *S, int_T tid)
{
}

static void mdlOutputs (SimStruct *S, int_T tid)  


{
   InputRealPtrsType uPtrs1 = ssGetInputPortRealSignalPtrs(S,0);

   InputRealPtrsType uPtrs2 = ssGetInputPortRealSignalPtrs(S,1);

   InputRealPtrsType uPtrs3 = ssGetInputPortRealSignalPtrs(S,2);

   InputRealPtrsType uPtrs4 = ssGetInputPortRealSignalPtrs(S,3);

   InputRealPtrsType uPtrs5 = ssGetInputPortRealSignalPtrs(S,4);


	int k, maxk;



   real_T *d_pf_mat = (real_T *)ssGetOutputPortRealSignal(S,0);

   real_T *d_tcam_mat = (real_T *)ssGetOutputPortRealSignal(S,1);

   real_T *pl_loop_mat = (real_T *)ssGetOutputPortRealSignal(S,2);

   real_T *pl_probe_mat = (real_T *)ssGetOutputPortRealSignal(S,3);

   real_T *pl_pf_mat = (real_T *)ssGetOutputPortRealSignal(S,4);

   real_T *pl_ves_mat = (real_T *)ssGetOutputPortRealSignal(S,5);

   real_T *shape_out = (real_T *)ssGetOutputPortRealSignal(S,6);

   real_T *contvals_mat = (real_T *)ssGetOutputPortRealSignal(S,7);

   real_T *surf_mat = (real_T *)ssGetOutputPortRealSignal(S,8);

   real_T *surf_psi = (real_T *)ssGetOutputPortRealSignal(S,9);

   real_T *surf_cur = (real_T *)ssGetOutputPortRealSignal(S,10);

   real_T *polar_cur = (real_T *)ssGetOutputPortRealSignal(S,11);


   double *pf_mat, *tcam_mat, *contpts_mat, *c_prof_mat, *aux_prof; 

   int k_out_dina;

   real_T t,dt;



#ifdef DEBUG

fprintf(stderr,"entering mdlOutputs\n");

#endif



   pf_mat = (double *)&(U1(0)); 

   tcam_mat = (double *)&(U2(0));

   contpts_mat = (double *)&(U3(0));

   c_prof_mat = (double *)&(U4(0));

   aux_prof = (double *)&(U5(0));



#if 0

fprintf(stderr,"tlast = %g\n",tlast);

#endif



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

/*
	vec_mat[10]=min_dt;
*/



	vec_mat[17]=t;



   if(key_mat[3]==-100) {
fprintf(stderr,"before dina\n");
   }
/*        mexPrintf("before DINA vec_mat[9]===%g\n",vec_mat[9]); */

/*mexPrintf("before DINA t=%g min_dt=%g max_dt=%g\n",t,min_dt,max_dt); */




 vec_mat[15]=pf_mat[0]; /* n_e -density */
 vec_mat[18]=pf_mat[1]; /* anom_res */

   mexPrintf(" Density %g \n",
   vec_mat[15]);



/* vec_mat[8]=pf_mat[2]; */ 
 
/* pf_mat[3] is ppr(1) */
/* vec_mat[0]=pf_mat[4]; */
/* vec_mat[1]=pf_mat[5]; */
/* pf_mat[6] is ppr(4) */
 
/* pf_mat[7] is ttpr(1) */
/* vec_mat[2]=pf_mat[8]; */ 
/* vec_mat[3]=pf_mat[9]; */ 
/* pf_mat[10] is ttpr(4) */

 vec_mat[19]=pf_mat[11]; 

 vec_mat[20]=pf_mat[12]; 

 vec_mat[21]=pf_mat[13]; 

 vec_mat[22]=pf_mat[2]; /* ratio_n */


   for (k=0; k< 6; k++) { 

	aux_heat[k]=pf_mat[k+3];

/*mexPrintf(" aux_heat %g   \n",aux_heat[k]);*/

   }




   if(key_mat[3]==1) {
mexPrintf("before DINA t=%g dt=%g min_dt=%g max_dt%g\n",vec_mat[17],

		  vec_mat[9],vec_mat[10],max_dt);

/*mexPrintf("anom_e=%g \n",vec_mat[20]);*/


mexPrintf("density n=%g zeff =%g \n",vec_mat[15],vec_mat[18]);


mexPrintf(" pf_mat %g  %g  %g \n",pf_mat[0],

		  pf_mat[1],pf_mat[2]);

mexPrintf(" contpts_mat %g  %g  %g  %g\n",contpts_mat[0],

		  contpts_mat[1],contpts_mat[2],contpts_mat[3]);

   }

#if 0

fprintf(stderr,"t = %g, dt = %g\n",t,dt);



fprintf(stderr,"pf_mat = ");

for(k=0; k<20; ++k) fprintf(stderr,"%f ",pf_mat[k]);

fprintf(stderr,"\n ");

#endif

fflush(stderr);



   if(key_mat[3]==1) {


  mexPrintf(" pf_mat %g %g %g \n",
   pf_mat[0],pf_mat[1],pf_mat[2]);

mexPrintf(" aux_prof_mat %g %g %g \n",
   aux_prof[0],aux_prof[1],aux_prof[2]);

   }











   dina_(key_mat,vec_mat, pf_mat0,tcam_mat0,d_pf_mat,d_tcam_mat,

	pl_loop_mat,pl_probe_mat,pl_pf_mat,pl_ves_mat,shape_out,&k_out_dina,

	 contpts_mat,contvals_mat,&npts_mat,tcam_mat,


         bp_exp_mat,ps_exp_mat,pf_exp_mat,indpf_mat,ext_transp_mat,

         c_prof_mat,aux_heat,aux_prof,surf_mat,surf_psi,surf_cur,
         polar_cur);


   /*fprintf(stderr," sh_mat %g %g %g %g   \n",

     shape_out[1],shape_out[5],shape_out[21],shape_out[85]); */

/*   mexPrintf("MDL Update \n");
*/

   if(key_mat[3]==-100) {
fprintf(stderr,"---------after dina\n");
   }


#if 0

fprintf(stderr,"time = %f\n",ssGetT(S));

fprintf(stderr,"d_pf_mat = ");

for(k=0; k<20; ++k) fprintf(stderr,"%f ",d_pf_mat[k]);

fprintf(stderr,"\n ");

#endif

fflush(stderr);



#ifdef DEBUG

fprintf(stderr,"exiting mdlOutputs\n");

#endif





}



/*

* mdlDerivatives - compute the derivatives

*

* In this function, you compute the S-function block's derivatives.

* The derivatives are placed in the dx variable.

*/



static void mdlDerivatives(S)

SimStruct *S;

{

}



/*

* mdlTerminate - called when the simulation is terminated.

*

* In this function, you should perform any actions that are necessary

* at the termination of a simulation.  For example, if memory was allocated

* in mdlInitializeConditions, this is the place to free it.

*/



static void mdlTerminate(SimStruct *S)

{

}



#ifdef MATLAB_MEX_FILE                  /* Compiled as MEX-file?*/

#include "simulink.c"                   /* Mex file interface */

#else

#include "cg_sfun.h"                    /* Code generation registration */

#endif



