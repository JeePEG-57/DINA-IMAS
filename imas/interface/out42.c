#include <stdio.h>
void out42_(int *ng,double ygr[],int *num,char name[])
 
{ 

float t;
int i,kn;
char uname[30];


for (i=0;i< *num; i++){

printf ("%c",name[i]); 
}


printf ("  "); 

/* return; */

kn=*ng;

for (i=0;i< kn; i++){
t=ygr[i];

 printf ("%g  ",t); 
}
 printf ("\n"); 
}


