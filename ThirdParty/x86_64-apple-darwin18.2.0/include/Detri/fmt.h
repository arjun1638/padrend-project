/* fmt.h - Headers extracted from: fmt.c */

/*--------------------------------------------------------------------------*/

#ifndef __fmt_H_FILE__  /* Include this file only once! */
#define __fmt_H_FILE__

#ifdef __cplusplus
extern "C" {
#endif

/*--------------------------------------------------------------------------*/

/* Required includes */

#include <stdio.h>
#include <stdarg.h>

/*--------------------------------------------------------------------------*/

extern char *fmt_flags;

typedef void (*FMT_T) (int code, va_list *app,
                       int put (int c, void *cl), void *cl,
                       unsigned char flags[256], int width, int precision);

FMT_T fmt_register (int code, FMT_T newcvt);

/*--------------------------------------------------------------------------*/

void fmt_fmt (int put (int c, void *cl), void *cl, const char *fmt, ...);

void fmt_vfmt (int put (int c, void *cl), void *cl,
               const char *fmt, va_list ap);

void fmt_putd (const char *str, int len,
               int put (int c, void *cl), void *cl,
               unsigned char flags[], int width, int precision);

void fmt_puts (const char *str, int len,
               int put (int c, void *cl), void *cl,
               unsigned char flags[], int width, int precision);

/*--------------------------------------------------------------------------*/

void fmt_print (const char *fmt, ...);

void fmt_fprint (FILE *stream, const char *fmt, ...);

int fmt_sfmt (char *buf, int size, const char *fmt, ...);

int fmt_vsfmt (char *buf, int size, const char *fmt, va_list ap);

char *fmt_string (const char *fmt, ...);

char *fmt_vstring (const char *fmt, va_list ap);

void *fmt_newbuf (void);

void fmt_printbuf (void *buf, const char *fmt, ...);

void fmt_vprintbuf (void *buf, const char *fmt, va_list ap);

char *fmt_strbuf (void *buf);

#define fmt_free(STRPTR) do { fmt_free_f (STRPTR); STRPTR = NULL; } while (0)
void    fmt_free_f (void *str);

/*--------------------------------------------------------------------------*/

#if defined(__cplusplus)
}
#endif

#endif  /* #ifndef __fmt_H_FILE__ */
