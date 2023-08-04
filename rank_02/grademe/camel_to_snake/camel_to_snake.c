#include <unistd.h>

void	camel_to_snake(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			write(1, &str[i++], 1);
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
			write(1, "_", 1);
			write(1, &str[i++], 1);
		}
		else
			i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		camel_to_snake(av[1]);
	write(1, "\n", 1);
	return (0);
}
