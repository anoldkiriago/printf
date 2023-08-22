#include "main.h"

/**
 * print_hex - Entry point
 * @ap: passed argument
 * @params: struct parameter
 *
 * Return: bytes printed
 */
int print_hex(va_list ap, params_t *params)
{
	unsigned long m;
	
	char *str;

	if (params->h_modifier)
		m = (unsigned long)va_arg(ap, unsigned long);
	else if (params->l_modifier)
		m = (unsigned short int)va_arg(ap, unsigned int);
	else
		m = (unsigned int)va_arg(ap, unsigned int);

	str = convert(m, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && m)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return print_number(str, params);
}

/**
 * print_HEX - Entry point
 * @ap: passed argument
 * @params: struct parameter
 *
 * Return: bytes printed
 */
int print_HEX(va_list ap, params_t *params)
{
	unsigned long m;

	char *str;

	if (params->l_modifier)
		m = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		m = (unsigned short int)va_arg(ap, unsigned int);
	else
		m = (unsigned int)va_arg(ap, unsigned int);

	str = convert(m, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && m)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return  print_number(str, params);
}
/**
 * print_binary - Entry point
 * @ap: passed argument
 * @params: struct parameter
 *
 * Return: bytes printed
 */
int print_binary(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);


	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return print_number(str, params);
}

/**
 * print_octal - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list ap, params_t *params)
{
	unsigned long m;
	char *str;


	if (params->h_modifier)
		m = (unsigned long)va_arg(ap, unsigned long);
	else if (params->l_modifier)
		m = (unsigned short int)va_arg(ap, unsigned int);
	else
		m = (unsigned int)va_arg(ap, unsigned int);
	str = convert(m, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && m)
		*--str = '0';
	params->unsign = 1;
	return print_number(str, params);
}
