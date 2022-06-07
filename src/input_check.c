/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 15:40:08 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/07 15:13:24 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_check(char *argv, t_list *test)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[0] == '-')
			i++;
		else if(ft_isdigit(argv[i]) == 0)
			return (-1);
		i++;
	}
	if (ft_atoi(argv) == -1)
		return (-1);
	while (test != NULL)
	{
		if (ft_atoi(argv) == test->content)
			return (-1);
		else
			test = test->next;
	}
	return (0);
}

t_list	**init_stack_a(t_list **stack, char **argv)
{
	int	i;

	i = 0;
	argv++;
	while (*argv)
	{
		if (argv_check(*argv, stack[0]) == -1)
			err_msg(ERR_MSG);
		if (i == 0)
		{
			stack[i] = ft_lstnew(ft_atoi(*argv));
			argv++;
			i++;
		}
		else
		{
			stack[i] = ft_lstnew(ft_atoi(*argv));
			ft_lstadd_back(stack, stack[i]);
			argv++;
			i++;
		}
	}
	return (stack);
}
