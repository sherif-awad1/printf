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
void cleaner(va_list arg, buf_t *op)
{
	va_end(arg);
	write(1, op->str, op->leng);
	free_buf(op);
}
