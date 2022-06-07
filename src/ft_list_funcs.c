/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_funcs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 13:59:57 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/07 15:47:25 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstfirst(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*first;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	first = malloc(sizeof(t_list));
	if (!first)
		return ;
	first = ft_lstfirst(*lst);
	new->next = first;
	new->prev = NULL;
	first->prev = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = malloc(sizeof(t_list));
	if (!last)
		return ;
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

t_list	*ft_lstnew(int content)
{
	t_list	*newelem;

	newelem = malloc(sizeof(t_list));
	if (!newelem)
		return (NULL);
	newelem->content = content;
	newelem->next = NULL;
	newelem->prev = NULL;
	return (newelem);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = temp->next;
		free(temp);
	}
	*lst = 0;
}
