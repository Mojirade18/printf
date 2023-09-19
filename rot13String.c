#include "main.h"

/**
* print_rot13string - Print a string in rot13.
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

int print_rot13string(va_list argList, char outputBuffer[], int activeFlags,int printWidth, int precision, int size)

{
	char character;
	char *inputStr;
	unsigned int i, j;
	int count = 0;
	char inputAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char outputAlphabet[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	UNUSED(outputBuffer);
	UNUSED(activeFlags);
	UNUSED(printWidth);
	UNUSED(precision);
	UNUSED(size);

	inputStr = va_arg(argList, char *);
	if (inputStr == NULL)
		inputStr = "(AHYY)";

	for (i = 0; inputStr[i]; i++)
	{
		for (j = 0; inputAlphabet[j]; j++)
		{
			if (inputAlphabet[j] == inputStr[i])
			{
				character = outputAlphabet[j];
				write(1, &character, 1);
				count++;
				break;
			}
		}
		if (!inputAlphabet[j])
		{
			character = inputStr[i];
			write(1, &character, 1);
			count++;
		}
		}
	return (count);
}
