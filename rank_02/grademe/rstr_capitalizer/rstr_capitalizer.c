
#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] > 32 && str[i + 1] < 33)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (av[i] != NULL)
		{
			rstr_capitalizer(av[i++]);
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
