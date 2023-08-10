
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int 			i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		// 2 -> 0b00000010 >> 7 & 1 = 0 (take the last bit)
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

// int	main(void)
// {
// 	print_bits(2);
// 	return (0);
// }
