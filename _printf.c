/*
 * File: _printf.c
 *
 * Author: Sherif Awad
 */
#include "main.h"
/**
 * cleaner - - clean operation for printf
 * @arg: argments pass to printf
 * @b: buf_t struct
 */
void cleaner(va_list arg, buf_t *b)
{
	va_end(arg);

