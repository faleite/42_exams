
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define WD_LEN 1000
#define WD_NUM 1000

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * WD_NUM);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			k = 0;
			tab[j] = (char *)malloc(sizeof(char) * WD_LEN);
			while (str[i] > 32)
				tab[j][k++] = str[i++];
			tab[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	**tab;

	tab = NULL;
	i = 0;
	if (argc == 2)
		tab = ft_split(argv[1]);
	while (tab[i] != '\0')
		i++;
	while (--i >= 0)
	{
		ft_putstr(tab[i]);
		if (i > 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return (0);
}
