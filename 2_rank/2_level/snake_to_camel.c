/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

Examples:
$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
*/
#include <unistd.h>

void	snake_to_camel(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '_')
		{
			i++;
			s[i] -= 32;
		}
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		snake_to_camel(av[1]);
	write(1, "\n", 1);
	return (0);
}
