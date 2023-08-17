
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/* Util de 05 */
char	*ft_strchr(const char *s, char c)
{
	while(*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

/* 05 */
size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((ft_strchr(accept, s[i]) == 0))
			break ;
		i++;
	}
	return (i);
}

/* 08 */
char	*ft_strpbrk(const char *s1, const char *s2)
{
	int		i;
	char	*str;

	str = (char *)s1;
	while (*str != '\0')
	{
		i = 0;
		while (s2[i] != '\0')
		{
			if (*str == s2[i])
				return (str);
			i++;
		}
	}
	return (NULL);
}

/* Utils 11 */
int	check_double(char *s, char c, int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

/* 11 */
void	inter(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				if (check_double(s1, s1[i], i))
				{
					write(1, &s1[i], 1);
					break ;
				}
			}
			j++;
		}
		i++;
	}
}

/* 12 */
int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	while (n % 2 == 0)
	{
		n /= 2;
		if (n == 1)
			return (1);
	}
	return (0);
}

/* 14 */
int	max(int *tab, unsigned int len)
{
	unsigned int i;

	if (len == 0)
		return (0);
	i = 0;
	while (len--)
	{
		if (tab[0] < tab[i])
		{
			tab[0] = tab[i];
		}
		i++;
	}
	return (tab[0]);
}

/* 15 */
void	print_bits(unsigned char octet)
{
	int	i;
	unsigned char bit;


	i = 8;
	bit = 0;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

/* 16 */
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char result;
	int i;

	i = 8;
	while (i)
	{
		result = result * 2 + (octet % 2);
		octet /= 2;
		--i;
	}
	return (result);
}

/* 18 */
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

/**
 * 19
 * Utils: ft_strlen check_double
 */
// int	check_double(char *s, char c, int pos)
// {
// 	int i;

// 	i = 0;
// 	while (i < pos)
// 	{
// 		if (s[i] == c)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
/* 19 */
void	ft_union(char *s1, char *s2)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (s2[i] != '\0')
		s1[len++] = s2[i++];
	i = 0;
	while (s1[i] != '\0')
	{
		if (check_double(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
}

/**
 * 20
 * Utils: strlen, strchr, len_wdmatch
 */
// char	*ft_strchr(const char *s, char c)
// {
// 	while (*s != '\0')
// 	{
// 		if (*s == c)
// 			return ((char *)s);
// 		++s;
// 	}
// 	return (0);
// }

int len_wdmatch(char *s1, char *s2)
{
	int i;
	int	len;

	i = 0;
	len = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(s2, s1[i]))
		{
			s2 = ft_strchr(s2, s1[i]);
			len++;
		}
	}
	return (len);
}

void	wdmatch(char *s1, char *s2)
{
	int i;
	int	len;

	len = len_wdmatch(s1, s2);
	i = 0;
	if (len == ft_strlen(s1))
	{
		while (s1[i] != '\0')
		{
			if (ft_strchr(s2, s1[i]))
			{
				s2 = ft_strchr(s2, s1[i]);
				write(1, &*s2, 1);
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
