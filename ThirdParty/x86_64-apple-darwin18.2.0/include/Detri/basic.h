/* basic-to-rx "mutation" */

/*--------------------------------------------------------------------------*/

/* NOTE: Use "cc -D__DEBUG__" when debugging! */

#ifndef __BASIC_H__  /* Include this file only once! */
#define __BASIC_H__

/*--------------------------------------------------------------------------*/

#include "rx.h"

/*--------------------------------------------------------------------------*/

/* MODULE basic/getarg.c --- parse command-line arguments */

/* This was originally written by D'Arcy J M Cain. */

int          basic_getarg_init  (int argc, char **argv);
int          basic_getarg_inite (int argc, char **argv);
int          basic_getarg       (const char *opts);
extern char* basic_getarg_optarg;
extern int   basic_getarg_optind;

/*--------------------------------------------------------------------------*/

/* MODULE basic/cb.c --- a (stack of) dynamically sized char buffer(s) */
void  basic_cb_putc  (char c);
char* basic_cb_str   (void);
void  basic_cb_clear (void);
int   basic_cb_len   (void);
int   basic_cb_size  (void);

int   basic_cb_addalinef (FILE *file);
char* basic_cb_getline   (FILE *file);

int   basic_cb_printf (const char *frmt, ...);
char* basic_cb_frmt   (const char *frmt, ...);

#define basic_cb_addaline  (void) basic_cb_addalinef
#define basic_cb_print     (void) basic_cb_printf

#define basic_cb_vprintf   basic_cb_doprnt

void  basic_cb_push_buffer (void);
void  basic_cb_pop_buffer  (void);

/* NOTE: This module uses Steve Summit's _doprnt() code: basic/cb_doprnt.c */
int basic_cb_doprnt (const char *fmt, va_list argp);

/*--------------------------------------------------------------------------*/

/* MODULE basic/isort --- inplace (insertion) sorting of very small lists */

int basic_isort2  (int *a, int*b);
int basic_isort3  (int *a, int *b, int *c);
int basic_isort4p (int *a, int *b, int *c, int *d);
int basic_isort4  (int *a, int *b, int *c, int *d);
int basic_isort5p (int *a, int *b, int *c, int *d, int *e);

/*--------------------------------------------------------------------------*/

/* MODULE basic/prime.c --- prime numbers */

int basic_prime_successor (int n);
int basic_prime_test      (int n);

typedef struct basic_prime_info_struct
{
  int tests, mods;
} Basic_prime_info;

Basic_prime_info* basic_prime_info (void);

/*--------------------------------------------------------------------------*/

/* MODULE basic/uhash.c --- universal hashing */

void basic_uhash_new (int s, int r, int *m, int a[]);
int  basic_uhash     (const int a[], int r, int m, const RX_BYTE x[]);

/*--------------------------------------------------------------------------*/

/* MODULE basic/istaque --- unbounded int stack/queue, dynamic re-allocation */

typedef char* Basic_istaque_adt;  /* Abstract data type! */

Basic_istaque_adt basic_istaque_new     (int minsize);
void              basic_istaque_dispose (Basic_istaque_adt s);

void basic_istaque_clear (      Basic_istaque_adt s);
int  basic_istaque_empty (const Basic_istaque_adt s);

int  basic_istaque_top  (const Basic_istaque_adt s);
int  basic_istaque_pop  (      Basic_istaque_adt s);
void basic_istaque_push (      Basic_istaque_adt s, int value);
int  basic_istaque_bot  (const Basic_istaque_adt s);
int  basic_istaque_get  (Basic_istaque_adt s);

int    basic_istaque_length (const Basic_istaque_adt s);
void   basic_istaque_print  (const Basic_istaque_adt s, FILE *file);
double basic_istaque_resize (      Basic_istaque_adt s, double resize_code);

/*--------------------------------------------------------------------------*/

/* MODULE basic/counter.c --- macros & routines for counters: big, int, N/A */

typedef struct basic_counter_record
{
  int a, b;
} Basic_counter;

/* Never use these functions directly; use below macros! */
char *basic_counter__ (Basic_counter counter);
char *basic_counter_  (int counter);
void  basic_counter_reset__ (Basic_counter *counter);
void  basic_counter_plus__ (Basic_counter *counter, int increment);

#define BASIC_COUNTER_MODE 1

#if (BASIC_COUNTER_MODE == 2)
#  define basic_counter_plus(CPTR,I)  basic_counter_plus__ (CPTR, I)
#  define basic_counter_reset(CPTR)   basic_counter_reset__ (CPTR)
#  define basic_counter(C)            basic_counter__ (C)
#endif

#if (BASIC_COUNTER_MODE == 1)
#  define basic_counter_plus(CPTR,I)  (CPTR)->a += (I)
#  define basic_counter_reset(CPTR)   (CPTR)->a = 0
#  define basic_counter(C)            basic_counter_ (C.a)
#endif

#if (BASIC_COUNTER_MODE == 0)
#  define basic_counter_plus(CPTR,I)  /* nothing */
#  define basic_counter_reset(CPTR)   /* nothing */
#  define basic_counter(C)            "N/A"
#endif

/* NOTE: basic_counter_plus() behaves like a function but is a macro, such
 *       that you can redefine it in case you don't bounther counting at all.
 */

/*--------------------------------------------------------------------------*/

/* MODULE basic/arg.c --- Routines for long command-line arguments */

void   basic_arg_open         (int arg_c, char **arg_v);
void   basic_arg_close        (void);
char*  basic_arg_string       (int i);
int    basic_arg_match        (int i, const char string[]);
int    basic_arg_match2int    (int i, const char string[], int *val);
int    basic_arg_match2float  (int i, const char string[], float *val);
int    basic_arg_match2double (int i, const char string[], double *val);
int    basic_arg_match2string (int i, const char string[],
                               char buffer[], int length);
int    basic_arg_increment    (void);
int    basic_arg_find         (const char string[], int arg_c,
                               /*const*/ char *arg_v[]);

/*--------------------------------------------------------------------------*/

/* Miscellaneous routines. */

/* basic/qsort.c */
void basic_qsort (int table[], int  i, int j,
                  int (*compare) (const int *, const int *)); 

/*--------------------------------------------------------------------------*/

/* MODULE basic/iit.c --- Integer interval tree [**] */

typedef  char*  Basic_iit;  /* Abstract data type! */

typedef struct basic_iit_info_type
{
  int n;
  int nodes;
  double lowsort_time;
  double buildup_time;
  int bytes, bytes_tree, bytes_array;
  int max_depth, filled_depth;
  double avg_depth;
  double avg_nodesize;
} Basic_iit_info;

Basic_iit       basic_iit_build (int n, int e[],
                                 int (* low) (int), int (* high) (int),
                                 int (* is_contained) (int, int));
void            basic_iit_query (Basic_iit t, int x, void (* report) (int));
void            basic_iit_kill  (Basic_iit t);
Basic_iit_info* basic_iit_info  (const Basic_iit t);
extern int      basic_iit_proto_flag;

/*--------------------------------------------------------------------------*/

/* MODULE basic/heapsort.c -- Heapsort routines [**] */

void basic_heapsort (int table[], int size, int (*comp) (int, int));

/*--------------------------------------------------------------------------*/

/* MODULE basic/uf.c -- Union/find data structure [**] */

typedef struct basic_uf_record_type       /* union and find data structure */
{
  int set;  /* pointer to root; for root, it is (negative) num. of elements */
  int next; /* next pointer */
} Basic_uf_record;

typedef struct basic_set_queue_type
{
  int num_elts;             /* Number of elements */
  int num_sets;             /* Number of sets */
  Basic_uf_record *ufelts;  /* Array of elements and their sets */
  int *root_list;           /* Array of roots */
} Basic_set_queue;

void             basic_uf_set      (Basic_set_queue *sq);
void             basic_uf_create   (int n);
int              basic_uf_find     (int i);
void             basic_uf_add      (int i);
void             basic_uf_delete   (int i);
void             basic_uf_union    (int i, int j);
Basic_set_queue* basic_uf_collect  (void);
int              basic_uf_set_size (int i);
int              basic_uf_num_sets (void);
void             basic_uf_free     (Basic_set_queue *sq);
void             basic_uf_print    (void);

/*--------------------------------------------------------------------------*/

/* NOTE: Modules marked with [**] are not necessarily included
         in the distribution. */

/*--------------------------------------------------------------------------*/

/*                        .................................................
                          "First learn computer science and all the theory.
                          Next develop a programming style. Then forget all
                          that and just hack."    -- George Carrette [1990]
                          ................................................. */

#endif  /* #ifndef __BASIC_H__ */
