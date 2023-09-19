#include "main.h"

/**
* print_pointer - Prints the value of a pointer variable
*
* @argList: List of arguments
* @outputBuffer: Buffer array to handle print
* @activeFlags: Calculates active flags
* @printWidth: Width specifier
* @precision: Precision specification
* @size: Size specifier
*
* Return: Number of chars printed.
*/

int print_pointer(va_list argList, char outputBuffer[], int activeFlags, int printWidth, int precision, int size)
{

	char extraChar = 0, paddingChar = ' ';
	int index = BUFF_SIZE - 2, length = 2, paddingStart = 1; /* length=2,
for '0x' */
	unsigned long numAddress;
	char hexMap[] = "0123456789abcdef";
	void *address = va_arg(argList, void *);

	UNUSED(printWidth);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
		
	outputBuffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	numAddress = (unsigned long)address;

	while (numAddress > 0)
	{
		outputBuffer[index--] = hexMap[numAddress % 16];
		numAddress /= 16;
		length++;
	}

	if ((activeFlags & F_ZERO) && !(activeFlags & F_MINUS))
		paddingChar = '0';

	if (activeFlags & F_PLUS)
		extraChar = '+', length++;

	else if (activeFlags & F_SPACE)
		extraChar = ' ', length++;

	index++;

	return (write_pointer(outputBuffer, index, length, printWidth,activeFlags, paddingChar, extraChar, paddingStart));
}
