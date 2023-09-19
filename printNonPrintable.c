#include "main.h"

/**
* print_non_printable - Prints ascii codes in hexa of non printable chars
*
* @argList: List of arguments
* @outputBuffer: Buffer array to handle print
* @activeFlags: Calculates active flags
* @printWidth: Width specifier
* @precision: Precision specification
* @size: Size specifier
*
* Return: Number of chars printed
*/

int print_non_printable(va_list argList, char outputBuffer[], int
activeFlags, int printWidth, int precision, int size)
{
	int index = 0, offset = 0;
	char *inputStr = va_arg(argList, char *);
	UNUSED(activeFlags);
	UNUSED(printWidth);
	UNUSED(precision);
	UNUSED(size);

	if (inputStr == NULL)
		return (write(1, "(null)", 6));

	while (inputStr[index] != '\0')
	{
		if (is_printable(inputStr[index]))
			outputBuffer[index + offset] = inputStr[index];

		else
	offset += append_hexa_code(inputStr[index], outputBuffer, index + offset);
	index++;
	}
	
	outputBuffer[index + offset] = '\0';

	return (write(1, outputBuffer, index + offset));
}
