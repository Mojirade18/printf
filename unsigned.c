#include "main.h"

/**
* print_unsigned - Prints an unsigned number
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

	int print_unsigned(va_list argList, char outputBuffer[], int activeFlags, int printWidth, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(argList, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		outputBuffer[index--] = '0';
		
	outputBuffer[BUFF_SIZE - 1] = '\0';

		while (number > 0)
		{
			outputBuffer[index--] = (number % 10) + '0';
			number /= 10;
		}

		index++;

		return (write_unsgnd(0, index, outputBuffer, activeFlags, printWidth,precision, size));
}

