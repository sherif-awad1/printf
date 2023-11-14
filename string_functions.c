/*
 * FILE: string_functions.c
 *
 * Author: Sherif Awad
 */
#include "main.h"
/**
 * con_s - convert argment to string
 * @arg: argment
 * @op: buf_t struct
 * @flag: flags mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: lenght mod
 * Return: number of byts
 */
uint con_s(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	char *str, *n = "(null)";
	int s;
	uint byt = 0;
	(void)flag;
	(void)leng;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (_memncpy(op, n, 6));
	for (s = 0; *(str + s);)
		s++;
	byt += print_sw(op, flag, width, prc, s);

	prc = (prc == -1) ? s : prc;
	while (*str != '\0' && prc > 0)
	{
		byt += _memncpy(op, str, 1);
		prc--;
		str++;
	}
	byt += print_nw(op, byt, flag, width);
	return (byt);
}
/**
 * con_S - convert argmet to strring
 * @arg: poiner to argment
 * @op: buf_t struct
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: lenght mod
 * Return: number of bytes
 */
uint con_S(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	char *str, *n = "(null)", *hex = "\\x", zero = '0';
	int s, i;
	uint byt = 0;

	(void)leng;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (_memncpy(op, n, 6));
	for (s = 0; str[s];)
		s++;

	byt += print_sw(op, flag, width, prc, s);

	prc = (prc == -1) ? s : prc;

	for (i = 0; *(str + i) != '\0' && i < prc; i++)
	{
		if (*(str + i) < 32 || *(str + i) >= 127)
		{
			byt += _memncpy(op, hex, 2);
			if (*(str + i) < 16)
				byt += _memncpy(op, &zero, 1);
			byt += con_ub(op, *(str + i), "0123456789ABCDEF", flag, 0, 0);
			continue;
		}
		byt += _memncpy(op, (str + i), 1);
	}
	byt += print_nw(op, byt, flag, width);
	return (byt);
}
/**
 * con_rev - reverses string
 * @arg: point to string to revers
 * @op: buf_t struct
 * @flag: flags mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of bytes
 */
uint con_rev(va_list arg, buf_t *op, uchr flag, int width, int prc, uchr leng)
{
	char *str, *n = "(null)";
	int s, last, i;
	uint byt = 0;

	(void)flag;
	(void)leng;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (_memncpy(op, n, 6));
	for (s = 0; (str + s);)
		s++;
	byt += print_sw(op, flag, width, prc, s);
	last = s - 1;
	prc = (prc == -1) ? s : prc;
	for (i = 0; last >= 0 && i < prc; i++)
	{
		byt += _memncpy(op, (str + last), 1);
		last--;
	}
	byt += print_nw(op, byt, flag, width);

	return (byt);
}
/**
 * con_R13 - convert string to rot13
 * @arg: point to string
 * @op: buf_t struct
 * @flag: flags mod
 * @width: width mod
 * @prc: percentage mod
 * @leng: length mod
 * Return: number of byts
 */
uint con_R13(va_list arg, buf_t *op, uchr flag, int width,  int prc, uchr leng)
{
	char *alph = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUBWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *n = "(null)";
	int i, j, s;
	uint byt = 0;

	(void)flag;
	(void)leng;

	str = va_arg(arg, char *);
	if (str == NULL)
		return (_memncpy(op, n, 6));
	for (s = 0; *(str + s);)
		s++;
	byt += print_sw(op, flag, width, prc, s);
	prc = (prc == -1) ? s : prc;
	for (i = 0; *(str + i) != '\0' && i < prc; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (*(str + i) == *(alph + j))
			{
				byt += _memncpy(op, (rot13 + j), 1);
				break;
			}
		}
		if (j == 52)
			byt += _memncpy(op, (str + i), 1);
	}
	byt += print_nw(op, byt, flag, width);

	return (byt);
}
