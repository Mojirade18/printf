#include "main.h"

/**
* print_reverse - Prints reverse string.
*
* @argList: List of arguments
* @outputBuffer: Buffer array to handle print
* @activeFlags: Calculates active flags
* @printWidth: Width specifier
* @precision: Precision specification
* @size: Size specifier
*
* Return: Numbers of chars printed
*/

int print_reverse(va_list argList, char outputBuffer[], int activeFlags, int printWidth, int precision, int size)
{
	char *inputStr;
	int i, count = 0;

	UNUSED(outputBuffer);
	UNUSED(activeFlags);
	UNUSED(printWidth);
	UNUSED(size);

	inputStr = va_arg(argList, char *);

	if (inputStr == NULL)
	{
		UNUSED(precision);
		inputStr = ")Null(";
	}

	for (i = 0; inputStr[i]; i++)
	;

	for (i = i - 1; i >= 0; i--)
	{
		char character = inputStr[i];
		write(1, &character, 1);
		count++;
	}

	return (count);
}
