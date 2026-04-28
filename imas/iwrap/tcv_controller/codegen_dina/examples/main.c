/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 28-Apr-2026 10:26:51
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "hybctrl_step_IDS.h"
#include "hybctrl_step_IDS_terminate.h"
#include "hybctrl_step_IDS_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Declarations */
static void argInit_104x104_real_T(double result[10816]);

static void argInit_104x1_real_T(double result[104]);

static void argInit_104x26_real_T(double result[2704]);

static void argInit_19x1_boolean_T(boolean_T result[19]);

static void argInit_19x40_real_T(double result[760]);

static void argInit_1x10_char_T(char result[10]);

static void argInit_1x10_real_T(double result[10]);

static void argInit_1x13_char_T(char result[13]);

static void argInit_1x14_char_T(char result[14]);

static void argInit_1x29_cell_wrap_0(cell_wrap_0 result[29]);

static void argInit_1x5_char_T(char result[5]);

static void argInit_1x6_char_T(char result[6]);

static void argInit_1x7_char_T(char result[7]);

static void argInit_1x8_char_T(char result[8]);

static void argInit_1x9_char_T(char result[9]);

static void argInit_22x1_cell_wrap_0(cell_wrap_0 result[22]);

static void argInit_22x26x10_real_T(double result[5720]);

static void argInit_26x117_real_T(double result[3042]);

static void argInit_26x1_boolean_T(boolean_T result[26]);

static void argInit_26x1_real_T(double result[26]);

static void argInit_29x1_real_T(double result[29]);

static void argInit_38x1_real_T(double result[38]);

static void argInit_40x1_boolean_T(boolean_T result[40]);

static void argInit_78x104_real_T(double result[8112]);

static void argInit_78x26_real_T(double result[2028]);

static boolean_T argInit_boolean_T(void);

static void argInit_cell_1(cell_1 *result);

static void argInit_cell_2(cell_2 *result);

static void argInit_cell_4(cell_4 *result);

static void argInit_cell_5(cell_5 *result);

static cell_wrap_0 argInit_cell_wrap_0(void);

static char argInit_char_T(void);

static double argInit_real_T(void);

static void argInit_struct0_T(struct0_T *result);

static void argInit_struct1_T(struct1_T *result);

static void argInit_struct2_T(struct2_T *result);

static void argInit_struct3_T(struct3_T *result);

static void argInit_struct4_T(struct4_T *result);

static void argInit_struct5_T(struct5_T *result);

static void argInit_struct6_T(struct6_T *result);

static void argInit_struct7_T(struct7_T *result);

static void argInit_struct8_T(struct8_T *result);

static void main_hybctrl_step_IDS(void);

/* Function Definitions */
/*
 * Arguments    : double result[10816]
 * Return Type  : void
 */
static void argInit_104x104_real_T(double result[10816])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 104; idx0++) {
    for (idx1 = 0; idx1 < 104; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result[idx0 + 104 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[104]
 * Return Type  : void
 */
static void argInit_104x1_real_T(double result[104])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 104; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[2704]
 * Return Type  : void
 */
static void argInit_104x26_real_T(double result[2704])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 104; idx0++) {
    for (idx1 = 0; idx1 < 26; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result[idx0 + 104 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : boolean_T result[19]
 * Return Type  : void
 */
static void argInit_19x1_boolean_T(boolean_T result[19])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 19; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_boolean_T();
  }
}

/*
 * Arguments    : double result[760]
 * Return Type  : void
 */
static void argInit_19x40_real_T(double result[760])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 19; idx0++) {
    for (idx1 = 0; idx1 < 40; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result[idx0 + 19 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : char result[10]
 * Return Type  : void
 */
static void argInit_1x10_char_T(char result[10])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 10; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : double result[10]
 * Return Type  : void
 */
static void argInit_1x10_real_T(double result[10])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 10; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : char result[13]
 * Return Type  : void
 */
static void argInit_1x13_char_T(char result[13])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 13; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : char result[14]
 * Return Type  : void
 */
static void argInit_1x14_char_T(char result[14])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 14; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : cell_wrap_0 result[29]
 * Return Type  : void
 */
static void argInit_1x29_cell_wrap_0(cell_wrap_0 result[29])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 29; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_cell_wrap_0();
  }
}

/*
 * Arguments    : char result[5]
 * Return Type  : void
 */
static void argInit_1x5_char_T(char result[5])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 5; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : char result[6]
 * Return Type  : void
 */
static void argInit_1x6_char_T(char result[6])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 6; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : char result[7]
 * Return Type  : void
 */
static void argInit_1x7_char_T(char result[7])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : char result[8]
 * Return Type  : void
 */
static void argInit_1x8_char_T(char result[8])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 8; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : char result[9]
 * Return Type  : void
 */
static void argInit_1x9_char_T(char result[9])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 9; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_char_T();
  }
}

/*
 * Arguments    : cell_wrap_0 result[22]
 * Return Type  : void
 */
static void argInit_22x1_cell_wrap_0(cell_wrap_0 result[22])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 22; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_cell_wrap_0();
  }
}

/*
 * Arguments    : double result[5720]
 * Return Type  : void
 */
static void argInit_22x26x10_real_T(double result[5720])
{
  int idx0;
  int idx1;
  int idx2;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 22; idx0++) {
    for (idx1 = 0; idx1 < 26; idx1++) {
      for (idx2 = 0; idx2 < 10; idx2++) {
        /* Set the value of the array element.
Change this value to the value that the application requires. */
        result[(idx0 + 22 * idx1) + 572 * idx2] = argInit_real_T();
      }
    }
  }
}

/*
 * Arguments    : double result[3042]
 * Return Type  : void
 */
static void argInit_26x117_real_T(double result[3042])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 26; idx0++) {
    for (idx1 = 0; idx1 < 117; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result[idx0 + 26 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : boolean_T result[26]
 * Return Type  : void
 */
static void argInit_26x1_boolean_T(boolean_T result[26])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 26; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_boolean_T();
  }
}

/*
 * Arguments    : double result[26]
 * Return Type  : void
 */
static void argInit_26x1_real_T(double result[26])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 26; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[29]
 * Return Type  : void
 */
static void argInit_29x1_real_T(double result[29])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 29; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[38]
 * Return Type  : void
 */
static void argInit_38x1_real_T(double result[38])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 38; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : boolean_T result[40]
 * Return Type  : void
 */
static void argInit_40x1_boolean_T(boolean_T result[40])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 40; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_boolean_T();
  }
}

/*
 * Arguments    : double result[8112]
 * Return Type  : void
 */
static void argInit_78x104_real_T(double result[8112])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 78; idx0++) {
    for (idx1 = 0; idx1 < 104; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result[idx0 + 78 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : double result[2028]
 * Return Type  : void
 */
static void argInit_78x26_real_T(double result[2028])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 78; idx0++) {
    for (idx1 = 0; idx1 < 26; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result[idx0 + 78 * idx1] = argInit_real_T();
    }
  }
}

/*
 * Arguments    : void
 * Return Type  : boolean_T
 */
static boolean_T argInit_boolean_T(void)
{
  return false;
}

/*
 * Arguments    : cell_1 *result
 * Return Type  : void
 */
static void argInit_cell_1(cell_1 *result)
{
  int i;
  char c;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x7_char_T(result->f2);
  argInit_1x6_char_T(result->f1);
  argInit_1x8_char_T(result->f77);
  argInit_1x9_char_T(result->f93);
  argInit_1x10_char_T(result->f115);
  for (i = 0; i < 7; i++) {
    c = result->f2[i];
    result->f3[i] = c;
    result->f4[i] = c;
    result->f5[i] = c;
    result->f6[i] = c;
    result->f7[i] = c;
    result->f8[i] = c;
    result->f9[i] = c;
    result->f10[i] = c;
    result->f11[i] = c;
    result->f12[i] = c;
    result->f13[i] = c;
    result->f14[i] = c;
    result->f15[i] = c;
    result->f16[i] = c;
    result->f17[i] = c;
    result->f18[i] = c;
    result->f19[i] = c;
    result->f20[i] = c;
    result->f21[i] = c;
    result->f22[i] = c;
    result->f23[i] = c;
    result->f24[i] = c;
    result->f25[i] = c;
    result->f26[i] = c;
    result->f27[i] = c;
    result->f28[i] = c;
    result->f29[i] = c;
    result->f30[i] = c;
    result->f31[i] = c;
    result->f32[i] = c;
    result->f33[i] = c;
    result->f34[i] = c;
    result->f35[i] = c;
    result->f36[i] = c;
    result->f37[i] = c;
    result->f38[i] = c;
  }
  for (i = 0; i < 6; i++) {
    c = result->f1[i];
    result->f39[i] = c;
    result->f40[i] = c;
    result->f41[i] = c;
    result->f42[i] = c;
    result->f43[i] = c;
    result->f44[i] = c;
    result->f45[i] = c;
    result->f46[i] = c;
    result->f47[i] = c;
    result->f48[i] = c;
    result->f49[i] = c;
    result->f50[i] = c;
    result->f51[i] = c;
    result->f52[i] = c;
    result->f53[i] = c;
    result->f54[i] = c;
    result->f55[i] = c;
    result->f56[i] = c;
    result->f57[i] = c;
    result->f58[i] = c;
    result->f59[i] = c;
    result->f60[i] = c;
    result->f61[i] = c;
    result->f62[i] = c;
    result->f63[i] = c;
    result->f64[i] = c;
    result->f65[i] = c;
    result->f66[i] = c;
    result->f67[i] = c;
    result->f68[i] = c;
    result->f69[i] = c;
    result->f70[i] = c;
    result->f71[i] = c;
    result->f72[i] = c;
    result->f73[i] = c;
    result->f74[i] = c;
    result->f75[i] = c;
    result->f76[i] = c;
  }
  for (i = 0; i < 8; i++) {
    c = result->f77[i];
    result->f78[i] = c;
    result->f79[i] = c;
    result->f80[i] = c;
    result->f81[i] = c;
    result->f82[i] = c;
    result->f83[i] = c;
    result->f84[i] = c;
    result->f85[i] = c;
    result->f86[i] = c;
    result->f87[i] = c;
    result->f88[i] = c;
    result->f89[i] = c;
    result->f90[i] = c;
    result->f91[i] = c;
    result->f92[i] = c;
  }
  for (i = 0; i < 9; i++) {
    result->f94[i] = result->f93[i];
  }
  for (i = 0; i < 6; i++) {
    c = result->f1[i];
    result->f95[i] = c;
    result->f96[i] = c;
    result->f97[i] = c;
    result->f98[i] = c;
    result->f99[i] = c;
    result->f100[i] = c;
    result->f101[i] = c;
    result->f102[i] = c;
    result->f103[i] = c;
    result->f104[i] = c;
    result->f105[i] = c;
    result->f106[i] = c;
    result->f107[i] = c;
    result->f108[i] = c;
    result->f109[i] = c;
    result->f110[i] = c;
    result->f111[i] = c;
    result->f112[i] = c;
    result->f113[i] = c;
    result->f114[i] = c;
  }
  for (i = 0; i < 8; i++) {
    result->f116[i] = result->f77[i];
  }
  for (i = 0; i < 6; i++) {
    result->f117[i] = result->f1[i];
  }
}

/*
 * Arguments    : cell_2 *result
 * Return Type  : void
 */
static void argInit_cell_2(cell_2 *result)
{
  int i;
  char c;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x5_char_T(result->f1);
  argInit_1x7_char_T(result->f2);
  argInit_1x10_char_T(result->f20);
  argInit_1x6_char_T(result->f22);
  argInit_1x14_char_T(result->f17);
  argInit_1x13_char_T(result->f18);
  argInit_1x8_char_T(result->f19);
  for (i = 0; i < 5; i++) {
    result->f3[i] = result->f1[i];
  }
  for (i = 0; i < 7; i++) {
    c = result->f2[i];
    result->f4[i] = c;
    result->f5[i] = c;
    result->f6[i] = c;
    result->f7[i] = c;
    result->f8[i] = c;
    result->f9[i] = c;
    result->f10[i] = c;
    result->f11[i] = c;
    result->f12[i] = c;
    result->f13[i] = c;
    result->f14[i] = c;
    result->f15[i] = c;
    result->f16[i] = c;
  }
  for (i = 0; i < 10; i++) {
    result->f21[i] = result->f20[i];
  }
  for (i = 0; i < 6; i++) {
    c = result->f22[i];
    result->f23[i] = c;
    result->f24[i] = c;
  }
  for (i = 0; i < 7; i++) {
    c = result->f2[i];
    result->f25[i] = c;
    result->f26[i] = c;
  }
}

/*
 * Arguments    : cell_4 *result
 * Return Type  : void
 */
static void argInit_cell_4(cell_4 *result)
{
  int i;
  char c;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x5_char_T(result->f1);
  argInit_1x8_char_T(result->f23);
  argInit_1x9_char_T(result->f39);
  for (i = 0; i < 5; i++) {
    c = result->f1[i];
    result->f2[i] = c;
    result->f3[i] = c;
    result->f4[i] = c;
    result->f5[i] = c;
    result->f6[i] = c;
    result->f7[i] = c;
    result->f8[i] = c;
    result->f9[i] = c;
    result->f10[i] = c;
    result->f11[i] = c;
    result->f12[i] = c;
    result->f13[i] = c;
    result->f14[i] = c;
    result->f15[i] = c;
    result->f16[i] = c;
    result->f17[i] = c;
    result->f18[i] = c;
    result->f19[i] = c;
    result->f20[i] = c;
    result->f21[i] = c;
    result->f22[i] = c;
  }
  for (i = 0; i < 8; i++) {
    c = result->f23[i];
    result->f24[i] = c;
    result->f25[i] = c;
    result->f26[i] = c;
    result->f27[i] = c;
    result->f28[i] = c;
    result->f29[i] = c;
    result->f30[i] = c;
    result->f31[i] = c;
    result->f32[i] = c;
    result->f33[i] = c;
    result->f34[i] = c;
    result->f35[i] = c;
    result->f36[i] = c;
    result->f37[i] = c;
    result->f38[i] = c;
  }
  for (i = 0; i < 9; i++) {
    result->f40[i] = result->f39[i];
  }
}

/*
 * Arguments    : cell_5 *result
 * Return Type  : void
 */
static void argInit_cell_5(cell_5 *result)
{
  int i;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x8_char_T(result->f1);
  argInit_1x9_char_T(result->f17);
  for (i = 0; i < 8; i++) {
    char c;
    c = result->f1[i];
    result->f2[i] = c;
    result->f3[i] = c;
    result->f4[i] = c;
    result->f5[i] = c;
    result->f6[i] = c;
    result->f7[i] = c;
    result->f8[i] = c;
    result->f9[i] = c;
    result->f10[i] = c;
    result->f11[i] = c;
    result->f12[i] = c;
    result->f13[i] = c;
    result->f14[i] = c;
    result->f15[i] = c;
    result->f16[i] = c;
  }
  for (i = 0; i < 9; i++) {
    result->f18[i] = result->f17[i];
  }
  for (i = 0; i < 8; i++) {
    result->f19[i] = result->f1[i];
  }
}

/*
 * Arguments    : void
 * Return Type  : cell_wrap_0
 */
static cell_wrap_0 argInit_cell_wrap_0(void)
{
  cell_wrap_0 result;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x5_char_T(result.f1);
  return result;
}

/*
 * Arguments    : void
 * Return Type  : char
 */
static char argInit_char_T(void)
{
  return '?';
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : struct0_T *result
 * Return Type  : void
 */
static void argInit_struct0_T(struct0_T *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_38x1_real_T(result->Bm);
  result->time = argInit_real_T();
  memcpy(&result->Ff[0], &result->Bm[0], 38U * sizeof(double));
}

/*
 * Arguments    : struct1_T *result
 * Return Type  : void
 */
static void argInit_struct1_T(struct1_T *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result->time = argInit_real_T();
  argInit_29x1_real_T(result->Ia);
  argInit_1x29_cell_wrap_0(result->names);
}

/*
 * Arguments    : struct2_T *result
 * Return Type  : void
 */
static void argInit_struct2_T(struct2_T *result)
{
  int i;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_40x1_boolean_T(result->iEin);
  argInit_struct3_T(&result->Amat);
  argInit_struct4_T(&result->Mmat);
  argInit_struct5_T(&result->Gmat);
  argInit_struct7_T(&result->ssPIDd);
  for (i = 0; i < 40; i++) {
    boolean_T b;
    b = result->iEin[i];
    result->iFin[i] = b;
    result->iOHin[i] = b;
    result->iGOin[i] = b;
  }
}

/*
 * Arguments    : struct3_T *result
 * Return Type  : void
 */
static void argInit_struct3_T(struct3_T *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_26x117_real_T(result->data);
  argInit_cell_1(&result->dimin);
  argInit_cell_2(&result->dimout);
  argInit_26x1_boolean_T(result->lhyb);
}

/*
 * Arguments    : struct4_T *result
 * Return Type  : void
 */
static void argInit_struct4_T(struct4_T *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_19x40_real_T(result->data);
  argInit_cell_4(&result->dimin);
  argInit_cell_5(&result->dimout);
  argInit_19x1_boolean_T(result->lhyb);
}

/*
 * Arguments    : struct5_T *result
 * Return Type  : void
 */
static void argInit_struct5_T(struct5_T *result)
{
  int i;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_22x26x10_real_T(result->G1I);
  argInit_struct6_T(&result->addr);
  argInit_cell_2(&result->dimin);
  argInit_22x1_cell_wrap_0(result->dimout);
  for (i = 0; i < 5720; i++) {
    double d;
    d = result->G1I[i];
    result->G2P[i] = d;
    result->G3D[i] = d;
  }
}

/*
 * Arguments    : struct6_T *result
 * Return Type  : void
 */
static void argInit_struct6_T(struct6_T *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_1x10_real_T(result->time);
  memcpy(&result->data[0], &result->time[0], 10U * sizeof(double));
}

/*
 * Arguments    : struct7_T *result
 * Return Type  : void
 */
static void argInit_struct7_T(struct7_T *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_104x104_real_T(result->a);
  argInit_104x26_real_T(result->b);
  argInit_78x104_real_T(result->c);
  argInit_78x26_real_T(result->d);
}

/*
 * Arguments    : struct8_T *result
 * Return Type  : void
 */
static void argInit_struct8_T(struct8_T *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_104x1_real_T(result->hyb);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_hybctrl_step_IDS(void)
{
  static struct2_T r2;
  struct0_T r;
  struct1_T r1;
  struct8_T cstate;
  double dv[26];
  double cout[19];
  /* Initialize function 'hybctrl_step_IDS' input arguments. */
  /* Initialize function input argument 'magn'. */
  /* Initialize function input argument 'pfa'. */
  /* Initialize function input argument 'Arefs'. */
  /* Initialize function input argument 'cpar'. */
  /* Initialize function input argument 'cstate'. */
  /* Call the entry-point 'hybctrl_step_IDS'. */
  argInit_struct8_T(&cstate);
  argInit_struct0_T(&r);
  argInit_struct1_T(&r1);
  argInit_26x1_real_T(dv);
  argInit_struct2_T(&r2);
  hybctrl_step_IDS(argInit_real_T(), &r, &r1, dv, &r2, &cstate, cout);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_hybctrl_step_IDS();
  /* Terminate the application.
You do not need to do this more than one time. */
  hybctrl_step_IDS_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
