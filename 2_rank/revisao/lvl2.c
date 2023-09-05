/*******************/
/* REVISAO LEVEL 2 */
/*******************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

/** FT_STRCSPN
 * @brief The strcspn() function calculates the length of the initial
 * segment of s which consists entirely of bytes not in reject.
 * @return The strcspn() function returns the number of bytes in the initial
 * segment of s which are not in the string reject.
*/

/** FT_STRPBRK
 * @brief The strpbrk() function locates the first occurrence in the string s
 * of any of the bytes in the string accept.
 * @return The strpbrk() function returns a pointer to the byte in s
 * that matches one of the bytes in accept, or NULL if no such byte is found.
*/

/** FT_STRREV
 * @brief Write a function that reverses (in-place) a string.
 * It must return its parameter
*/

/** FT_STRSPN
 * @brief The strspn() function calculates the length (in bytes) of the initial
 * segment of s which consists entirely of bytes in accept.
 * @return returns the number of bytes in the initial segment of s which consist
 * only of bytes from accept.
*/
char	*ft_strchar(char const *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchar(accept, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

/* MAIN
int	main(void)
{
	char s1[] = "Teext string";
	char s2[] = "Tet";

	printf("%ld\n", strspn(s1, s2));
	printf("%ld", ft_strspn(s1, s2));
	return (0);
}
*/

/** INTER
* Assignment name  : inter
* Expected files   : inter.c
* Allowed functions: write
* --------------------------------------------------------------------------------
*
* Write a program that takes two strings and displays, without doubles, the
* characters that appear in both strings, in the order they appear in the first
* one.
*
* The display will be followed by a \n.
*
* If the number of arguments is not 2, the program displays \n.
*
* Examples:
*
* $>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
* padinto$
* $>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
* df6ewg4$
* $>./inter "rien" "cette phrase ne cache rien" | cat -e
* rien$
* $>./inter | cat -e
* $
*/
int	check_double(char *s, char c, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

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
			if (s2[j] == s1[i])
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

/* MAIN
int	main(int argc, char *argv[])
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
*/

/** IS_POWER_OF_2
* Assignment name  : is_power_of_2
* Expected files   : is_power_of_2.c
* Allowed functions: None
* --------------------------------------------------------------------------------
*
* Write a function that determines if a given number is a power of 2.
*
* This function returns 1 if the given number is a power of 2, otherwise it returns 0.
*
* Your function must be declared as follows:
*
* int	    is_power_of_2(unsigned int n);
*/
int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
	{
		n /= 2;
		if (n == 1)
			return (1);
	}
	return (0);
}
/* MAIN
int	main(void)
{
	printf("%d", is_power_of_2(1));
	return (0);
}
*/

/* WDMATCH */
char	*ft_strchar(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		++s;
	}
	return (0);
}

size_t	le_wdmatch(char *s1, char *s2)
{
	size_t	len;
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchar(s2, s1[i]))
		{
			s2 = ft_strchar(s2, s1[i]);
			len++;
		}
		i++;
	}
	return (len);
}

void	wdmatch(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchar(s2, s1[i]))
		{
			s2 = ft_strchar(s2, s1[i]);
			write(1, &*s2, 1);
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
	{
		if (strlen(argv[1]) == le_wdmatch(argv[1], argv[2]))
			wdmatch(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
