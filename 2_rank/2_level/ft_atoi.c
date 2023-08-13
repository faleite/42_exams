
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sig;
	int res;

	i = 0;
	sig = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (0);
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res *= 10;
		res += str[i] - '0';
		++i;
	}
	return (res * sig);
}

// int	main(int argc, char *argv[])
// {
// 	(void)argc;
// 	printf("%d\n", ft_atoi(argv[1]));
// 	printf("%d\n", atoi(argv[1]));
// 	return (0);
// }
