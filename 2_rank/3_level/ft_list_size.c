/*
Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

/*************/
/* Option 01 */
/*************/
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

/*************/
/* Option 02 */
/*************/
int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	return (1 + ft_list_size(begin_list->next));
}

/*****************/
/* Just for test */
/*****************/
int	main(void)
{
	// Criando uma lista encadeada simples
	t_list	*list = NULL;

	// Adicionando elemntos a lista
	t_list *node1 = malloc(sizeof(t_list));
	node1->data = "Item 1";
	node1->next = NULL;

	t_list *node2 = malloc(sizeof(t_list));
	node2->data = "Item 2";
	node2->next = NULL;

	t_list *node3 = malloc(sizeof(t_list));
	node3->data = "Item 3";
	node3->next = NULL;

	// Ligando os elemntos
	node1->next = node2;
	node2->next = node3;

	// Definindo o inicio da lista
	list = node1;

	// Calculando o tamanho da lista
	int list_size = ft_list_size(list);

	printf("Tamanho da lista: %d\n", list_size);

	// Lembre-se de liberar a memória para os nós da lista
	free(node1);
	free(node2);
	free(node3);

	return (0);
}

