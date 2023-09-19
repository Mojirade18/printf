#include "main.h"

/**
* print_hexa_upper - Prints an unsigned number in upper hexadecimal
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

int print_hexa_upper(va_list argList, char outputBuffer[], int activeFlags, int printWidth, int precision, int size)
{
	return (print_hexa(argList, "0123456789ABCDEF", outputBuffer, activeFlags, 'X', printWidth, precision, size));
}
