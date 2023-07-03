/*** Subject ***//*

Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

*//*** Code ***/

#include <unistd.h>

void	epur_str(char *s)
{
	int i = 0;
	
	while (s[i] < 33 && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] < 33)
		{
			if (s[i + 1] > 32 && s[i + 1] != '\0')
				write(1, " ", 1);
		}
		else if (s[i] != ' ' && s[i] != '\t')
			write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		epur_str(av[1]);
	write(1, "\n", 1);
	return (0);
}
