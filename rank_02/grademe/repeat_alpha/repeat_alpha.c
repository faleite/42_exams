#include <unistd.h>

void	repeat_alpha(char *str)
{
	int	i;
	int	mult;

	i = 0;
	mult = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			mult = (str[i] - 'A') + 1;
			while (mult--)
				write(1, &str[i], 1);		
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			mult = (str[i] - 'a') + 1;
			while (mult--)
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
		repeat_alpha(av[1]);
	write(1, "\n", 1);
	return (0);
}
