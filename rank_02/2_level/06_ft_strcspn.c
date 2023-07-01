/*** Subject ***/

/*
Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);
*/

/*** Man ***/

/*
STRCSPN(3)               BSD Library Functions Manual               STRCSPN(3)

NAME
	strcspn -- span the complement of a string

LIBRARY
	Standard C Library (libc, -lc)

SYNOPSIS
	#include <string.h>

	size_t
	strcspn(const char *s1, const char *s2);

DESCRIPTION
	The strcspn() function spans the initial part of the null-terminated string
	s1, as 	long as the characters from s1 do not occur in string s2 (it spans
	the complement of s2).  In other words, it computes the string 	array index
	in s1 of the first character of s1 which is also in s2, else the index of
	the first null character.

RETURN VALUES
	The strcspn() function returns the number of characters spanned.

SEE ALSO
	memchr(3), strchr(3), strpbrk(3), strrchr(3), strsep(3), strspn(3), 
	strstr(3), strtok(3)

STANDARDS
	The strcspn() function conforms to ISO/IEC 9899:1990 (``ISO C90'').

BSD                              June 4, 1993								BSD
*/

int	ft_strcspn(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;

	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
