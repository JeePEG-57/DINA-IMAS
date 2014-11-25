#include <stdio.h>
out42_(igr,ng,ygr,tgr)
int *igr,*ng;
/*float ygr[],tgr[]; */
double ygr[],tgr[]; 
{ 
FILE *outfile; 
float t;
int i,j,ki,kn,kk,kij;
ki=*igr;
kn=*ng;
j=0;
if (*igr==0) return(0);
outfile=fopen("for042","a");
kk=0;
kij=*igr*(*ng)-1;
(void) fprintf(outfile," %4d %4d\n",*igr,*ng);
for (j=0;j<*ng;j++){
for (i=0;i<*igr;i++){
t=ygr[i,j];
printf ("t=%f\n",t);
if ((kk++<5) && (i*j<kij)) fprintf(outfile,"%6e ",t);
else {
 fprintf(outfile,"%6e\n",t);
kk=0;
}
}}
/* fprintf(outfile,"\n"); */

kk=0;
for (i=0;i<*igr;i++){
t=tgr[i];
if ((kk++<5) && (i<*igr-1)) fprintf(outfile,"%6e ",t);
else {
 fprintf(outfile,"%6e\n",t);
kk=0;
}
}
(void) fclose(outfile); 
}

f2_(ygr,tgr)

float *ygr[], *tgr[]; 
{
  ygr=tgr;
}



