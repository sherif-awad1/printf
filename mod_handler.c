/*
 * File: mod_handler
 *
 * Author: Sherif AWad
 */
#include "main.h"
/**
 * print_wid - to print the width
 * @p: buf_t struct
 * @print: the number of char printed
 * @flag: flag mod
 * @width: width mod
 * Return: number of byts
 */
unsigned int print_wid(buf_t *p, unsigned int print, unsigned char flag, int width)
{
	unsigned int i = 0;
	char wid = ' ';

	if (
