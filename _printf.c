/*
 * File: _printf.c
 *
 * Author: Sherif Awad
 */
#include "main.h"
/**
 * cleaner - clean operation for printf
 * @arg: argments pass to _printf
 * @op: buf_t struct
 */
void cleaner(va_list arg, buf_t *op)
{
	va_end(arg);
	write(1, op->str, op->leng);
	free_buf(op);
}
/**
 * rprintf - handle format string for _printf
 * @format: string to print
 * @op: buf_t struct
 * @arg: argment
 * Return: byt
 */
int rprintf(cchr *format, va_list arg, buf_t *op)
{
	int i, width, prc, byt = 0;
	char tmp;
	uchr flag, leng;
	uint (*f)(va_list, buf_t *, uchr, int, int, uchr);

	for (i = 0; *(format + i); i++)
	{
		leng = 0;
		if (*(format + i) == '%')
		{
			tmp = 0;
			flag = flags_handler(format + i + 1, &tmp);
			width = width_handler(arg, format + i + tmp + 1, &tmp);
			prc = prc_handler(arg, format + i + tmp + 1, &tmp);
			leng = length_handler(format + i + tmp + 1, &tmp);
			f = specfi_handler(format + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				byt += f(arg, op, flag, width, prc, leng);
				continue;
			}
			else if (*(format + i + tmp + 1) == '\0')
			{
				byt = -1;
				break;
			}
		}
		byt += _memncpy(op, format + i, 1);
		i += (leng != 0) ? 1 : 0;
	}
	cleaner(arg, op);
	return (byt);
}
/**
 * _printf - stander format output
 * @format: pointer to string
 * Return: number of char peinted
 */
int _printf(cchr *format, ...)
{
	buf_t *op;
	va_list arg;
	int byt;

	if (format == NULL)
		return (-1);
	op = int_buf();
	if (op == NULL)
		return (-1);

	va_start(arg, format);
	byt = rprintf(format, arg, op);

	return (byt);
}
