#include <stdio.h>
#ifdef   MATLAB_MEX_FILE
#include "mex.h"
#endif
#if defined (_MSC_VER)

#define out42_ out42

#endif


OUT42(ng,ygr,num,name)

int *num,*ng;

/*float ygr[];*/
double ygr[];

char name[];
 
{ 

float t;
int i,kn;
char uname[30];


for (i=0;i< *num; i++){

mexPrintf("%c",name[i]); 
}


mexPrintf("  "); 

/* return; */

kn=*ng;

for (i=0;i< kn; i++){
t=ygr[i];


mexPrintf ("%g  ",t); 
/* mexPrintf ("%14.7e  ",t); */
}
mexPrintf ("\n"); 
}


#include <stdio.h>
#if defined (_MSC_VER)

#define pau_ PAU

#endif

pau_()
 
{ 

char uname;

mexPrintf (" PAUSE \n"); 
  mexCallMATLAB(0, NULL, 0, NULL, "pause");
uname= getchar();


}

