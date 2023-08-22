#include "main.h"

/**
 * get_precision - Entry point
 * @p: string format
 * @params: Struct parameter
 * @ap: pointer argument
 *
 * Return: a new pointer
 */
char *get_precision(char *s, params_t *params, va_list ap)
{
	int j = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		j = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			j = j * 10 + (*s++ - '0');
	}
	params->precision = j;
	return (s);
}
