
#include <stdlib.h>
#include <stdio.h>

#define WD_NUM 1000
#define WD_LEN 1000

char    **ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * WD_NUM);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 32)
		{
			k = 0;
			arr[j] = (char *)malloc(sizeof(char) * WD_LEN);
			while (str[i] > 32)
				arr[j][k++] = str[i++];
			arr[j][k] = '\0';
			j++;
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}

int	main(void)
{
	char	str[] = " TEst  cego estpou\n etou na proxima \nlin	ha canzado oi  ";
	char 	**arr = ft_split(str);

	while (*arr)
	printf("%s\n", *arr++);
	return (0);
}
