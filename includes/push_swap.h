/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 14:09:42 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/06/07 16:13:28 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR_MSG "Error\n"

# include "../ft_printf/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

t_list		*ft_lstnew(int content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstfirst(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			argv_check(char *argv, t_list *test);
t_list		**init_stack_a(t_list **stack, char **argv);
void		printlist_next(t_list *stack);
void		printlist_prev(t_list *stack);
int			err_msg(char *str);
void		push_top(t_list **stack, t_list *elem);
void		swap_top(t_list *top, t_list *new_top);
void		delete_first(t_list **stack, t_list *del);
void		delete_last(t_list **stack, t_list *del);
void		rotate(t_list **stack);
void		reverse_rotate(t_list **stack);
void		ft_lstclear(t_list **lst);

// void		ft_lstdelone(t_list *lst, void (*del)(void *));
// void		ft_lstiter(t_list *lst, void (*f)(void *));
// t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), \
// void (*del)(void *));

#endif
