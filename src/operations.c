/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 13:00:09 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/07 16:12:41 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_list **stack, t_list *elem)
{
	int	i;

	i = 0;
	if (!stack[i])
		stack[i] = ft_lstnew(elem->content);
	else
	{
		i = ft_lstsize(*stack);
		stack[i] = ft_lstnew(elem->content);
		ft_lstadd_front(stack, stack[i]);
	}
}

void	swap_top(t_list *top, t_list *new_top)
{
	if (new_top->next != NULL)
	{
		top->next = new_top->next;
		new_top->next->prev = top;
	}
	else
		top->next = NULL;
	top->prev = new_top;
	new_top->next = top;
	new_top->prev = NULL;
}

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*new;

	temp = ft_lstfirst(*stack);
	new = ft_lstnew(temp->content);
	ft_lstadd_back(stack, new);
	delete_first(stack, ft_lstfirst(*stack));
}

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*new;

	temp = ft_lstlast(*stack);
	new = ft_lstnew(temp->content);
	ft_lstadd_front(stack, new);
	delete_last(stack, ft_lstlast(*stack));
}
