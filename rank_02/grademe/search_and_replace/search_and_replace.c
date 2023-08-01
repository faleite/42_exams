#include <unistd.h>

void	search_and_replace(char *s1, char *s2, char *s3)
{
	/* int i = 0; */

	while (*s1)
	{
		if (s2[1] == '\0' && s3[1] == '\0')
		{
			if (*s1 == s2[0])
				write(1, &s3[0], 1);
			else 
				write(1, s1, 1);
		}
		s1++;
	}

}

int	main(int ac, char **av)
{
	if (ac == 4)
		search_and_replace(av[1], av[2], av[3]);
	write(1, "\n", 1);
	return (0);
}
