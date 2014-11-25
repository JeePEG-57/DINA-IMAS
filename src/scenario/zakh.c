#include <string.h>
#include <math.h>
#include <stdio.h>

u_choice(xmin,imin,xmax,imax,unitx)
double*xmin,*xmax,*unitx;
int*imin,*imax;
{
double s,u;
int i,j,k;
if(*xmax==*xmin){
if(*xmax>0.)*xmin= 0.;
else if(*xmax==0.)*xmax= 1.;
else*xmax= 0.;
}
u= *xmax-*xmin;
s= log10(u);
i= s;
if(s<0.)i--;
u= pow(10.,(double)i);
s= (*xmax-*xmin)/u;
if(s>1.2){
if(s>2.5){
if(s>5.)u*= 2.;
}
else u*= 0.5;
}
else u*= 0.2;
*unitx= u;
s= (*xmin)/u+1.e-6;
if((*xmin)>0){
j= (int)s;
i= j+1;
}
else{
i= (int)s;j= i-1;
}
s-= j;
if(s<0.25){
*xmin= j*u;*imin= j;
}
else{
*imin= i;
if(s<0.5)*xmin= (j+0.25)*u;
else if(s<0.75)*xmin= (j+0.5)*u;
else if(s<1)*xmin= (j+0.75)*u;
}
s= (*xmax)/u-1.e-6;
if((*xmax)>0){
j= (int)s;i= j+1;
}
else{
i= (int)s;
j= i-1;
}
s= i-s;
if(s<0.25){
*xmax= i*u;
*imax= i;
}
else{
*imax= j;
if(s<0.5)*xmax= (j+0.75)*u;
else if(s<0.75)*xmax= (j+0.5)*u;
else if(s<1)*xmax= (j+0.25)*u;
}
}
