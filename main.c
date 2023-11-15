#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%o", 1024);
	len2 = printf("%o", 1024);
	fflush(stdout);
	if (len != len2)
	{
		_printf("%o\n", 1024);
		printf("%o\n", 1024);
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
