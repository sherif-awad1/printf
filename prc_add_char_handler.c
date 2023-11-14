/*
 * FILE: prc_add_char_handler
 *
 * Author: Sherif Awad
 */
#include "main.h"
/**
 * con_c - convert argment to char
 * @arg: point to argment
 * @op: buf_t struct
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of bytes
 */
uint con_c(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	char c;
	uint byt = 0;

	(void)prc;
	(void)leng;

	c = va_arg(arg, int);

	byt += print_w(op, byt, flag, width);
	byt += _memncpy(op, &c, 1);
	byt += print_nw(op, byt, flag, width);

	return (byt);
}
/**
 * con_prc - percentage handler
 * @arg: argments
 * @op: buf_t struct
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of bytes
 */
uint con_prc(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	char perc = '%';
	uint byt = 0;

	(void)arg;
	(void)prc;
	(void)leng;

	byt += print_w(op, byt, flag, width);
	byt += _memncpy(op, &perc, 1);
	byt += print_nw(op, byt, flag, width);

	return (byt);
}
/**
 * con_p - convert address to hex
 * @arg: point to argment
 * @op: buf_t struct
 * @flag: flags mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of bytes
 */
uint con_p(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	char *n = "(nil)";
	uint add, byt = 0;

	(void)leng;

	add = va_arg(arg, ulint);

	if (add == '\0')
		return (_memncpy(op, n, 5));

	flag |= 32;
	byt += con_ub(op, add, "0123456789abcdef", flag, width, prc);
	byt += print_nw(op, byt, flag, width);

	return (byt);
}
