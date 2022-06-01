/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 15:40:08 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/01 14:36:44 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	argv_check(char *argv, t_list *test)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atoi(argv) == -1)
		return (0);
	while (test != NULL)
	{
		if (!ft_strncmp(argv, (char *)test->content, ft_strlen(argv)))
			return (0);
		test = test->next;
	}
	return (1);
}

void	init_stack(t_list **stack, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		if (argv_check(argv[i + 1], stack[0]) == 0)
			err_msg(ERR_MSG);
		if (i == 0)
		{
			stack[i] = ft_lstnew((void *)argv[i + 1]);
			i++;
		}
		else
		{
			stack[i] = ft_lstnew((void *)argv[i + 1]);
			ft_lstadd_back(stack, stack[i]);
			i++;
		}
	}
}
