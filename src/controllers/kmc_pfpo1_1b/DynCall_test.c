// DynCall.c
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <float.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>



int i2;

main()
{

  // Переменная цикла
  int i00;

    double EqTime, SimStep , finaltime;

	FILE *prob1, *f;
	char b[256];

      int i,j,ii,jj,kk,kpr;
	  double tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref,c_a_tpl1_eob;
      double c_a_tpl2,c_a_tpl_min,y0,c2_y0;

i2=0;

printf("Call  main1\n");

kpr=1;

	  if( kpr == 1){
  
	  printf("---t15_2_initialize ");

f=fopen("control_data2.dat","r");
printf("---open file ");



fgets(b,255,f);
printf("%s", b);
//goto stop;

fscanf(f,"%lf",&tcont2);
	  printf("  tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref \n");
  	  printf("%g ",tcont2);

	  fscanf(f,"%lf",&Ip_div);
fscanf(f,"%lf",&ref_ramp);
fscanf(f,"%lf ",&Ip_rd);
fscanf(f,"%lf \n",&trd_ref);
	  printf("  tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref \n");
  	  printf("%g   %g   %g  %g   %g  ",tcont2,Ip_div,ref_ramp,Ip_rd,trd_ref);

fgets(b,255,f);
fscanf(f,"%lf",&c_a_tpl1_eob);
fscanf(f,"%lf",&c_a_tpl2);
fscanf(f,"%lf",&c_a_tpl_min);
fscanf(f,"%lf",&y0);
fscanf(f,"%lf",&c2_y0);

	  printf("  c_a_tpl1_eob,c_a_tpl2,c_a_tpl_min,y0,c2_y0 \n");
  	  printf("%g   %g   %g  %g %g\n ",c_a_tpl1_eob,c_a_tpl2,c_a_tpl_min,y0,c2_y0);


fclose(f);



stop:;


  }

}
