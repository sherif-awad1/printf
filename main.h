#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
typedef unsigned int uint;
typedef unsigned char uchr;
typedef const char cchr;
typedef unsigned long int ulint;
typedef long int lint;
#define SHORT 1
#define LONG 2
#define PLUS 1
#define SPAC 2
#define HASH 4
#define ZERO 8
#define NEGTIV 16
#define PLUS_FLAGS (flag & 1)
#define SPAC_FLAGS ((flag >> 1) & 1)
#define HASH_FLAGS ((flag >> 2) & 1)
#define ZERO_FLAGS ((flag >> 3) & 1)
#define NEGTIV_FLAGS ((flag >> 4) & 1)
/**
 * struct buf_s - buffer struct
 * @buf: pointer to array
 * @str: start buffer
 * @leng: lenght of string
 */
typedef struct buf_s
{
	char *buf;
	char *str;
	uint leng;
} buf_t;
/**
 * struct con_spe - con struct
 * @specfi: spacfier
 * @fun: function pointer
 */
typedef struct con_spe
{
	uchr specfi;
	uint (*fun)(va_list, buf_t *, uchr, int, int, uchr);
} con_t;
/**
 * struct flags_s - flags struct
 * @flags: flags
 * @values: values of the flags
 */
typedef struct flags_s
{
	uchr flags;
	uchr values;
} flags_t;

/* printf.c */
void cleaner(va_list arg, buf_t *op);
int rprintf(cchr *format, va_list arg, buf_t *op);
int _printf(cchr *format, ...);
/* prc_add_char_handler.c */
uint con_c(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
uint con_prc(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
uint con_p(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
/* handler */
uchr flags_handler(cchr *flag, char *i);
uchr length_handler(cchr *flag, char *i);
int width_handler(va_list arg, cchr *mod, char *i);
int prc_handler(va_list arg, cchr *mod, char *i);
uint (*specfi_handler(cchr *spacfi))(va_list, buf_t *, uchr, int, int, uchr);
/* mod_handler.c */
uint print_w(buf_t *op, uint print, uchr flag, int width);
uint print_sw(buf_t *op, uchr flag, int width, int prc, int size);
uint print_nw(buf_t *op, uint print, uchr flag, int width);
/* hex_functions.c */
uint con_x(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
uint con_X(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
/* string functions */
uint con_s(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
uint con_S(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
uint con_rev(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
uint con_R13(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
/* integer functions */
uint con_d(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
uint con_b(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
uint con_o(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
uint con_u(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng);
/* memory_function Functions */
buf_t *int_buf(void);
void free_buf(buf_t *op);
uint _memncpy(buf_t *op, cchr *src, uint n);
/* long int handler */
uint con_sb(buf_t *op, lint n, char *b, uchr flag, int width, int prc);
uint con_ub(buf_t *op, ulint n, char *b, uchr flag, int width, int prc);

#endif /* MAIN_H */
