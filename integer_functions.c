/*
 * FILE: integer_functions
 *
 * Author: Sherif Awad
 */
#include "main.h"
/**
 * con_d - handle integer
 * @arg: argment
 * @op: struct buf_t
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of byte
 */
uint con_d(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	lint d, c;
	uint byt = 0, n = 0;
	char p, spac = ' ', negtiv = '-', plus = '+';

	if (leng == LONG)
		d = va_arg(arg, lint);
	else
		d = va_arg(arg, int);
	if (leng == SHORT)
		d = (short)d;
	if (SPAC_FLAGS == 1 && d >= 0)
		byt += _memncpy(op, &spac, 1);
	if (prc <= 0 && NEGTIV_FLAGS == 0)
	{
		if (d == LONG_MIN)
			n += 19;
		else
			for (c = (d < 0) ? -d : d; c > 0; c /= 10)
				n++;

		n += (d == 0) ? 1 : 0;
		n += (d < 0) ? 1 : 0;
		n += (PLUS_FLAGS == 1 && d >= 0) ? 1 : 0;
		n += (SPAC_FLAGS == 1 && d >= 0) ? 1 : 0;
		if (ZERO_FLAGS == 1 && PLUS_FLAGS == 1 && d >= 0)
			byt +=  _memncpy(op, &plus, 1);
		if (ZERO_FLAGS == 1 &&  d && d < 0)
			byt += _memncpy(op, &negtiv, 1);
		p = (ZERO_FLAGS == 1) ? '0' : ' ';
		for (width -= n; width > 0; width--)
			byt += _memncpy(op, &p, 1);
	}
	if (ZERO_FLAGS == 0 && d < 0)
		byt += _memncpy(op, &negtiv, 1);
	if (ZERO_FLAGS == 0 && (PLUS_FLAGS == 1 && d >= 0))
		byt += _memncpy(op, &plus, 1);
	if (!(d == 0 && prc == 0))
		byt += con_sb(op, d, "0123456789", flag, 0, prc);
	byt += print_nw(op, byt, flag, width);
	return (byt);
}
/**
 * con_b - argment to binary
 * @arg: argments
 * @op: struct buf_t
 * @flag: flag mod
 * @width: width flag
 * @prc: percentage mod
 * @leng: length flag
 * Return: number of byte
 */
uint con_b(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	uint n;

	n = va_arg(arg, uint);

	(void)leng;
	return (con_ub(op, n, "01", flag, width, prc));
}
/**
 * con_o - argment to octal
 * @arg: point to argment
 * @op: buf_t struct
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of byte
 */
uint con_o(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	ulint n;
	uint byt = 0;
	char zero = '0';

	if (leng == LONG)
		n = va_arg(arg, ulint);
	else
		n = va_arg(arg, uint);
	if (leng == SHORT)
		n = (unsigned short)n;
	if (HASH_FLAGS == 1 &&  n != 0)
		byt += _memncpy(op, &zero, 1);
	if (!(n == 0 && prc == 0))
		byt += print_nw(op, byt, flag, width);

	return (byt);
}
/**
 * con_u - handle usigned
 * @arg: argments
 * @op: buf_t struct
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of byte
 */
uint con_u(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	ulint n;
	uint byt = 0;

	if (leng == LONG)
		n = va_arg(arg, ulint);
	else
		n = va_arg(arg, uint);
	if (leng == SHORT)
		n = (unsigned short)n;

	if (!(n == 0 && prc == 0))
		byt += con_ub(op, n, "0123456789", flag, width, prc);
	byt += print_nw(op, byt, flag, width);
	return (byt);
}
