/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linked_lists.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 14:11:43 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/17 16:28:20 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <ctype.h>

void	delete_first(t_list **test)
{
	t_list *temp;
	temp = ft_lstfirst(*test);
	//hmm
	temp->next = NULL;
	free(temp);
	
}

void	printlist_next(t_list *test)
{
	while (test != NULL)
	{
		ft_printf("%s\n", (char *)test->content);
		test = test->next;
	}
}

void	printlist_prev(t_list *test)
{
	while (test != NULL)
	{
		ft_printf("%s\n", (char *)test->content);
		test = test->prev;
	}
}

void	err_msg(char *str)
{
	write(STDERR_FILENO, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		err_msg(ERR_MSG);
	int		i = 0;
	t_list	**test;
	test = malloc(sizeof(t_list) * sizeof(t_list));
	while (i < (argc - 1))
	{
		if (!argv_check(argv[i+1]))
			err_msg(ERR_MSG);
		if (i == 0)
		{
			test[i] = ft_lstnew((void *)argv[i+1]);
			i++;
		}
		test[i] = ft_lstnew((void *)argv[i+1]);
		ft_lstadd_back(test, test[i]);
		i++;
	}
	ft_printf("Forward:\n");
	printlist_next(test[0]);
	ft_printf("\n");
	ft_printf("Backward:\n");
	printlist_prev(ft_lstlast(test[0]));
	// printlist_next(test[4]);
	// test[10] = ft_lstnew((void *)211);
	// ft_lstadd_front(test, test[10]);
	// ft_printf("Added a new element?\n");
	// ft_printf("\n");
	// printlist_prev(ft_lstlast(test[0]));
	// ft_printf("Removed an element?\n");
	char *str = argv[3];
	int d = argv_check(str);
	ft_printf("arg checker? %i\n", d);


	return (0);
}
