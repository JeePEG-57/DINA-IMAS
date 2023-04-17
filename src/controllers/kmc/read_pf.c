#include <stdio.h>
#define nmax 9997
#define kf 15
#define mexPrintf printf

//extern FILE *f2;
	FILE *f2;


/* Subroutine */ int scen_read(int i_en, int npf, int indx, int  *n, 
		double *t_val, double *tpl_val, double *pf_val)
{
    int i, j, ii, nmax1;
    char s_ncam[50];

	float ss;

	static int kmax;
	static double pf[nmax][kf];
	static double t[nmax],tpl[nmax];
	int res;
	char b[1024];




	if(i_en > 1){goto l2;}

//	mexPrintf(" i_en npf %d %d \n ",i_en,npf);

//	return;

	f2=fopen("scr_data.dat","r");

	printf("---scr_data.dat \n");

	/* read (41,*) */
/* read (41,*)ncam */
	fgets(b,1024,f2);
	sscanf(b, "%s ", &s_ncam);
	printf(" sss== %s \n  ",s_ncam);

	fgets(b,1024,f2);
	sscanf(b, "%s ", &s_ncam);
	printf(" sss== %s \n  ",s_ncam);

	fgets(b,1024,f2);
	sscanf(b, "%s ", &s_ncam);
	printf(" sss== %s \n  ",s_ncam);


	sscanf(b, "%s ", &s_ncam);

	printf(" sss== %s \n  ",s_ncam);

//	mexPrintf(" sss %s  ",s_ncam);

//	nmax1=21;
	nmax1=nmax;

	for (i = 1; i <= nmax1; ++i) {
	
		ii=feof(f2);


	//mexPrintf(" i ii %d %d \n   ",i,ii);

	if(ii != 0){goto l1;}

			
	res=fscanf(f2, "%f",&ss);

//	fgets(b,1024,f2);
//	res=sscanf(b, " %f",&ss);

//	printf(" i ii res ss %d %d %d %g\n   ",i,ii,res,ss);

	if(res != 1){goto l1;}

	kmax=i;

	t[i]=ss;

//	mexPrintf(" i res t %d %d %f ",i,res,t[i]);

	fscanf(f2, "%f",&ss);
//	res=sscanf(b, " %f",&ss);
	tpl[i]=ss;
	printf(" i t tpl  %d %f %f \n ",i,t[i],tpl[i]);
//	mexPrintf(" i t tpl  %d %f %f \n ",i,t[i],tpl[i]);
    //printf(" zc %g  ",zc[i]);
	for (j = 1; j <= npf; ++j) {
	fscanf(f2, "%f",&ss);
//	res=sscanf(b, " %f",&ss);
	pf[i][j]=ss;
//		mexPrintf("%f ",pf[i][j]);
     }
//		mexPrintf(" \n   ");

						 
								 }

l1:

/* close (41) */

//	mexPrintf("  i res %d %d \n   ",i,res);

	fclose(f2);


		printf("---scr_data.dat finished \n");


	//	getchar();

//	return 0;


	kmax=kmax+1;
	i=kmax;
	t[i]=10000.;
	tpl[i]=tpl[i-1];
	for (j = 1; j <= npf; ++j) {
	pf[i][j]=pf[i-1][j];}

//	goto l2;


	i=0;
	t[i]=-1.e-5;
	tpl[i]=tpl[i+1];
	for (j = 1; j <= npf; ++j) {
	pf[i][j]=pf[i+1][j];}

l2:

//	mexPrintf(" kmax= indx %d %d \n ",kmax,indx);

//	return 0;

	for (i = 0; i <= kmax; ++i) {
		t_val[i]=t[i];
		tpl_val[i]=tpl[i];
    	for (j = 1; j <= npf; ++j) {
		pf_val[j+i*npf]=pf[i][j];}
	}

//	mexPrintf("  return \n   ");
	n[0]=kmax;

//	mexPrintf("  return 2 n %d \n   ",n[0]);

    return 0;
} /* scen_read */
