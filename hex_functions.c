/*
 * FILE: hex_functions
 *
 * Author: Sherif Awad
 */
#include "main.h"
/**
 * con_x - argment to hex
 * @arg: argments
 * @op: buf_t struct
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of byte
 */
uint con_x(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	ulint n;
	uint byt = 0;
	char *hax = "0x";

	if (leng == LONG)
		n = va_arg(arg, ulint);
	else
		n = va_arg(arg, uint);
	if (leng == SHORT)
		n = (unsigned short)n;
	if (HASH_FLAGS == 1 && n != 0)
		byt += _memncpy(op, hax, 2);
	if (!(n == 0 && prc == 0))
		byt += con_ub(op, n, "0123456789abcdef", flag, width, prc);
	byt += print_nw(op, byt, flag, width);

	return (byt);
}
/**
 * con_X - argment to HEX
 * @arg: argment
 * @op: buf_t struct
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of byte
 */
uint con_X(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	ulint n;
	uint byt = 0;
	char *haX = "0X";

	if (haX == LONG)
		n = va_arg(arg, ulint);
	else
		n = va_arg(arg, uint);
	if (leng == SHORT)
		n = (unsigned short)n;
	if (HASH_FLAGS == 1 && n != 0)
		byt += _memncpy(op, haX, 2);
	if (!(n == 0 && prc == 0))
		byt += con_ub(op, n, "0123456789ABCDEF", flag, width, prc);
	byt += print_nw(op, byt, flag, width);
	return (byt);
}
