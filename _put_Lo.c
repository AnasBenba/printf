#include "main.h"

/**
 * _put_Lo - Prints an unsigned long int argument as an octal number
 * @nb: The number to print
 * @flags: struct that contains the flags to use
 * Return: The number of characters printed
 */

int     _put_Lo(unsigned long int nb, flags_t flags)
{
	unsigned long int octal[22];
	int i, j, count;

	i = 0;
	j = 0;
	count = 0;
	if (flags.h == 1)
		nb = (unsigned short)nb;
	else if (flags.h == 2)
		nb = (unsigned char)nb;
	else if (flags.l == 1)
		nb = (unsigned long)nb;
	while (nb > 0)
	{
		octal[i] = nb % 8;
		nb /= 8;
		i++;
	}
	if (i == 0)
	{
		_putchar('0');
		return (1);
	}
	j = i - 1;
	if (flags.hash && octal[j] != 0)
		count += _putchar('0');
	while (j >= 0)
	{
		_putchar(octal[j] + '0');
		count++;
		j--;
	}
	return (count);
}
