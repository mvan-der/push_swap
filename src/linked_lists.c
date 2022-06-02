/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_lists.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 14:11:43 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/02 12:10:47 by mvan-der      ########   odam.nl         */
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

void	swap(t_list *a)
{
	t_list	*b = NULL;
	t_list	*saved_prev = a -> prev;
	t_list	*saved_next = a -> next;

	a -> next = b -> next;
	a -> prev = b -> prev;

	if(b -> next)
		(b -> next) -> prev = a;
	if(b -> prev)
		(b -> prev) -> next = a;

	if(saved_prev)
		saved_prev -> next = b;
	if(saved_next)
		saved_next -> prev = b;

	b -> prev = saved_prev;
	b -> next = saved_next;
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	*head_a = NULL;
	// t_list	*last_a = NULL;

	if (argc == 1)
		exit(EXIT_FAILURE);;
	stack_a = malloc(sizeof(t_list) * sizeof(t_list));
	init_stack(stack_a, argc, argv);
	head_a = ft_lstfirst(*stack_a);
	// last_a = ft_lstlast(head_a);
	ft_printf("Forward:\n");
	printlist_next(head_a);
	ft_printf("\n");
	ft_printf("Backward:\n");
	printlist_prev(ft_lstlast(head_a));
	ft_printf("\n");

	// swap top elements
	// head + head->next
	// t_list	*temp = NULL;
	// t_list	*temp2 = NULL;
	// t_list	*temp3 = NULL;

	// swap(head_a);
	// ft_printf("Forward:\n");
	// printlist_next(head_a);
	// ft_printf("\n");
	// temp3 = head_a->prev;
	// head_a->next = temp;
	// head_a = temp2;
	// head_a->prev = temp3;
	// ft_printf("Forward:\n");
	// printlist_next(head_a);
	// ft_printf("\n");
	// ft_printf("Backward:\n");
	// printlist_prev(head_a);
	/* printlist_next(stack_a[4]);
	// stack_a[10] = ft_lstnew((void *)211);
	// ft_lstadd_front(stack_a, stack_a[10]);
	// ft_printf("Added a new element?\n");
	// ft_printf("\n");
	// printlist_prev(ft_lstlast(stack_a[0]));
	// ft_printf("Removed an element?\n");
	*/
	return (0);
}
