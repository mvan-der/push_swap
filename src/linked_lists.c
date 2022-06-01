/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_lists.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 14:11:43 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/01 16:19:30 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <ctype.h>

void	delete_first(t_list **stack)
{
	t_list	*temp;

	temp = ft_lstfirst(*stack);
	/*hmm
	*/
	temp->next = NULL;
	free(temp);
}

void	printlist_next(t_list *stack)
{
	while (stack != NULL)
	{
		ft_printf("%s\n", (char *)stack->content);
		stack = stack->next;
	}
}

void	printlist_prev(t_list *stack)
{
	while (stack != NULL)
	{
		ft_printf("%s\n", (char *)stack->content);
		stack = stack->prev;
	}
}

int	err_msg(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	*head_a = NULL;
	// t_list	*last_a = NULL;

	if (argc == 1)
		err_msg(ERR_MSG);
	stack_a = malloc(sizeof(t_list) * sizeof(t_list));
	init_stack(stack_a, argc, argv);
	head_a = stack_a[0];
	// last_a = ft_lstlast(head_a);
	ft_printf("Forward:\n");
	ft_printf("\n");
	// ft_printf("Backward:\n");

	printlist_next(head_a);

	ft_printf("\n");

	// swap top elements
	// head + head->next
	t_list	*temp = NULL;
	t_list	*temp2 = NULL;
	t_list	*temp3 = NULL;

	temp = head_a;
	temp2 = head_a->next;
	temp3 = head_a->prev;
	ft_printf("Forward:\n");
	head_a->next = temp;
	head_a = temp2;
	head_a->prev = temp3;
	printlist_next(head_a);
	ft_printf("\n");
	ft_printf("Backward:\n");
	printlist_prev(head_a);
	/* printlist_next(stack_a[4]);
	// stack_a[10] = ft_lstnew((void *)211);
	// ft_lstadd_front(stack_a, stack_a[10]);
	// ft_printf("Added a new element?\n");
	// ft_printf("\n");
	// printlist_prev(ft_lstlast(stack_a[0]));
	// ft_printf("Removed an element?\n");
	// char *str = argv[1];
	// int d = argv_check(str, stack_a[0]);
	// ft_printf("arg checker? %i\n", d);
	*/
	return (0);
}
