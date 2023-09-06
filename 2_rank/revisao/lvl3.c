/*******************/
/* REVISAO LEVEL 2 */
/*******************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/** ADD_PRIME_SUM
* Assignment name  : add_prime_sum
* Expected files   : add_prime_sum.c
* Allowed functions: write, exit
* --------------------------------------------------------------------------------
*
* Write a program that takes a positive integer as argument and displays the sum
* of all prime numbers inferior or equal to it followed by a newline.
*
* If the number of arguments is not 1, or the argument is not a positive number,
* just display 0 followed by a newline.
*
* Yes, the examples are right.
*
* Examples:
*
* $>./add_prime_sum 5
* 10
* $>./add_prime_sum 7 | cat -e
* 17$
* $>./add_prime_sum | cat -e
* 0$
* $>
*/
int	is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= nb)
	{
		if (nb % i == 0)
		{
			if (nb == i)
				return (1);
			else
				break ;
		}
		i++;
	}
	return (0);
}

int	add_prime_sum(int nb)
{
	int i;
	int	res;

	i = 1;
	res = 0;
	while (i <= nb)
	{
		if (is_prime(i))
			res += i;
		i++;
	}
	return (res);
}

/** FT_ATOI_BASE
* Assignment name  : ft_atoi_base
* Expected files   : ft_atoi_base.c
* Allowed functions: None
* --------------------------------------------------------------------------------
*
* Write a function that converts the string argument str (base N <= 16)
* to an integer (base 10) and returns it.
*
* The characters recognized in the input are: 0123456789abcdef
* Those are, of course, to be trimmed according to the requested base. For
* example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
*
* Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
*
* Minus signs ('-') are interpreted only if they are the first character of the
* string.
*
* Your function must be declared as follows:
*
* int	ft_atoi_base(const char *str, int str_base);
*/

int	get_digit(const char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'A' && c <= 'F')
		return (c - 55);
	else if (c >= 'a' && c <= 'f')
		return (c - 87);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
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
	while (str[i] != '\0' && str[i] > 32)
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

// int	main(void)
// {
// 	printf("%d\n", ft_atoi_base("ff", 16));
// 	printf("%d\n", ft_atoi_base(" --Ceci pe", 16));
// 	printf("%d\n", ft_atoi_base("123", 4));
// }

/** FT_LIST_SIZE
* Assignment name  : ft_list_size
* Expected files   : ft_list_size.c, ft_list.h
* Allowed functions:
* --------------------------------------------------------------------------------
*
* Write a function that returns the number of elements in the linked list that's
* passed to it.
*
* It must be declared as follows:
*
* int	ft_list_size(t_list *begin_list);
*
* You must use the following structure, and turn it in as a file called
* ft_list.h:
*
* typedef struct    s_list
* {
*     struct s_list *next;
*     void          *data;
* }                 t_list;
*/

/* ft_list.h */
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	t_list	*list;
	int		i;

	list = begin_list;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

/** HIDENP
* Assignment name  : hidenp
* Expected files   : hidenp.c
* Allowed functions: write
* --------------------------------------------------------------------------------
*
* Write a program named hidenp that takes two strings and displays 1
* followed by a newline if the first string is hidden in the second one,
* otherwise displays 0 followed by a newline.
*
* Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
* find each character from s1 in s2, in the same order as they appear in s1.
* Also, the empty string is hidden in any string.
*
* If the number of parameters is not 2, the program displays a newline.
*
* Examples :
*
* $>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
* 1$
* $>./hidenp "abc" "2altrb53c.sse" | cat -e
* 1$
* $>./hidenp "abc" "btarc" | cat -e
* 0$
* $>./hidenp | cat -e
* $
* $>
*/
void	hidenp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s2[j] == s1[i])
			i++;
		j++;
	}
	if (s1[i] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

/** FT_RANGE / FT_RRANGE
* Assignment name  : ft_range
* Expected files   : ft_range.c
* Allowed functions: malloc
* --------------------------------------------------------------------------------
*
* Write the following function:
*
* int     *ft_range(int start, int end);
*
* It must allocate (with malloc()) an array of integers, fill it with consecutive
* values that begin at start and end at end (Including start and end !), then
* return a pointer to the first value of the array.
*
* Examples:
*
* - With (1, 3) you will return an array containing 1, 2 and 3.
* - With (-1, 2) you will return an array containing -1, 0, 1 and 2.
* - With (0, 0) you will return an array containing 0.
* - With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int     *ft_range(int start, int end)
{
	int	i;
	int	*tab;
	int	len;

	i = 0;
	len = ft_abs(end - start) + 1;
	tab = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		if (start < end)
			tab[i++] = start++; // For ft_rrange: tab[i++] = end--;
		else
			tab[i++] = start--; // For ft_rrange: tab[i++] = end++;
	}
	return (tab);
}

// int	main(void)
// {
// 	int	*tab;
// 	int	len;
//
// 	len = ft_abs(-3 - 0) + 1;
// 	tab = ft_range(-3, 1);
// 	while (len--)
// 		printf("%d ", *tab++);
// 	return (0);
// }

/** LCM
* Assignment name  : lcm
* Expected files   : lcm.c
* Allowed functions:
* --------------------------------------------------------------------------------
*
* Write a function who takes two unsigned int as parameters and returns the
* computed LCM of those parameters.
*
* LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
* integer divisible by the both integers.
*
* A LCM can be calculated in two ways:
*
* - You can calculate every multiples of each integers until you have a common
* multiple other than 0
*
* - You can use the HCF (Highest Common Factor) of these two integers and
* calculate as follows:
*
* 	LCM(x, y) = | x * y | / HCF(x, y)
*
*   | x * y | means "Absolute value of the product of x by y"
*
* If at least one integer is null, LCM is equal to 0.
*
* Your function must be prototyped as follows:
*
* unsigned int    lcm(unsigned int a, unsigned int b);
*/
unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int n;

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
		++n;
	}
	return (n);
}
// int	main(void)
// {
// 	printf("%d\n", lcm(10, 8));
// 	return (0);
// }

/** PGCD
* Assignment name  : pgcd
* Expected files   : pgcd.c
* Allowed functions: printf, atoi, malloc, free
* --------------------------------------------------------------------------------
*
* Write a program that takes two strings representing two strictly positive
* integers that fit in an int.
*
* Display their highest common denominator followed by a newline (It's always a
* strictly positive integer).
*
* If the number of parameters is not 2, display a newline.
*
* Examples:
*
* $> ./pgcd 42 10 | cat -e
* 2$
* $> ./pgcd 42 12 | cat -e
* 6$
* $> ./pgcd 14 77 | cat -e
* 7$
* $> ./pgcd 17 3 | cat -e
* 1$
* $> ./pgcd | cat -e
* $
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

// int main(int ac, char *av[])
// {
// 	if (ac == 3)
// 		pgcd(atoi(av[1]), atoi(av[2]));
// 	printf("\n");
// 	return (0);
// }
