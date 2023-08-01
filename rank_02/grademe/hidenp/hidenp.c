#include <unistd.h>

void	hidep(char *s1, char *s2)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (s1[i])
	{
		while(s2[j])
		{
			if (s1[i] == s2[j])
			{
				c++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (s1[c] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int ac, char *av[])
{
	if (ac == 3)
	{
		hidep(av[1], av[2]);
	}
	write(1, "\n", 1);
	return (0);
}
