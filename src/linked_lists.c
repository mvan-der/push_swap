/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_lists.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 14:11:43 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/07 16:17:07 by mvan-der      ########   odam.nl         */
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
	t_list	*head_a = NULL;
	t_list	*head_b = NULL;

	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_a = malloc(sizeof(t_list) * sizeof(t_list));
	stack_b = malloc(sizeof(t_list) * sizeof(t_list));
	stack_a = init_stack_a(stack_a, argv); //uses malloc internally
	head_a = ft_lstfirst(*stack_a);
	ft_printf("address head a: %p\n", &head_a);
	while (*stack_a)
	{
		ft_printf("stack pointers: %p\n", &stack_a);
		stack_a++;
	}
	ft_printf("Stack a\n");
	ft_printf("Before top swap:\n");
	printlist_next(ft_lstfirst(*stack_a));
	ft_printf("\n");
	printlist_prev(ft_lstlast(head_a));
	ft_printf("\n");
	if(head_a->next)
	{
		swap_top(ft_lstfirst(*stack_a), head_a->next);
		head_a = ft_lstfirst(*stack_a);
	}
	ft_printf("After top swap:\n");
	printlist_next(head_a);
	ft_printf("\n");
	//push top a to top b;
	//copy first node in a to b, update head_b;
	ft_printf("Push top a to top b\n");
	push_top(stack_b, head_a); //uses malloc internally
	head_b = ft_lstfirst(*stack_b);
	ft_printf("address head b: %p\n", &head_b);
	ft_printf("Stack b\n");
	printlist_next(head_b);
	ft_printf("\n");
	//delete first node in a and update head_a;
	delete_first(stack_a, head_a);
	head_a = ft_lstfirst(*stack_a);
	ft_printf("Stack a\n");
	printlist_next(head_a);
	ft_printf("\n");
	ft_printf("Rotate a?\n");
	rotate(stack_a); //uses malloc internally
	head_a = ft_lstfirst(*stack_a);
	printlist_next(head_a);
	ft_printf("\n");
	ft_printf("Reverse rotate a?\n");
	reverse_rotate(stack_a); //uses malloc internally
	head_a = ft_lstfirst(*stack_a);
	printlist_next(head_a);
	ft_printf("\n");
	// free(head_a);
	// free(head_b);
	// ft_printf("clearing stuff.. unsuccesfully :S\n");
	// ft_lstclear(stack_a);
	// ft_lstclear(stack_b);
	system("leaks pushswap");
	return (0);
}
