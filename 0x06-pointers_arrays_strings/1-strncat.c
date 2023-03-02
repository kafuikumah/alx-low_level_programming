#include "main.h"

/**
 * _strncat - Concatenates two strings using
 *            inputted number of bytes from @src.
 * @dest: pointer to destination to be appended upon.
 * @src: pointer to string to be appended to dest.
 * @n: The number of bytes from src to be appended to dest.
 *
 * Return: A pointer to the resulting string dest.
 */

char *_strncat(char *dest, char *src, int n)
{
	int arr = 0, d_count = 0;

	while (dest[arr++])
	{
		d_count++;
	}

	for (arr = 0; src[arr] && arr < n; arr++)
	{
		dest[d_count++] = src[arr];
	}

	return (dest);
}
