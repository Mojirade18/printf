#include "main.h"

/**
 * handle_write_char - Prints a character
 * @character: Character to be printed
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Active formatting flags
 * @printWidth: Width specifier
 * @precision: Precision specifier
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int handle_write_char(char character, char outputBuffer[],
	int activeFlags, int printWidth, int precision, int sizeSpecifier)
{
	int index = 0;
	char paddingChar = ' ';

	UNUSED(precision);
	UNUSED(sizeSpecifier);

	if (activeFlags & F_ZERO)
		paddingChar = '0';
	outputBuffer[index++] = character;
	outputBuffer[index] = '\0';
	if (printWidth > 1)
	{
		outputBuffer[BUFF_SIZE - 1] = '\0';
		for (index = 0; index < printWidth - 1; index++)
			outputBuffer[BUFF_SIZE - index - 2] = paddingChar;

		if (activeFlags & F_MINUS)
			return (write(1, &outputBuffer[0], 1) +
			write(1, &outputBuffer[BUFF_SIZE - index - 1], printWidth - 1));
		else
			return (write(1, &outputBuffer[BUFF_SIZE - index - 1],
				printWidth - 1) + write(1, &outputBuffer[0], 1));
	}
	return (write(1, &outputBuffer[0], 1));
}

/**
 * write_number - Prints a number
 * @isNegative: Flag indicating if the number is negative
 * @index: Index at which the number starts in the buffer
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Active formatting flags
 * @printWidth: Width specifier
 * @precision: Precision specifier
 * @sizeSpecifier: Size specifier
 * Return: Number of characters printed
 */
int write_number(int isNegative, int index, char outputBuffer[],
	int activeFlags, int printWidth, int precision, int sizeSpecifier)
{
	int length = BUFF_SIZE - index - 1;
	char paddingChar = ' ', extraChar = 0;

	UNUSED(sizeSpecifier);

	if ((activeFlags & F_ZERO) && !(activeFlags & F_MINUS))
		paddingChar = '0';

	if (isNegative)
		extraChar = '-';
	else if (activeFlags & F_PLUS)
		extraChar = '+';
	else if (activeFlags & F_SPACE)
		extraChar = ' ';
	return (write_num(index, outputBuffer, activeFlags,
		printWidth, precision, length, paddingChar, extraChar));
}

/**
 * write_num - Writes a number using a buffer
 * @index: Index at which the number starts in the buffer
 * @outputBuffer: Buffer array to handle print
 * @activeFlags: Active formatting flags
 * @printWidth: Width specifier
 * @precision: Precision specifier
 * @length: Number length
 * @paddingChar: Padding character
 * @extraChar: Extra character
 * Return: Number of printed characters
 */
int write_num(int index, char outputBuffer[], int activeFlags,
	int printWidth, int precision, int length, char paddingChar, char extraChar)
{
	int i, paddingStart = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 &&
		outputBuffer[index] == '0' && printWidth == 0)
		return (0);

	if (precision == 0 && index == BUFF_SIZE - 2 && outputBuffer[index] == '0')
		outputBuffer[index] = paddingChar = ' ';
	if (precision > 0 && precision < length)
		paddingChar = ' ';
	while (precision > length)
	{
		outputBuffer[--index] = '0';
		length++;
	}
	if (extraChar != 0)
		length++;

	if (printWidth > length)
	{
		for (i = 1; i < printWidth - length + 1; i++)
			outputBuffer[i] = paddingChar;
		outputBuffer[i] = '\0';

		if (activeFlags & F_MINUS && paddingChar == ' ')
		{
			if (extraChar)
				outputBuffer[--index] = extraChar;
			return (write(1, &outputBuffer[index],
				length) + write(1, &outputBuffer[1], i - 1));
		}
		else if (!(activeFlags & F_MINUS) && paddingChar == ' ')
		{
			if (extraChar)
				outputBuffer[--index] = extraChar;
			return (write(1, &outputBuffer[1], i - 1)
				+ write(1, &outputBuffer[index], length));
		}
		else if (!(activeFlags & F_MINUS) && paddingChar == '0')
		{
			if (extraChar)
				outputBuffer[--paddingStart] = extraChar;
			return (write(1, &outputBuffer[paddingStart], i - paddingStart) +
			write(1, &outputBuffer[index], length - (1 - paddingStart)));
		}
	}

	if (extraChar)
		outputBuffer[--index] = extraChar;
	return (write(1, &outputBuffer[index], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @isNegative: Number indicating if the num is negative
 * @index: Index at which the number starts in the buffer
 * @outputBuffer: Array of chars
 * @activeFlags: Flags specifiers
 * @printWidth: Width specifier
 * @precision: Precision specifier
 * @sizeSpecifier: Size specifier
 * Return: Number of written characters
 */
int write_unsgnd(int isNegative, int index, char outputBuffer[],
	int activeFlags, int printWidth, int precision, int sizeSpecifier)
{
	int length = BUFF_SIZE - index - 1, i = 0;
	char paddingChar = ' ';

	UNUSED(isNegative);
	UNUSED(sizeSpecifier);

	if (precision == 0 && index == BUFF_SIZE - 2 && outputBuffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		paddingChar = ' ';

	while (precision > length)
	{
		outputBuffer[--index] = '0';
		length++;
	}

	if ((activeFlags & F_ZERO) && !(activeFlags & F_MINUS))
		paddingChar = '0';
	if (printWidth > length)
	{
		for (i = 0; i < printWidth - length; i++)
			outputBuffer[i] = paddingChar;

		outputBuffer[i] = '\0';
		if (activeFlags & F_MINUS)
			return (write(1, &outputBuffer[index], length) +
			write(1, &outputBuffer[0], i));
		else
			return (write(1, &outputBuffer[0], i) +
				write(1, &outputBuffer[index], length));
	}
	return (write(1, &outputBuffer[index], length));
}

/**
 * write_pointer - Write a memory address
 * @outputBuffer: Array of chars
 * @index: Index at which the number starts in the buffer
 * @length: Length of number
 * @printWidth: Width specifier
 * @activeFlags: Flags specifier
 * @paddingChar: Char representing the padding
 * @extraChar: Char representing extra char
 * @paddingStart: Index at which padding should start
 * Return: Number of written characters.
 */
int write_pointer(char outputBuffer[], int index, int length,
	int printWidth, int activeFlags,
	char paddingChar, char extraChar, int paddingStart)
{
	int i;

	if (printWidth > length)
	{
		for (i = 3; i < printWidth - length + 3; i++)
			outputBuffer[i] = paddingChar;
		outputBuffer[i] = '\0';

		if (activeFlags & F_MINUS && paddingChar == ' ')
		{
			outputBuffer[--index] = 'x';
			outputBuffer[--index] = '0';
			if (extraChar)
				outputBuffer[--index] = extraChar;
			return (write(1, &outputBuffer[index],
			length) + write(1, &outputBuffer[3], i - 3));
		}
		else if (!(activeFlags & F_MINUS) && paddingChar == ' ')
		{
			outputBuffer[--index] = 'x';
			outputBuffer[--index] = '0';
			if (extraChar)
				outputBuffer[--index] = extraChar;
			return (write(1, &outputBuffer[3],
			i - 3) + write(1, &outputBuffer[index], length));
		}
		else if (!(activeFlags & F_MINUS) && paddingChar == '0')
		{
			if (extraChar)
				outputBuffer[--paddingStart] = extraChar;
			outputBuffer[1] = '0';
			outputBuffer[2] = 'x';
			return (write(1, &outputBuffer[paddingStart], i - paddingStart)
			+ write(1, &outputBuffer[index], length - (1 - paddingStart) - 2));
		}
	}
	outputBuffer[--index] = 'x';
	outputBuffer[--index] = '0';
	if (extraChar)
		outputBuffer[--index] = extraChar;
	return (write(1, &outputBuffer[index], BUFF_SIZE - index - 1));
}
