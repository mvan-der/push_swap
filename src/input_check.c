/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/17 15:40:08 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/17 16:40:30 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int argv_check(char *argv)
{
	int	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
			return (0);
		i++;
	}
	if (ft_atoi(argv) == -1)
		return (0);
	// check duplicates
	return (1);
}