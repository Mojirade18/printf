#include <stdio.h>
#include "main.h"

/**
 * _strlen - prints number of characters in string
 * n: pointer to the number of string
 * Return: number counted
 */

int _strlen(char *n)
{
	int count = 0;

	while(n[count] != '\0')
	{
		count++;
	}

	return (count);
	
}
