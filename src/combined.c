/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   combined.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/08 11:44:19 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/08 12:42:56 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack, char c)
{
	if ((ft_lstfirst(*stack))->next)
	{
		swap_top(ft_lstfirst(*stack), (ft_lstfirst(*stack))->next);
		if (c == 'a')
			ft_printf("sa\n");
		else if (c =='b')
			ft_printf("sb\n");
	}
	else
		err_msg("uh oh..");
}

void	swap_2(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstfirst(*stack_a))->next)
		swap_top(ft_lstfirst(*stack_a), (ft_lstfirst(*stack_a))->next);
	if ((ft_lstfirst(*stack_b))->next)
		swap_top(ft_lstfirst(*stack_b), (ft_lstfirst(*stack_b))->next);
	ft_printf("ss\n");
}

void	push(t_list **stack_a, t_list **stack_b, char c)
{
	if (c == 'a')
	{
		push_top(stack_a, ft_lstfirst(*stack_b));
		delete_first(stack_b, ft_lstfirst(*stack_b));
		ft_printf("pa\n");
	}
	else if (c == 'b')
	{
		push_top(stack_b, ft_lstfirst(*stack_a));
		delete_first(stack_a, ft_lstfirst(*stack_a));
		ft_printf("pb\n");
	}
	else
		err_msg("uh oh..");
}

void	rotate_2(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'c');
	rotate(stack_b, 'c');
	ft_printf("rr\n");
}


void	rev_rot_2(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 'c');
	reverse_rotate(stack_b, 'c');
	ft_printf("rrr\n");
}
