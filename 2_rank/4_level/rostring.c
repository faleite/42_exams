
#include <unistd.h>
#include <stdlib.h>

#define WD_NUM 1000
#define WD_LEN 1000

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	**ft_split(char *s)
{
	char	**arr;
	int		j;
	int		k;

	arr = (char **)malloc(sizeof(char *) * WD_NUM);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		++s;
	j = 0;
	while (*s != '\0')
	{
		if (*s > 32)
		{
			arr[j] = (char *)malloc(sizeof(char) * WD_LEN);
			k = 0;
			while (*s > 32)
				arr[j][k++] = *s++;
			arr[j][k++] = '\0';
			j++;
		}
		else
			++s;
	}
	arr[j] = 0;
	return (arr);
}

int	main(int ac, char *av[])
{
	char	**arr;
	int		i;

	i = 1;
	if (ac > 1)
	{
		arr = ft_split(av[1]);
		while (arr[i] != 0)
		{
			ft_putstr(arr[i]);
			write(1, " ", 1);
			free(arr[i]);
			i++;
		}
		ft_putstr(arr[0]);
		free(arr[0]);
	}
	write(1, "\n", 1);
	free(arr);
	return (0);
}
