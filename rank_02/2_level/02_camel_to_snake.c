/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/

#include <unistd.h>

/* math: char = char + 32 */
void	putchar(char c)
{
	write(1, &c, 1);
}

void	camel_snake(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			putchar('_');
			*str = *str + 32;
		}
		putchar(*str);	
		++str;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		camel_snake(av[1]);
	putchar('\n');
	return (0);
}
