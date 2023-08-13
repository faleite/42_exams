
#include <stdlib.h>
#include <stdio.h>

int	len_nbr(int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*arr;
	int		cpynu;

	if (nbr == -2147483648)
		return ("-2147483648");
	cpynu = nbr;
	len = len_nbr(nbr);
	if (nbr < 0)
	{
		cpynu *= -1;
		len++;
	}
	if (nbr == 0)
		return ("0");
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	if (nbr < 0)
		arr[0] = '-';
	arr[len] = '\0';
	while (cpynu)
	{
		arr[--len] = (cpynu % 10) + 48;
		cpynu /= 10;
	}
	return (arr);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa((0)));
// 	return (0);
// }
