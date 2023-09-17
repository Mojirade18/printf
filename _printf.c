#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - prints output with specifiers
 * @format: the format string
 * @...: other arguments
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int print_chars = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print_chars++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c_arg = va_arg(args, int);

				write(1, &c_arg, 1);
				print_chars++;
			}
			else if (*format == '%')
			{
				write(1, "%", 1);
				print_chars++;
			}
			else
			{
				write(1, "%", 1);
				write(1, format, 1);
				print_chars += 2;
			}
		}
		format++;
	}
	va_end(args);
	return (print_chars);
}

/**
 * print_string - prints a string
 * @str: the string to be printed
 * Return: numbers of characters printed
 */
int print_string(char *str)
{
	int print_chars = 0;

	while (*str)
	{
		write(1, str, 1);
	print_chars++;
		str++;
	}
	return (print_chars);
}
