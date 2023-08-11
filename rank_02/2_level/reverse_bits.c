
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int	i;
	unsigned char	result;

	i = 8;
	result = 0;
	while (i > 0)
	{
		result = octet * 2 + (octet % 2);
		octet /= 2;
		i--;
	}
	return (result);
}

int	main(void)
{
	// Ex: 0b00100110 = 38 -> 0b01100100 = 100
	printf("%hhu", reverse_bits(38));
	return (0);
}
