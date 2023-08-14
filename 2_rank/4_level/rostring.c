
#include <unistd.h>
#include <stdlib.h>

#define WD_NUM 1000
#define WD_LEN 1000

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
	char	**wds;

	wds = (char **)malloc(sizeof(char *) * WD_NUM);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			k = 0;
			wds[j] = (char *)malloc(sizeof(char) * WD_LEN);
			while (str[i] > 32)
				wds[j][k++] = str[i++];
			wds[j++][k] = '\0';
		}
		else
			i++;
	}
	wds[j] = NULL;
	return (wds);
}

int	main(int ac, char *av[])
{
	int		i;
	char	**wds;

	i = 1;
	wds = NULL;
	if (ac > 1)
	{
		wds = ft_split(av[1]);
		while (wds[i] != NULL)
		{
			ft_putstr(wds[i]);
			write(1, " ", 1);
			free(wds[i]);
			i++;
		}
		ft_putstr(wds[0]);
		free(wds);
	}
	write(1, "\n", 1);
	return (0);
}
