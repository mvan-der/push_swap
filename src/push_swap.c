/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 15:16:59 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/07 15:18:42 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	**a;

	if (argc == 1)
		exit(EXIT_FAILURE);
	a = init_stack_a(a, argv);
}
