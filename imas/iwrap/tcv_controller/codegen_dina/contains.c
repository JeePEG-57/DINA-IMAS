/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: contains.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 24-Apr-2026 10:42:42
 */

/* Include Files */
#include "contains.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T ab_contains(const char str[6])
{
  static const char cv[5] = {'I', 'a', '_', 'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 2) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T ac_contains(const char str[8])
{
  static const char cv[6] = {'I', 'a', '_', 'T', 'O', 'R'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T b_contains(const char str[7])
{
  static const char cv[3] = {'F', 'f', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T bb_contains(const char str[7])
{
  static const char cv[5] = {'I', 'a', '_', 'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T bc_contains(const char str[9])
{
  static const char cv[6] = {'I', 'a', '_', 'T', 'O', 'R'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T c_contains(const char str[8])
{
  static const char cv[3] = {'F', 'f', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 6) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T cb_contains(const char str[8])
{
  static const char cv[5] = {'I', 'a', '_', 'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T cc_contains(const char str[10])
{
  static const char cv[6] = {'I', 'a', '_', 'T', 'O', 'R'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T contains(const char str[6])
{
  static const char cv[3] = {'F', 'f', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T d_contains(const char str[9])
{
  static const char cv[3] = {'F', 'f', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 7) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T db_contains(const char str[9])
{
  static const char cv[5] = {'I', 'a', '_', 'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T dc_contains(const char str[6])
{
  static const char cv[2] = {'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T e_contains(const char str[10])
{
  static const char cv[3] = {'F', 'f', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 8) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T eb_contains(const char str[10])
{
  static const char cv[5] = {'I', 'a', '_', 'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 6) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T ec_contains(const char str[7])
{
  static const char cv[2] = {'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 6) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T f_contains(const char str[6])
{
  static const char cv[4] = {'F', 'f', 'r', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T fb_contains(const char str[6])
{
  static const char cv[5] = {'I', 'a', '_', 'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 2) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T fc_contains(const char str[8])
{
  static const char cv[2] = {'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 7) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T g_contains(const char str[7])
{
  static const char cv[4] = {'F', 'f', 'r', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T gb_contains(const char str[7])
{
  static const char cv[5] = {'I', 'a', '_', 'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T gc_contains(const char str[9])
{
  static const char cv[2] = {'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 8) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T h_contains(const char str[8])
{
  static const char cv[4] = {'F', 'f', 'r', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T hb_contains(const char str[8])
{
  static const char cv[5] = {'I', 'a', '_', 'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T hc_contains(const char str[10])
{
  static const char cv[2] = {'E', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 9) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T i_contains(const char str[9])
{
  static const char cv[4] = {'F', 'f', 'r', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 6) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T ib_contains(const char str[9])
{
  static const char cv[5] = {'I', 'a', '_', 'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T ic_contains(const char str[6])
{
  static const char cv[2] = {'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T j_contains(const char str[10])
{
  static const char cv[4] = {'F', 'f', 'r', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 7) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T jb_contains(const char str[10])
{
  static const char cv[5] = {'I', 'a', '_', 'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 6) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T jc_contains(const char str[7])
{
  static const char cv[2] = {'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 6) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T k_contains(const char str[6])
{
  static const char cv[6] = {'F', 'f', 'd', 'o', 't', '_'};
  int j;
  j = 1;
  while ((j <= 6) && (str[j - 1] == cv[j - 1])) {
    j++;
  }
  return j > 6;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T kb_contains(const char str[6])
{
  static const char cv[5] = {'I', 'a', '_', 'G', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 2) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T kc_contains(const char str[8])
{
  static const char cv[2] = {'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 7) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T l_contains(const char str[7])
{
  static const char cv[6] = {'F', 'f', 'd', 'o', 't', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 2) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T lb_contains(const char str[7])
{
  static const char cv[5] = {'I', 'a', '_', 'G', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T lc_contains(const char str[9])
{
  static const char cv[2] = {'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 8) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T m_contains(const char str[8])
{
  static const char cv[6] = {'F', 'f', 'd', 'o', 't', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T mb_contains(const char str[8])
{
  static const char cv[5] = {'I', 'a', '_', 'G', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T mc_contains(const char str[10])
{
  static const char cv[2] = {'F', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 9) {
      int j;
      j = 1;
      while ((j <= 2) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 2) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T n_contains(const char str[9])
{
  static const char cv[6] = {'F', 'f', 'd', 'o', 't', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T nb_contains(const char str[9])
{
  static const char cv[5] = {'I', 'a', '_', 'G', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T nc_contains(const char str[6])
{
  static const char cv[4] = {'_', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T o_contains(const char str[10])
{
  static const char cv[6] = {'F', 'f', 'd', 'o', 't', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T ob_contains(const char str[10])
{
  static const char cv[5] = {'I', 'a', '_', 'G', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 6) {
      int j;
      j = 1;
      while ((j <= 5) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 5) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T oc_contains(const char str[7])
{
  static const char cv[4] = {'_', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T p_contains(const char str[6])
{
  static const char cv[3] = {'B', 'm', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T pb_contains(const char str[6])
{
  static const char cv[6] = {'I', 'a', '_', 'O', 'H', '_'};
  int j;
  j = 1;
  while ((j <= 6) && (str[j - 1] == cv[j - 1])) {
    j++;
  }
  return j > 6;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T pc_contains(const char str[8])
{
  static const char cv[4] = {'_', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T q_contains(const char str[7])
{
  static const char cv[3] = {'B', 'm', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T qb_contains(const char str[7])
{
  static const char cv[6] = {'I', 'a', '_', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 2) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T qc_contains(const char str[9])
{
  static const char cv[4] = {'_', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 6) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T r_contains(const char str[8])
{
  static const char cv[3] = {'B', 'm', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 6) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T rb_contains(const char str[8])
{
  static const char cv[6] = {'I', 'a', '_', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T rc_contains(const char str[10])
{
  static const char cv[4] = {'_', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 7) {
      int j;
      j = 1;
      while ((j <= 4) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 4) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T s_contains(const char str[9])
{
  static const char cv[3] = {'B', 'm', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 7) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T sb_contains(const char str[9])
{
  static const char cv[6] = {'I', 'a', '_', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T t_contains(const char str[10])
{
  static const char cv[3] = {'B', 'm', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 8) {
      int j;
      j = 1;
      while ((j <= 3) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 3) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T tb_contains(const char str[10])
{
  static const char cv[6] = {'I', 'a', '_', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T u_contains(const char str[6])
{
  static const char cv[6] = {'B', 'm', 'd', 'o', 't', '_'};
  int j;
  j = 1;
  while ((j <= 6) && (str[j - 1] == cv[j - 1])) {
    j++;
  }
  return j > 6;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T ub_contains(const char str[7])
{
  static const char cv[7] = {'I', 'a', '_', 'D', 'O', 'H', '_'};
  int j;
  j = 1;
  while ((j <= 7) && (str[j - 1] == cv[j - 1])) {
    j++;
  }
  return j > 7;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T v_contains(const char str[7])
{
  static const char cv[6] = {'B', 'm', 'd', 'o', 't', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 2) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T vb_contains(const char str[8])
{
  static const char cv[7] = {'I', 'a', '_', 'D', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 2) {
      int j;
      j = 1;
      while ((j <= 7) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 7) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[8]
 * Return Type  : boolean_T
 */
boolean_T w_contains(const char str[8])
{
  static const char cv[6] = {'B', 'm', 'd', 'o', 't', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T wb_contains(const char str[9])
{
  static const char cv[7] = {'I', 'a', '_', 'D', 'O', 'H', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 3) {
      int j;
      j = 1;
      while ((j <= 7) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 7) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[9]
 * Return Type  : boolean_T
 */
boolean_T x_contains(const char str[9])
{
  static const char cv[6] = {'B', 'm', 'd', 'o', 't', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 4) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[6]
 * Return Type  : boolean_T
 */
boolean_T xb_contains(const char str[6])
{
  static const char cv[6] = {'I', 'a', '_', 'T', 'O', 'R'};
  int j;
  j = 1;
  while ((j <= 6) && (str[j - 1] == cv[j - 1])) {
    j++;
  }
  return j > 6;
}

/*
 * Arguments    : const char str[10]
 * Return Type  : boolean_T
 */
boolean_T y_contains(const char str[10])
{
  static const char cv[6] = {'B', 'm', 'd', 'o', 't', '_'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 5) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * Arguments    : const char str[7]
 * Return Type  : boolean_T
 */
boolean_T yb_contains(const char str[7])
{
  static const char cv[6] = {'I', 'a', '_', 'T', 'O', 'R'};
  int matchPos;
  matchPos = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (matchPos < 2) {
      int j;
      j = 1;
      while ((j <= 6) && (str[(matchPos + j) - 1] == cv[j - 1])) {
        j++;
      }
      if (j > 6) {
        matchPos++;
        exitg1 = 1;
      } else {
        matchPos++;
      }
    } else {
      matchPos = 0;
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return matchPos > 0;
}

/*
 * File trailer for contains.c
 *
 * [EOF]
 */
