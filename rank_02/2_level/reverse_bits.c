/*
Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char	reverse_bits(unsigned char octet);

Example:

  1 byte
_____________
 0010  0110
	 ||
	 \/
 0110  0100
 */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	result;

	i = 8;
	result = 0;
	while (i)
	{
		result = result * 2 + (octet % 2);
		octet /= 2;
		--i;
	}
	return (result);
}

int	main(void)
{
	// Ex: 0b00100110 = 38 -> 0b01100100 = 100
	printf("%hhu", reverse_bits(38));
	return (0);
}
