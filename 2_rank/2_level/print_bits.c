
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	bit = 0;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int	main(void)
{
	write(1, "0b", 2);
	print_bits(6);
	write(1, "\n", 2);
	return (0);
}
