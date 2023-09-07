/*******************/
/* REVISAO LEVEL 4 */
/*******************/

#include <stdlib.h>
#include <stdio.h>

/** FLOOD_FILL
* Assignment name  : flood_fill
* Expected files   : *.c, *.h
* Allowed functions: -
* --------------------------------------------------------------------------------
*
* Write a function that takes a char ** as a 2-dimensional array of char, a
* t_point as the dimensions of this array and a t_point as the starting point.
*
* Starting from the given 'begin' t_point, this function fills an entire zone
* by replacing characters inside with the character 'F'. A zone is an group of
* the same character delimitated horizontally and vertically by other characters
* or the array boundry.
*
* The flood_fill function won't fill diagonally.
*
* The flood_fill function will be prototyped like this:
*   void  flood_fill(char **tab, t_point size, t_point begin);
*
* The t_point structure is prototyped like this:
*
* typedef struct  s_point
* {
*   int           x;
*   int           y;
* }               t_point;
*/

/** FT_LIST_FOREACH
* Assignment name  : ft_list_foreach
* Expected files   : ft_list_foreach.c, ft_list.h
* Allowed functions:
* --------------------------------------------------------------------------------
*
* Write a function that takes a list and a function pointer, and applies this
* function to each element of the list.
*
* It must be declared as follows:
*
* void    ft_list_foreach(t_list *begin_list, void (*f)(void *));
*
* The function pointed to by f will be used as follows:
*
* (*f)(list_ptr->data);
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

/** FT_LIST_REMOVE_IF
* Assignment name  : ft_list_remove_if
* Expected files   : ft_list_remove_if.c
* Allowed functions: free
* --------------------------------------------------------------------------------
*
* Write a function called ft_list_remove_if that removes from the
* passed list any element the data of which is "equal" to the reference data.
*
* It will be declared as follows :
*
* void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
*
* cmp takes two void* and returns 0 when both parameters are equal.
*
* You have to use the ft_list.h file, which will contain:
*
* $>cat ft_list.h
* typedef struct      s_list
* {
*     struct s_list   *next;
*     void            *data;
* }                   t_list;
* $>
*/

/** FPRIME
* Assignment name  : fprime
* Expected files   : fprime.c
* Allowed functions: printf, atoi
* --------------------------------------------------------------------------------
*
* Write a program that takes a positive int and displays its prime factors on the
* standard output, followed by a newline.
*
* Factors must be displayed in ascending order and separated by '*', so that
* the expression in the output gives the right result.
*
* If the number of parameters is not 1, simply display a newline.
*
* The input, when there is one, will be valid.
*
* Examples:
*
* $> ./fprime 225225 | cat -e
* 3*3*5*5*7*11*13$
* $> ./fprime 8333325 | cat -e
* 3*3*5*5*7*11*13*37$
* $> ./fprime 9539 | cat -e
* 9539$
* $> ./fprime 804577 | cat -e
* 804577$
* $> ./fprime 42 | cat -e
* 2*3*7$
* $> ./fprime 1 | cat -e
* 1$
* $> ./fprime | cat -e
* $
* $> ./fprime 42 21 | cat -e
* $
*/

/** SORT_INT_TAB
* Assignment name  : sort_int_tab
* Expected files   : sort_int_tab.c
* Allowed functions:
* --------------------------------------------------------------------------------
*
* Write the following function:
*
* void sort_int_tab(int *tab, unsigned int size);
*
* It must sort (in-place) the 'tab' int array, that contains exactly 'size'
* members, in ascending order.
*
* Doubles must be preserved.
*
* Input is always coherent.
*/

/** SORT_LIST
* Assignment name  : sort_list
* Expected files   : sort_list.c
* Allowed functions:
* --------------------------------------------------------------------------------
*
* Write the following functions:
*
* t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
*
* This function must sort the list given as a parameter, using the function
* pointer cmp to select the order to apply, and returns a pointer to the
* first element of the sorted list.
*
* Duplications must remain.
*
* Inputs will always be consistent.
*
* You must use the type t_list described in the file list.h
* that is provided to you. You must include that file
* (#include "list.h"), but you must not turn it in. We will use our own
* to compile your assignment.
*
* Functions passed as cmp will always return a value different from
* 0 if a and b are in the right order, 0 otherwise.
*
* For example, the following function used as cmp will sort the list
* in ascending order:
*
* int ascending(int a, int b)
* {
* 	return (a <= b);
* }
*/
