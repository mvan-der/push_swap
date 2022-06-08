/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 15:16:59 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/08 10:09:43 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_first(t_list **stack, t_list *del)
{
	*stack = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
}

void	delete_last(t_list **stack, t_list *del)
{
	t_list *temp;
	
	temp = ft_lstlast(*stack);
	temp->prev->next = NULL;
	free(del);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	// int		i;

	if (argc == 1)
		exit(EXIT_FAILURE);
	a = malloc(sizeof(t_list) * sizeof(t_list));
	a = init_stack_a(a, argv);
	printlist_next(ft_lstfirst(*a));
	system("leaks pushswap");
	return (0);
}
