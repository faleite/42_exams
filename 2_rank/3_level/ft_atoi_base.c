/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/
#include <stdio.h>

int	get_digit(char c)
{
	int	res;

	res = 0;
	if (c >= '0' && c <= '9')
		return (res = c - '0');
	else if (c >= 'A' && c <= 'F')
		return (res = c - 55);
	else if (c >= 'a' && c <= 'f')
		return (res = c - 87);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sig;
	int	res;

	i = 0;
	sig = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sig = -1;
		i++;
	}
	while (str[i] > 32 && str[i] != '\0')
	{
		if (get_digit(str[i]))
		{
			res *= str_base;
			res += get_digit(str[i]);
		}
		i++;
	}
	return (res * sig);
}
/*
int	main(void)
{
	printf("%d", ft_atoi_base(" ff", 16));
	return (0);
}
*/
