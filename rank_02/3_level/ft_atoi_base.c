
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	result;
	int	sig;

	sig = 1;
	i = 0;
	while (str[i] < 33)
		i++;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	result = 0;
	while (str[i] != '\0' && str[i] > 32)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= str_base;
			result += str[i] - 48;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			result *= str_base;
			result += str[i] - 55;
		}
		else if (str[i] >= 'a' && str[i] <= 'f')
		{
			result *= str_base;
			result += str[i] - 87;
		}
		i++;
	}
	return (result * sig);
}
/*
int	main(void)
{
	printf("%d\n", ft_atoi_base("  Ceci pe", 16));
	return (0);
}
*/
