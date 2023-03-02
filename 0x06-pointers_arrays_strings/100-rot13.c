#include "main.h"

/**
 * rot13 - Encodes a string using rot13;rotating tthe char 13 spaces
 * @s: string to be encoded
 *
 * Return: pointer to the encoded string.
 */

char *rot13(char *s)
{
	int i, j;
	char rotated_alphabet[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char boolean;

	for (i = 0; s[i] != '\0'; i++)
	{
		boolean = 0;
		for (j = 0; alphabet[j] != '\0' && boolean == 0; j++)
		{
			if (s[i] == alphabet[j])
			{
				s[i] = rotated_alphabet[j];
				boolean = 1;
			}
		}
	}
	return (s);
}
