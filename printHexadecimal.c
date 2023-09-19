#include "main.h"

/**
* print_hexadecimal - Prints an unsigned number in hexadecimal
notation
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

int print_hexadecimal(va_list argList, char outputBuffer[], int activeFlags,int printWidth, int precision, int size)
{
	return (print_hexa(argList, "0123456789abcdef", outputBuffer, activeFlags, 'x', printWidth, precision, size));
}
