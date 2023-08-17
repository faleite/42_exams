
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LEVEL 3*/

/**
 * 01
 * Utils: putnbr, atoi, is_prime
 */
int	is_prime(int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		if (n % i == 0)
		{
			if (n == i)
				return (1);
			else
				break;
		}
		i++;
	}
	return (0);
}

int	add_prim_sum(int n)
{
	int i;
	int	result;

	if (n == 1)
		return (1);
	i = 2;
	result = 0;
	while (i <= n)
	{
		if (is_prime(i))
			result += i;
		i++;
	}
	return (result);
}

/* 05 */
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	return (1 + ft_list_size(begin_list->next));
}

/** 06 (ft_range)
 * utils: len_array
 */

int	len_array(int start, int end)
{
	if (end < 0)
		end *= -1;
	if (end > start)
		return ((end - start) + 1);
	if (end < start)
		return ((start - end) + 1);
	return (1);
}
/* meio da principal */
int	*ft_range(int start, int end)
{
	int	i;
	int	len;
	char *arr;

	i = 0;
	len = len_array(start, end);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = start;
		if (start < end)
			start++;
		else
			start--;
		i++;
	}
	return (arr);
}

/** 09 (lcm)
 * loop infinito while (1)
 */
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}

/** 11 (pgcd)
 *
 */
void	pgcd(int a, int b)
{
	if (a > 0 && b > 0)
	{
		while (a != b)
		{
			if (a > b)
				a -= b;
			else
				b -= a;
		}
	}
	printf("%d", a);
}
