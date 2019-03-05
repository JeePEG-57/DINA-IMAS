#include <stdio.h>
out42(ng,ygr,num,name)

int *num,*ng;
/*float ygr[];*/
double ygr[];

char name[];
 
{ 

float t;
int i,kn;
char uname[30];


for (i=0;i< *num; i++){

mexPrintf ("%c",name[i]); 
}


mexPrintf ("  "); 

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
PAU1()

 
{ 

char uname;

mexPrintf (" PAUSE1 \n"); 
  mexCallMATLAB(0, NULL, 0, NULL, "pause");
uname= getchar();


}
