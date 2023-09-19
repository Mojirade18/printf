#include <stdarg.h>
#include <unistd.h>
#include "main.h"

void printBuffer(char buffer[], int *bufferIndex);

/**
 * _printf - Printf function
 *
 * @format: format string.
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printedChars = 0, totalPrintedChars = 0;
	int flags, width, precision, size, bufferIndex = 0;
	va_list args;
	char outputBuffer[BUFF_SIZE];

	if (format == NULL)
	return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			outputBuffer[bufferIndex++] = format[i];
			if (bufferIndex == BUFF_SIZE)
				printBuffer(outputBuffer, &bufferIndex);
			printedChars++;
		}
		else
		{
			printBuffer(outputBuffer, &bufferIndex);
			flags = getFlags(format, &i);
			width = getWidth(format, &i, args);
			precision = getPrecision(format, &i, args);
			size = getSize(format, &i);
			++i;
			printedChars = handlePrint(format, &i, args, outputBuffer,
					flags, width, precision, size);
		if (printedChars == -1)
			return (-1);
		totalPrintedChars += printedChars;
		}
	}
	printBuffer(outputBuffer, &bufferIndex);

	va_end(args);

	return (totalPrintedChars);
}

/**
 * printBuffer - Prints the contents of the buffer if it exists
 *
 * @buffer: Array of characters
 * @bufferIndex: Index at which to add the next
 * character, represents the length.
 */
void printBuffer(char buffer[], int *bufferIndex)
{
	if (*bufferIndex > 0)
		write(1, &buffer[0], *bufferIndex);

	*bufferIndex = 0;
}
