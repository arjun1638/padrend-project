/* rx.h - Headers extracted from: rx.c */

/*--------------------------------------------------------------------------*/

#ifndef __rx_H_FILE__  /* Include this file only once! */
#define __rx_H_FILE__

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------*/

/* NOTE:
 *
 * Use 'cc -c -g -D__DEBUG__" for debugging!
 *
 * IMPORTANT: This header file violates the "clean name space" rule.
 * It defines numerous macros NOT starting with the "rx_" prefix!
 * Moreover, it includes, also numerous, system header files.
 *
 * It even violates the "rule" that macros are pointed out by capitalization.
 *
 * Granted, this ends up being a rather long header file.
 * The idea here is that #include "rx.h" takes care of most stuff...
 */

/*--------------------------------------------------------------------------*/

/* Use SGI's symbols __sgi and sgi as synonyms */
#if defined (__sgi) && !defined (sgi)
# define sgi
#endif
#if defined (sgi) && !defined (__sgi)
# define __sgi
#endif

/*--------------------------------------------------------------------------*/

/* Include commonly used standard header files (ANSI C standard) */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdarg.h> /* for variable-length argument lists */

#include <limits.h>
#include <float.h>

/*--------------------------------------------------------------------------*/

/* NOTE: This is not ANSI C, but we would like to have a proper MAXPATHLEN */

#include <sys/param.h>  

#ifndef  MAXPATHLEN  
# define MAXPATHLEN  256  /* Or even 1024? */
#endif

/*--------------------------------------------------------------------------*/

#ifndef  BITS
# define BITS(type)  (CHAR_BIT * (int) sizeof (type))
#endif

/*--------------------------------------------------------------------------*/

/* 'gcc -Wall' sometimes has really poorly defined HIBIT* in <values.h>.
   They should be as listed below!  If you're still getting warnings,
   try using -D__USE_FIXED_PROTOTYPES__ */
#if defined(__GNUC__) && defined(__USE_FIXED_PROTOTYPES__)
# undef HIBITS
# undef HIBITI
# undef HIBITL
#endif

/* Properly defined HIBIT* ... */
#ifndef  HIBITI
# define HIBITS  ((short)(1 << (BITS(short) - 1)))
# define HIBITI  (1 << (BITS(int) - 1))
# define HIBITL  (1L << (BITS(long) - 1))
#endif

/* QUESTION: DO WE REALLY STILL NEED THIS IN THE 1ST PLACE ??? */

/*--------------------------------------------------------------------------*/

/* Boolean (int) constants. */

#define Basic_byte  unsigned char

#ifdef  TRUE
# undef TRUE
#endif
#define TRUE   1

#ifdef  FALSE
# undef FALSE
#endif
#define FALSE  0

#define YES    TRUE
#define NO     FALSE

#define ON     TRUE
#define OFF    FALSE

/*--------------------------------------------------------------------------*/

/* Human-readable logical operators */

//#define and    &&
//#define or     ||
//#define not    !
//#define mod    %

/*--------------------------------------------------------------------------*/

/* In-line if, also human-readable */

#define If(COND,THEN,ELSE)  ((COND) ? (THEN) : (ELSE))

/*--------------------------------------------------------------------------*/

/* Nicer loop constructs. */

#define   upfor(I,S,E)  for (I = (S); I <= (E); I++)
#define downfor(I,S,E)  for (I = (S); I >= (E); I--)
#define until(Q)        while (! (Q));
#define loop            for (;;) 

/*--------------------------------------------------------------------------*/

/* The "once" macro is intended to be used within macro definitions; as in:
   "#define MACRO(...)  do { .... } once"   ...this allows semicolons after
   MACRO() invocations */

#define once  while (0)

/*--------------------------------------------------------------------------*/

/* The "_noop_" macro has the same intent, but it's used slightly differently:
   "#define MACRO(...)   { ... } _noop_"     ... Which is better?  We'll see.
   (The problem with "once" is that some compilers are bitching about it --
   eg, on the SGI: "remark(1209): controlling expression is constant" */

#define _noop_  _touch_ (0)

/*--------------------------------------------------------------------------*/

/* Some useful macros. */

/* WARNING: They might evaluate their arguments twice! */

#define Odd(X)  ((X) % 2 == 1)

/* NOTE:
   The proper def of "Even" would be "#define even(X)  (! Odd (X))";
   note the subtile difference to "((X) % 2 == 0)" wrt portability! */

#define Sign(X)  (((X) > 0) ? 1 : (((X) < 0) ? -1 : 0))
#define Abs(X)   (((X) >= 0) ? X : -(X))

#define Min(X,Y)  (((X) < (Y)) ? (X) : (Y))
#define Max(X,Y)  (((X) > (Y)) ? (X) : (Y))

#define Square(X)  ((X) * (X))

#define power2(EXP)    (1L << (EXP))  /* like a function, returning: long */
#define bitsof(TYPE)   (BITS (TYPE))  /* like a function, returning: int  */

/*--------------------------------------------------------------------------*/

/* Pointer casting */

#define Addr(PTR)  ((unsigned long) (PTR))

/*
 * NOTE:
 *
 * Whenever there is the need to cast pointers to integers, PLEASE use Addr();
 * even in:  ``print ("... 0x%lx ...", ... Addr (PTR) ...);''
 *
 * The motto is: better paranoid than sorry.
 *
 * REMEMBER:
 *
 * (1) In general, you can't just cast a pointer to an integer!  Logically
 *     speaking,  you should use size_t (as defined in <stddef.h>) for it,
 *     but we're talking C here, so what does all this have to do with logic?
 *     The problem is that size_t might be either int, unsigned int, or
 *     unsigned long, depending on architecture, and so we don't know how
 *     to print it.
 *
 *       One solution is this: make sure that
 *
 *             sizeof (unsigned long) == sizeof (void *)
 *
 *     cf: rx_types_okay(), and cast pointers always to unsigned long,
 *     ie, use the Addr() macro... and hope that <stddef.h> is smart
 *     enough to define a proper size_t.
 *
 * (2) Repeat: Whenever we're talking about pointers/addresses,
 *     we're talking unsigend long integers.
 *
 * (3) The sizeof() operator returns size_t... so, if you want an int,
 *      you need to cast: "(int) sizeof (...)"
 */

/*--------------------------------------------------------------------------*/

/* The return values of ?printf() and ?scanf() are rarely used. */

#define  print  (void) printf
#define fprint  (void) fprintf
#define sprint  (void) sprintf
#define  scan   (void)  scanf
#define fscan   (void) fscanf
#define sscan   (void) sscanf

//#define flush() fflush (stdout)

/*--------------------------------------------------------------------------*/

/* The binfwrite() and binfread() marcos are for binary in/output. */

/* NOTE: Users of binfread() must provide enough space at *PTR.
   Cf, 'man fread' and 'man fwrite'.  Also: N can be int or long;
   no matter what, it's casted to unsigned long via Addr(). */

#define binfread(PTR,N,F) \
do { \
     unsigned long k = \
       fread ((void *) (PTR), sizeof (*(PTR)), Addr (N), (F)); \
     if (k != Addr (N)) \
       rx_error ("binfread: failed, %s: %d", __FILE__, __LINE__); \
   } once

#define binfwrite(PTR,N,F) \
do { \
     unsigned long k = \
       fwrite ((void *) (PTR), sizeof (*(PTR)), Addr (N), (F)); \
     if (k != Addr (N)) \
       rx_error ("binfwrite: failed, %s: %d", __FILE__, __LINE__); \
   } once

/*--------------------------------------------------------------------------*/

/* The assertion macros: Assert(EX), Assert_if(EX), and Assert_always(EX). */

/* The Assert(EX) macro indicates that expression EX is expected to be TRUE
   (ie, nonzero) at this point of the program's execution.  If EX is FALSE
   (ie, zero) the macro calls the rx_error() routine which aborts execution
   with a diagnostic comment.  Compiling w/o -D__DEBUG__ will ignore all
   Assert() and Assert_if() macros, while Assert_always() will check for a
   valid EX all the time.  (This is based on /usr/include/assert.h.) */
  
#define Assert_always(EX) \
do { \
     if (! (EX)) rx_error (rx__assert_frmt, __FILE__, __LINE__); \
   } once

#ifdef __DEBUG__
# define Assert(EX)          Assert_always (EX)
# define Assert_if(FLAG,EX)  do { if (FLAG) Assert_always (EX); } once
#else
# define Assert(EX)          /* relax */
# define Assert_if(FLAG,EX)  /* relax */
#endif

extern const char rx__assert_frmt[];

/*--------------------------------------------------------------------------*/

/* "Touching" of unused arguments... */

/* It sometimes happens, in particular, in connection with above Assert*()
   macros, that some of the arguments to a function are unused...  *and*
   there happen to be compilers that bitch about this.  Rather than to
   globally disable the "argument unused" warnings, it's better to
   selectively avoid the warnings by "touching" these arguments.

   The hack "_touch_ (a && b && c && ...);" will make  the compiler believe
   that "a, b, c, ..." are used.  It's not the cleanest way, but it seems to
   work well, and the macro is implemented such that (I believe!) it doesn't
   cost too much time during execution.  Hopefully, it's portable, too.

   NOTE: This is also used to "implement" the _noop_ macro (see above).

   --epm */

#define _touch_(ARG_CONJUNCTION)  (void) (0 && (ARG_CONJUNCTION))

/*---------------------------------------------------------------------------*/

/* RX_BYTE and NULL */

#ifndef  NULL
# define NULL (void *) 0
#endif

/* NOTE: The NULL constant should actually come from <stdio.h>.
   Anyways:  NULL denotes a nonexistent pointer */

#define RX_BYTE  unsigned char

/*--------------------------------------------------------------------------*/

/* Charbit macros */

/* Usage: eg: c = rx_charbit_s1 (2,c)
 *
 * macro rx_charbit_on(I,C) returns TRUE iff bit I in char C is set to 1;
 * macro rx_charbit_s1(I,C) sets bit I in char C to 1;
 * macro rx_charbit_s0(I,C) sets bit I in char C to 0;
 *
 * Of course, insted af char, you can also use RX_BYTE.
 */

extern const RX_BYTE rx_charbit_mask__[];
extern const RX_BYTE rx_charbit_mask_n[];

#define rx_charbit_on(I,CVAR)  ((rx_charbit_mask__[I] & CVAR) != 0)
#define rx_charbit_s1(I,CVAR)  ((char) (rx_charbit_mask__[I] | CVAR))
#define rx_charbit_s0(I,CVAR)  ((char) (rx_charbit_mask_n[I] & CVAR))

#define rx_intbit_on(I,IVAR) ((power2 (I) & IVAR) != 0)

/*--------------------------------------------------------------------------*/

/* bits and bytes */

unsigned long rx_kbytes     (unsigned long bytes);
double        rx_mbytes     (unsigned long bytes);
char         *rx_strip      (const char *strng);

int rx_types_okay (void);
int rx_is_64_bit_ARCH (void);

/*--------------------------------------------------------------------------*/

/* system.c -- A handful for system routines */

void rx_system   (const char *frmt, ...);

double rx_utime    (void);
char  *rx_hostname (void);
char  *rx_date     (void);
double rx_seconds  (void);
int    rx_seed     (void);

void rx_error      (const char *frmt, ...);
void rx_error_hook (void (* user_error) (const char msg[]));

#define NULL_HOOK    rx__null_hook
extern       void (* rx__null_hook) (const char []);

/*--------------------------------------------------------------------------*/

/* getline.c -- Simple line-oriented parsing: getline & tokenize */

int rx_getline (FILE *file, char buffer[], int len);
int rx_tokenize (char string[], char *token[], int maximum);

/*--------------------------------------------------------------------------*/

/* file.c -- Encapsulated file utilities */

FILE  *rx_fopen   (const char path_name[], const char mode[]);
void   rx_fclose  (FILE *file);
int    rx_access  (const char path_name[]);
time_t rx_modtime (const char path_name[]);
void   rx_rm      (const char path_name[]);

const char *rx_fname (FILE *file);
const char *rx_bname (FILE *file);

/*--------------------------------------------------------------------------*/

/* malloc.c -- encapsulated malloc */

/* Macros for dynamic memory alloctaion:
   
   (T *)    MALLOC (T, N)      ... allocate N elements of type T
   void     REALLOC (P, T, N)  ... re-allocate memory object (char *) P
   void     FREE (P)           ... deallocate memory object (char *) P
   void     BZERO (P, T, N)    ... clear bytes of memory object (char *) P

   The parameters T and N above always denote a type and an integer number.
   Momory objects (char *) P are assumed to be allocated with this module.
   NOTE that REALLOC() is a void function... in contrast to realloc()!

   Macros for string allocation:

   (char *) STRDUP (S) ... duplicate string (char *) S and return pointer
   STRSET (S1, S2)     ... sets S1 = STRDUP (S2);  assumes S1 either NULL
                           or result of earlier STRDUP()

   The macros below are ignored for rx_malloc_debug (0), which is the
   default.

   void     HIDE (P)           ... mark memory object P as "hidden"
   void     MARK (P, M)        ... mark memory object P with (int) M

   Cf, malloc(), realloc(), strdup(), free(), bzero() of standard library.

   */

#define MALLOC(T,N) \
  (T*) rx_malloc_f (((size_t) N) * sizeof(T), __FILE__, __LINE__)

#define REALLOC(P,T,N) \
 P = (T*) rx_realloc_f ((char *) P, ((size_t) (N)) * sizeof(T), \
                        __FILE__, __LINE__)

#define FREE(P) \
  do { rx_free_f ((char *) P, __FILE__, __LINE__);  P = NULL; } once

#define BZERO(P,T,N)  rx_bzero ((char *) P, ((size_t) (N)) * sizeof (T))

#define HIDE(P)    rx_malloc_mark ((char *) P, -1)
#define MARK(P,M)  rx_malloc_mark ((char *) P,  M)

#define STRDUP(S) \
  rx_strdup_f (S, __FILE__, __LINE__)

#define STRSET(S1,S2) \
  do { FREE (S1);  S1 = STRDUP (S2); } once

typedef struct rx_malloc_info_struct
{
  size_t total;
  size_t in_use;
  size_t hidden;
  size_t arena;
  size_t used;
  size_t used_sml;
  size_t used_ord;
} RX_MALLOC_INFO;

RX_MALLOC_INFO* rx_malloc_info (void);
void            rx_malloc_debug        (int level);
void            rx_malloc_mark         (void *ptr, int mark);
unsigned long   rx_malloc_marked_bytes (int a, int b);
void            rx_malloc_list_print   (FILE *file);
void            rx_malloc_info_print   (FILE *file);

/* NOTE: The routines below should be invoked only in connection */
/*       with the above mentioned allocation macros!             */
void *rx_malloc_f  (size_t n,            const char *f, int l);
void *rx_realloc_f (void *ptr, size_t n, const char *f, int l);
void  rx_free_f    (void *ptr,           const char *f, int l);
char *rx_strdup_f  (const char *s1,      const char *f, int l);

void rx_bzero (void *p, size_t n);
void rx_bcopy (const void *src, void *dst, size_t n);

/*--------------------------------------------------------------------------*/

/* random.c -- Encapsulating the random generator */

long rx_random (void);
void rx_srandom (int seed);

/*--------------------------------------------------------------------------*/

/* nonansi.c -- Substitutes for functions that are sometimes missing... */

/* NOTE: For simplicity, we just add the headers here... independent of
   whether the actual implementation comes from the system libraries or
   rx/nonansi.c... or is not even used at all. */

int rx_ipower (int x, int y);

#ifndef __linux__
double log2  (double x);
double exp2  (double x);
double exp10 (double x);


double cbrt (double x);
#endif
/*--------------------------------------------------------------------------*/

/* QUOTE:                 .................................................
                          "First learn computer science and all the theory.
                          Next develop a programming style. Then forget all
                          that and just hack."    -- George Carrette [1990]
                          ................................................. */

/*--------------------------------------------------------------------------*/

#if defined(__cplusplus)
}
#endif

#endif  /* #ifndef __rx_H_FILE__ */
