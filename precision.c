#include "main.h"
/**
* get_precision - getsCalculates the precision for printing
* @format: Formatsted string in which to print the arguments
* @currentIndex: Current index in the format string
* @argList: List of arguments
* Return: Precision.
*/

int get_precision(const char *format, int *currentIndex, va_list argList)
{
	int currentIdx = *currentIndex + 1;
	int precision = -1;

	if (format[currentIdx] != '.')
		return precision;
		precision = 0; //need explination here, should there always be a . for this to work?

	for (currentIdx += 1; format[currentIdx] != '\0'; currentIdx++)
	{
		if (is_digit(format[currentIdx]))
		{
			precision *= 10;
			precision += format[currentIdx] - '0';
		}

		else if (format[currentIdx] == '*')
		{
			currentIdx++;
			precision = va_arg(argList, int);
			break;
		}
		
		else
		{
			break;
		}
	}

	*currentIndex = currentIdx - 1;
	return precision;
}
