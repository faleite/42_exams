/* 04 (ft_foreach)*/

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

#include <ft_list.h>

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

/* 05 (ft_list_remove_if)*/

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *cur;

	if (begin_list == NULL, || *begin_list == NULL)
		return ;
	cur = *begin_list;
	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur_>next, data_ref, cmp);
}

/* 10 (sort_list) */
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	swap;
	t_list *tmp;

	tmp = lst;
	while (lst->next != 0)
	{
		if (((cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next-data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

/* 01 (flood_fill)*/
void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;

	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}
