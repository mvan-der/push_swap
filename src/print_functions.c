/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 12:58:09 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/07 15:15:57 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlist_next(t_list *stack)
{
	while (stack != NULL)
	{
		ft_printf("%i\n", stack->content);
		stack = stack->next;
	}
}

void	printlist_prev(t_list *stack)
{
	while (stack != NULL)
	{
		ft_printf("%i\n", stack->content);
		stack = stack->prev;
	}
}

int	err_msg(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	system("leaks pushswap");
	exit(EXIT_FAILURE);
}
