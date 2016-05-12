#include "mex.h"

//Definition of the class structures in file UALClasses.h
#include "UALClasses.h"

void timestwo(double y[], double x[])
{
  y[0] = 2.0*x[0];
}

void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
  double *x,*y;
  size_t mrows,ncols;
  
  /* Check for proper number of arguments. */
  if(nrhs!=1) {
    mexErrMsgIdAndTxt( "MATLAB:timestwo:invalidNumInputs",
            "One input required.");
  } else if(nlhs>1) {
    mexErrMsgIdAndTxt( "MATLAB:timestwo:maxlhs",
            "Too many output arguments.");
  }
  
  /* The input must be a noncomplex scalar double.*/
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
  if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
      !(mrows==1 && ncols==1) ) {
    mexErrMsgIdAndTxt( "MATLAB:timestwo:inputNotRealScalarDouble",
            "Input must be a noncomplex scalar double.");
  }
  
  /* Create matrix for the return argument. */
  plhs[0] = mxCreateDoubleMatrix((mwSize)mrows, (mwSize)ncols, mxREAL);
  
  /* Assign pointers to each input and output. */
  x = mxGetPr(prhs[0]);
  y = mxGetPr(plhs[0]);
  
  /* Call the timestwo subroutine. */
  timestwo(y,x);
} 


using namespace IdsNs;
int main(int argc, char *argv[])
{
   float time=10;
   int icoil,i, shot, number=1;
   char dum[23];
   int interp = 2;

   IdsNs::IDS *II,*JJ;
   II = new IDS();
   if(argc != 4) {
    printf("usage : test_getslice_pf_active num_shot, time, interp\n");
    exit(1);
   }
   shot = atoi(argv[1]);
   time = atof(argv[2]);
   interp = atoi(argv[3]);

   IdsNs::IDS ids1(shot,1,shot,0);
   ids1.open(); //Open the database

   ids1._pf_active.getSlice(time, interp);

   printf("coil1,2  name:%s,  %s\n",ids1._pf_active.coil(0).name.c_str(),ids1._pf_active.coil(1).name.c_str());
   cout << "pf_activeSYSTEMS at time " << time << "\n" << ids1._pf_active;

   printf("\n\n======   Shot %d   ===============\nAt time %g  with interp = %d\n",shot, time, interp);

   for (icoil=0; icoil< ids1._pf_active.coil.extent(0);icoil++) {
     printf("coil(%d).current.data:", icoil);
     for (int i=0;i<ids1._pf_active.coil(icoil).current.data.extent(0);i++) 
       printf("%g ",  ids1._pf_active.coil(icoil).current.data(i));
       puts(" ");
      printf("coil(%d).current.time: ",icoil);
     for (int i=0;i< ids1._pf_active.coil(icoil).current.time.extent(0);i++) 
       printf("%g ",  ids1._pf_active.coil(icoil).current.time(i)) ;
       puts(" ");
   puts("======");
   }
   ids1.close();
}
