#include "main.h"

/**
 * convert - Entry point
 * @num: my number
 * @base: the base
 * @flags: argument flags
 * @params: struct parammeter
 *
 * Return: a  string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long x = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		x = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[x % base];
		x /= base;
	} while (x != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - Entry point
 * @ap: pointer argument
 * @params: struct argument
 *
 * Return: bytes printed
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long m;

	if (params->h_modifier)
		m = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		m = (unsigned short int)va_arg(ap, unsigned int);
	else
		m = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(m, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * print_address - Entry point
 * @ap: pointer
 * @params: struct parameter
 *
 * Return: bytes printed
 */
int print_address(va_list ap, params_t *params)
{
	unsigned long int x = va_arg(ap, unsigned long int);
	char *str;

	if (!x)
		return (_puts("(nil)"));

	str = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}
