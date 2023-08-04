#include <unistd.h>

void	alpha_mirror(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = 155 - str[i];
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = 219 - str[i];
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		alpha_mirror(av[1]);
	write(1, "\n", 1);
	return (0);
}
