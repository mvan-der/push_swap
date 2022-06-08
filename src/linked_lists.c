/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_lists.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 14:11:43 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/08 14:53:11 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <ctype.h>

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
	t_list	**stack_a;
	t_list	**stack_b;
	//some global struct with relevant info?
	// t_info	storage;

	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_a = malloc(sizeof(t_list) * sizeof(t_list));
	stack_b = malloc(sizeof(t_list) * sizeof(t_list));
	stack_a = init_stack_a(stack_a, argv);
	if (argc <= 11)
		hardcoded_sort(stack_a, stack_b);
	// push(stack_a, stack_b, 'b');
	// swap(stack_a, 'a');
	// rotate(stack_a, 'a');
	// reverse_rotate(stack_a, 'a');
	// rotate_2(stack_a, stack_b);
	// rev_rot_2(stack_a, stack_b);
	// ft_printf("%s", storage.result);
	return (0);
}
