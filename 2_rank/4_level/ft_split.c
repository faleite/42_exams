
#include <stdlib.h>
#include <stdio.h>

#define WD_NUM 1000
#define WD_LEN 1000

/************/
/* Option 1 */ 
/************/
char	**ft_split(char *str)
{
	char	**arr;
	int		j;
	int		k;

	arr = (char **)malloc(sizeof(char *) * WD_NUM);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	j = 0;
	while (*str != '\0')
	{
		if (*str > 32)
		{
			k = 0;
			arr[j] = (char *)malloc(sizeof(char) * WD_LEN);
			while (*str > 32)
				arr[j][k++] = *str++;
			arr[j][k] = '\0';
			j++;
		}
		else
			str++;
	}
	arr[j] = 0;
	return (arr);
}

/************/
/* Option 2 */ 
/************/
void	copy_word(char **tab, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			k = 0;
			tab[j] = (char *)malloc(sizeof(char) * WD_LEN);
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
}

char	**ft_split(char *str)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * WD_NUM);
	copy_word(tab, str);
	return (tab);
}

// int	main(void)
// {
// 	char *str = "   lorem   ipsum dolor  consectetur.   Suspendisse  ";

// 	char **split_str = ft_split(str);

// 	while (*split_str)
// 		printf("%s\n", *split_str++);
// 	return (0);
// }
