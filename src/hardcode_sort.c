/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hardcode_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/08 14:43:21 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/08 14:57:44 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hardcoded_sort(t_list **stack_a, t_list **stack_b)
{
	printlist_next(ft_lstfirst(*stack_a));
	ft_printf("\n");
	if ((ft_lstfirst(*stack_a))->content > (ft_lstfirst(*stack_a))->next->content)
	{
		swap(stack_a, 'a');
	}
	else
	{
		push(stack_a, stack_b, 'b');
	}
	printlist_next(ft_lstfirst(*stack_a));
	ft_printf("\n");
	printlist_next(ft_lstfirst(*stack_b));
	// int	i = ft_lstsize(*stack_b);
	// while (i > 0)
	// {
	// 	push(stack_b, stack_a, 'a');
	// 	i--;
	// }

	// hardcoded_sort(stack_a, stack_b);
}
