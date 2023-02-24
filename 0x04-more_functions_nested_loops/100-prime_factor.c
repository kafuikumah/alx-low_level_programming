#include <stdio.h>

/**
 * main - Finds and prints the largest prime
 *        factor of the number 612852475143.
 *
 * Return: Always 0.
 */
int main(void)
{
	long int x = 612852475143;
	long int p;
	
	for (p = 2; p < x; p++)
	{
		if (x % p == 0)
 		{
 			x = x / p;
 		}
 	}
 	printf("%ld\n", p);
 	return (0);
 {
