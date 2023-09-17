#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_string - prints a string
 * @str: the string to be printed
 * Return: numbers of characters printed
 */
int print_string(char *str)
{
	int char_pr = 0;

	while (*str)
	{
		write(1, str, 1);
		char_pr++;
		str++;
	}
	return (char_pr);
}

/**
 * _printf - prints output with specifiers
 * @format: the format string
 * @...: other arguments
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int char_pr = 0;
	va_list list_args;

	va_start(list_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_pr++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c_arg = va_arg(list_args, int);

				write(1, &c_arg, 1);
				char_pr++;
			}
			else if (*format == 's')
			{
				char *str_arg = va_arg(list_args, char*);

				char_pr += print_string(str_arg);
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				char_pr++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				char_pr += 2;
			}
		}
		format++;
	}
	va_end(list_args);
	return (char_pr);
}
