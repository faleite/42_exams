
#include <stdio.h>
#include <stdlib.h>

#define WD_NUM 1000
#define WD_LEN 1000

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		h;
	char	**array;

	i = 0;
	j = 0;
	array = (char **)malloc(sizeof(**array) * WD_NUM);
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			h = 0;
			array[j] = (char*)malloc(sizeof(char) * WD_LEN);
			while (str[i] > 32)
				array[j][h++] = str[i++];
			array[j][h++] = '\0';
			j++;
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}
