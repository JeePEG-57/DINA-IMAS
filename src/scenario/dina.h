#if defined (_MSC_VER)

#define tran_to_dina_ tran_to_dina

#define dina_ dina

#define time_iterp_ time_iterp

#endif



/* 

 * Some compilers don't use a trailing 

 * underscore on Fortran external symbols 

 */

#if defined(__xlc__) || defined(__hpux)

#define dina_ dina

#define tran_to_dina_ tran_to_dina

#define time_iterp_ time_iterp

#endif
