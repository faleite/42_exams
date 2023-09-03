/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/
#include <stdlib.h>
#include <stdio.h>

int	len_nbr(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;

	if (nbr == 0)
		return ("0");
	if (nbr == -2147483648)
		return ("-2147483648\0");
	len = len_nbr(nbr);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	str[--len] = '\0';
	while (nbr)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}
/*
int	main(void)
{
	printf("%s\n", ft_itoa(12345));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-12345));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483648));
}
*/
