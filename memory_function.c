/*
 * FILE: memory_function.c
 *
 * Author: Sherif Awad
 */
#include "main.h"
/**
 * _memncpy - copy n form memory of src
 * @op: buf_t struct
 * @src: sorc string
 * @n: number of byts to copy
 * Return: number of byts
 */
uint _memncpy(buf_t *op, cchr *src, uint n)
{
	uint i;

	for (i = 0; i < n; i++)
	{
		*(op->buf) = *(src + i);
		(op->leng)++;

		if (op->leng == 1024)
		{
			write(1, op->str, op->leng);
			op->buf = op->str;
			op->leng = 0;
		}
		else
			(op->buf)++;
	}
	return (n);
}
/**
 * free_buf - frees a buf_t struct
 * @op: buf_t struct
 */
void free_buf(buf_t *op)
{
	free(op->str);
	free(op);
}
/**
 * int_buf - intialises variable struct buf_t
 * Return: pointer
 */
buf_t *int_buf(void)
{
	buf_t *op;

	op = malloc(sizeof(buf_t));
	if (op == NULL)
		return (NULL);
	op->buf = malloc(sizeof(char) * 1024);
	if (op->buf == NULL)
	{
		free(op);
		return (NULL);
	}
	op->str = op->buf;
	op->leng = 0;
	return (op);
}
