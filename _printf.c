#include "main.h"
#include <stdio.h>
/**
 * _printf - entry point
 * @format: my format string
 *
 * Return: no. of bytes
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list an;
	char *n, *start;
	params_t params = PARAMS_INIT;

	va_start(an, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (n = (char *)format; *n; n++)
	{
		init_params(&params, an);
		if (*n != '%')
		{
			sum += putchar(*n);
			continue;
		}
		start = n;
		n++;
		while (get_flag(n, &params)) /* while char at n is flag char */
		{
			n++; /* next char */
		}
		n = get_width(n, &params, an);
		n = get_precision(n, &params, an);
		if (get_modifier(n, &params))
			n++;
		if (!get_specifier(n))
			sum += print_from_to(start, n,
				params.l_modifier || params.h_modifier ? n - 1 : 0);
		else
			sum += get_print_func(n, an, &params);
	}
	putchar(BUF_FLUSH);
	va_end(an);
	return (sum);
}
