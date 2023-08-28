/*
Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its first word, followed by a
newline.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...    is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
*/

/* 
- O numero de parametros tem que ser 1 ou seja argc == 2 (arq + param)
- Enquanto o caracter do param for == space ou tab incremente "i".
- Enquanto o caracter do param for != space ou tab, escreva e incremente "i".
- Escreva a quebra de linha
*/

#include <unistd.h>

void	first_word(char *s)
{
	int	i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] != '\0' && (s[i] != ' ' && s[i] != '\t'))
		write(1, &s[i++], 1);
}

int	main(int ac, char *av[])
{
	if (ac == 2)
		first_word(av[1]);
	write(1, "\n", 1);
	return (0);
}
