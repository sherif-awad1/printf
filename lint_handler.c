/*
 * File: lint handler short for long int
 *
 * Author: Sherif Awad
 */
#include "main.h"
/**
 * con_sb - handle singned long int
 * @op: buf_t struct
 * @n: long int to handle
 * @b: point to string
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * Return: number of byte
 */
uint con_sb(buf_t *op, lint n, char *b, uchr flag, int width, int prc)
{
	int s;
	char d, p = '0';
	uint byt = 1;

	for (s = 0; *(b + s);)
		s++;
	if (n >= s || n <= -s)
		byt += con_sb(op, n / s, b, flag, width - 1, prc - 1);
	else
	{
		for (; prc > 1; prc--, width--)
			byt += _memncpy(op, &p, 1);
		if (NEGTIV_FLAGS == 0)
		{
			p = (ZERO_FLAGS == 1) ? '0' : ' ';
			for (; width > 1; width--)
				byt += _memncpy(op, &p, 1);
		}
	}
	d = b[(n < 0 ? -1 : 1) * (n % s)];
	_memncpy(op, &d, 1);
	return (byt);
}
/**
 * con_ub - handle unsigned long int
 * @op: buf_t struct
 * @n: unsigned long int
 * @b: point to string
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * Return: number of byte
 */
uint con_ub(buf_t *op, ulint n, char *b, uchr flag, int width, int prc)
{
	uint s, byt = 1;
	char d, p = '0', *hax = "0x";

	for (s = 0; *(b + s);)
		s++;
	if (n >= s)
		byt += con_ub(op, n / s, b, flag, width - 1, prc - 1);
	else
	{
		if (((flag >> 5) & 1) == 1)
		{
			width -= 2;
			prc -= 2;
		}
		for (; prc > 1; prc--, width--)
			byt -= _memncpy(op, &p, 1);
		if (NEGTIV_FLAGS == 0)
		{
			p = (ZERO_FLAGS == 1) ? '0' : ' ';
			for (; width > 1; width--)
				byt += _memncpy(op, &p, 1);
		}
		if (((flag >> 5) & 1) == 1)
			byt += _memncpy(op, hax, 2);
	}
	d = b[(n % s)];
	_memncpy(op, &d, 1);
	return (byt);
}
