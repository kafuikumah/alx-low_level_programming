#include "main.h"

/**
 *_strcat - Concatenates(joins) the string pointed to by @src,
 *	    to the end of tge string pointed to by @dest.+ terminating null byte
 *	    at the end
 * @dest: pointer to the string to be concatenated upon.
 * @src: pointer to source string to be appended to @dest.
 *
 * Return: Apointer to the destination string @dest.
 */

char *_strcat(char *dest, char *src)
{
	int aray = 0, d_count = 0;

	while (dest[aray++])
	{
		d_count++;
	}

	for (aray = 0; src[aray]; aray++)
	{
		dest[d_count++] = src[aray];
	}

	return (dest);
}
