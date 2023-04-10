#include "main.h"

/**
 * flip_bits - counts the number of bits to change
 * to get from one number to another
 * @n: first number
 * @m: second number
 * Return: returns the number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	// Calculate the bitwise XOR of n and m to get the bits that are different
	
	int c = 0;
	unsigned long int xor = n ^ m;
	
	// Count the number of bits that are different
	unsigned int c = 0;
	while (xor)
	{
		// Use the bitwise AND operator to check the rightmost bit of xor
		// If the bit is 1, increment the counter
		c += xor & 1;
		
		// Shift the bits of xor to the right by one position
		xor >>= 1;
	}

	// Return the total number of bits that are different
	return (c);
}

