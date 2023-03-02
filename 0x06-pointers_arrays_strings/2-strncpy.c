#include "main.h"

/**
 * _strncpy - Copies a number of bytes from string src into dest
 * @dest: the string copy to copy to
 * @src: The source string.
 * @n: number of bytes to copied from src.
 *
 * Return: pointer to final result  string dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int arr = 0, src_count = 0;

	while (src[arr++])
	{
		src_count++;
	}

	for (arr = 0; src[arr] && arr < n; arr++)
	{
		dest[arr] = src[arr];
	}

	for (arr = src_count; arr < n; arr++)
	{
		dest[arr] = '\0';
	}

	return (dest);
}
