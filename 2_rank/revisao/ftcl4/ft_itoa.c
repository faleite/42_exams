
#include <stdlib.h>
#include <stdio.h>

int	len_num(int nbr)
{
	int len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		cpyn;
	int		len;
	char	*arr;

	if (nbr == -2147483648)
		return ("-2147483648");
	if (nbr == 0)
		return ("0");
	cpyn = nbr;
	len = len_num(nbr);
	if (nbr < 0)
	{
		cpyn *= -1;
		len++;
	}
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	if (nbr < 0)
		arr[0] = '-';
	arr[len] = '\0';
	while (cpyn)
	{
		arr[--len] = (cpyn % 10) + 48;
		cpyn /= 10;
	}
	return (arr);
}

int	main(void)
{
	printf("%s", ft_itoa(1));
	return (0);
}
