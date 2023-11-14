/*
 * File: mod_handler
 *
 * Author: Sherif AWad
 */
#include "main.h"
/**
 * print_w - print width
 * @op: buf_t struct
 * @print: number of char printed
 * @flag: flag mod
 * @width: width mod
 * Return: number of byts
 */
uint print_w(buf_t *op, uint print, uchr flag, int width)
{
	uint byt = 0;
	char wid = ' ';

	if (NEGTIV_FLAGS == 0)
	{
		for (width -= print; width > 0;)
			byt += _memncpy(op, &wid, 1);
	}
	return (byt);
}
/**
 * print_sw - print string width
 * @op: buf_t struct
 * @flag: flag mod
 * @width: width mod
 * @prc: percentage mod
 * @size: size of string
 * Return: numbet of bytes
 */
uint print_sw(buf_t *op, uchr flag, int width, int prc, int size)
{
	uint byt = 0;
	char wid = ' ';

	if (NAGTIV_FLAGS == 0)
	{
		width -= (prc == -1) ? size : prc;
		for (; width > 0; width--)
			byt += _memncpy(op, &wid, 1);
	}
	return (byt);
}
/**
 * print_nw - print negtive width
 * @op: buf_t struct
 * @print: number of bytes
 * @flag: flag mod
 * @width: width mod
 * Return: number of byte
 */
uint print_nw(buf_t *op, uint print, uchr flag, int width)
{
	uint byt = 0;
	char wid = ' ';

	if (NAGTIV_FLAGS == 1)
	{
		for (width -= print; width > 0; width--)
			byt += _memncpy(op, &wid, 1);
	}
	return (byt);
}
