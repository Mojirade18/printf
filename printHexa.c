#include "main.h"

/**
* print_hexa - Prints a hexadecimal number in lower or upper
*
* @argList: List of arguments
* @mapTo: Array of values to map the number to
* @outputBuffer: Buffer array to handle print
* @activeFlags: Calculates active flags
* @flagChar: Calculates active flags
* @printWidth: Width specifier
* @precision: Precision specification
* @size: Size specifier
*
* Return: Number of chars printed
*/

int print_hexa(va_list argList, char mapTo[], char outputBuffer[], int activeFlags, char flagChar, int printWidth, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(argList, unsigned long int);
	unsigned long int initialNumber = number;

	UNUSED(printWidth);
	number = convert_size_unsgnd(number, size);

	if (number == 0)
		outputBuffer[index--] = '0';
		outputBuffer[BUFF_SIZE - 1] = '\0';

		while (number > 0)
	{
		outputBuffer[index--] = mapTo[number % 16];
		number /= 16;
	}

	if (activeFlags & F_HASH && initialNumber != 0)
	{
		outputBuffer[index--] = flagChar;
		outputBuffer[index--] = '0';
	}

	index++;
	return (write_unsgnd(0, index, outputBuffer, activeFlags, printWidth, precision, size));
}
