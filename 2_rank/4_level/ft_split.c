#include <stdlib.h>

# define w_n 1000
# define w_l 1000

char	**split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char **tab;
	
	tab = (char **)malloc(sizeof(char) * w_n);
	while (str[i] == ' ' || str[i] == 't' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32) // printables
		{
			k = 0;
			tab[j] = (char *)malloc(sizeof(char) * w_l);
			while (str[i] > 32)
			{
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}

#include <stdio.h>

int	main(void)
{
	char *str = "   lorem   ipsum dolor  consectetur.   Suspendisse  ";

	char **split_str = split(str);

	while (*split_str)
		printf("%s\n", *split_str++);
	return (0);
}
