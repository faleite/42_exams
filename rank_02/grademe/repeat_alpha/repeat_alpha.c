#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			count = (str[i] - 65) + 1;
			while (count--)
				write(1, &str[i], 1);
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			count = (str[i] - 97) + 1;
			while (count--)
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		repeat_alpha(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}
