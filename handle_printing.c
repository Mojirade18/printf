#include "main.h"
#include <unistd.h>

typedef struct {
	char format;
	int (*function)(va_list, char[], int, int, int, int, int);
} FormatType;	

/**
 * handle_print - Prints an argument based on its type
 * @formatSpecifier: Formatted string in which to print the arguments
 * @list: List of arguments to be printed
 * @index: Current index
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Active formatting flags
 * @printWidth: Width specifier
 * @precision: Precision specification
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed or -1 on error
 */
int handle_print(const char *formatSpecifier,
		int *index, va_list list, char outputBuffer[],
int activeFlags, int printWidth, int precision, int sizeSpecifier)
{
	int i, unknownLength = 0, printedChars = -1;
	FormatType formatTypes[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL},
	};
	for (i = 0; formatTypes[i].format != '\0'; i++)
	{
	if (formatSpecifier[*index] == formatTypes[i].format)
	{
		return (formatTypes[i].function(list), outputBuffer,
		activeFlags, printWidth, precision, sizeSpecifier);
	}
	}

	if (formatTypes[i].format == '\0')
	{
		if (formatSpecifier[*index] == '\0')
		{
			return (-1);
		}
		unknownLength += write(1, "%%", 1);
		if (formatSpecifier[*index - 1] == ' ')
		{
			unknownLength += write(1, " ", 1);
		}
		else if (printWidth)
		{
			(*index)--;
			while (formatSpecifier[*index] != ' ' && formatSpecifier[*index] != '%')
			{
				(*index)--;
			}

			if (formatSpecifier[*index] == ' ')
			{
				(*index)--;
			}

		return (1);
		}
		unknownLength += write(1, &formatSpecifier[*index], 1);
		return (unknownLength);
	}

	return (printedChars);
}
