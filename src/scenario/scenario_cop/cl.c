#include <time.h>
#include <stdio.h>

double c_time__()
/*main()*/

{
  clock_t t0,t1;
  double tt;
    
/*    t0=clock(); */
  t1=clock();
  /*  tt=(float)(t1)/CLK_TCK; */
  tt=(float)(t1)/CLOCKS_PER_SEC;
/*  printf(" time in %.2f secs.\n",tt);*/
  
  return tt;
}


