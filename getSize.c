#include "main.h"

/**
* get_size - Calculates the size to cast the argument
*
* @formatString: Formatted string in which to print the arguments
* @currentIndex: Current index in the format string
*
* Return: Size specifier.
*/

int get_size(const char *formatString, int *currentIndex)
{
	int currentIdx = *currentIndex + 1;
	int sizeSpecifier = 0;

	if (formatString[currentIdx] == 'l')
		sizeSpecifier = S_LONG;

	else if (formatString[currentIdx] == 'h')
		sizeSpecifier = S_SHORT;

	if (sizeSpecifier == 0)
		*currentIndex = currentIdx - 1;

	else
		*currentIndex = currentIdx;

	return (sizeSpecifier);
}
