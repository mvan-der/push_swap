/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_funcs.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 13:59:57 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/11 14:27:27 by mvan-der      ########   odam.nl         */
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
	t_list *first;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	first = malloc(sizeof(t_list));
	if(!first)
		return ;//?? void so just return? or exit? needs to be handled somehow rihgt?
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
		return ; // same thoughts as lst_add_front... needs to be handled somehow
	last = ft_lstlast(*lst);
	last->next = new;
	new->prev = last;
}

t_list	*ft_lstnew(void *content)
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