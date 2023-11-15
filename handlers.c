/*
 * FILE: handlers
 *
 * Author: Sherif Awad
 */
#include "main.h"
/**
 * flags_handler - to handle flags
 * @flags: point to flag
 * @i: index counter
 * Return: byt
 */
uchr flags_handler(cchr *flags, char *i)
{
	int k, j;
	uchr byt = 0;
	flags_t flag[] = {
		{'+', PLUS},
		{' ', SPAC},
		{'#', HASH},
		{'0', ZERO},
		{'-', NEGTIV},
		{0, 0}
	};
	for (k = 0; flags[k]; k++)
	{
		for (j = 0; flag[j].flags != 0; j++)
		{
			if (flags[k] == flag[j].flags)
			{
				(*i)++;
				if (byt == 0)
					byt = flag[j].values;
				else
					byt |= flag[j].values;
				break;
			}
		}
		if (flag[j].values == 0)
			break;
	}
	return (byt);
}
/**
 * length_handler - handler length mod
 * @mod: point tp lenght mod
 * @i: index
 * Return: leng mod or 0
 */
uchr length_handler(cchr *mod, char *i)
{
	if (*mod == 'h')
	{
		(*i)++;
		return (SHORT);
	}
	else if (*mod == 'l')
	{
		(*i)++;
		return (LONG);
	}
	return (0);
}
/**
 * width_handler -handl width mod
 * @arg: argments
 * @mod: point to width mod
 * @i: index pointer
 * Return: width mod or 0
 */
int width_handler(va_list arg, cchr *mod, char *i)
{
	int j = 0;

	while ((*mod >= '0' && *mod <= '9') || (*mod == '*'))
	{
		(*i)++;

		if (*mod == '*')
		{
			j = va_arg(arg, int);
			if (j <= 0)
				return (0);
			return (j);
		}
		j *= 10;
		j += (*mod - '0');
		mod++;
	}

	return (j);
}
/**
 * prc_handler -handler percentage mod
 * @arg: argment
 * @mod: poiter to percentage mod
 * @i: index counter
 * Return: percentage value
 */
int prc_handler(va_list arg, cchr *mod, char *i)
{
	int j = 0;

	if (*mod != '.')
		return (-1);
	mod++;
	(*i)++;

	if ((*mod <= '0' || *mod > '9') && *mod != '*')
	{
		if (*mod == '0')
			(*i)++;
		return (0);
	}
	while ((*mod >= '0' || *mod <= 9) || (*mod == '*'))
	{
		(*i)++;

		if (*mod == '*')
		{
			j = va_arg(arg, int);
			if (j <= 0)
				return (0);
			return (j);
		}
		j *= 10;
		j += (*mod - '0');
		mod++;
	}
	return (j);
}
/**
 * *specfi_handler - handler specfier
 * @specfi: pointer ot specfier
 * Return: pointer to function
 */
uint (*specfi_handler(cchr *specfi))(va_list, buf_t *, uchr, int, int, uchr)
{
	int i;
	con_t con[] = {
		{'c', con_c},
		{'s', con_s},
		{'S', con_S},
		{'r', con_rev},
		{'R', con_R13},
		{'d', con_d},
		{'i', con_d},
		{'%', con_prc},
		{'b', con_b},
		{'u', con_u},
		{'o', con_o},
		{'x', con_x},
		{'X', con_X},
		{'p', con_p},
		{0, NULL}
	};

	for (i = 0; con[i].fun; i++)
	{
		if (con[i].specfi == *specfi)
			return (con[i].fun);
	}
	return (NULL);
}

