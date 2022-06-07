# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/16 16:32:49 by mvan-der      #+#    #+#                  #
#    Updated: 2022/06/07 13:02:46 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BLU = \033[0;34m
GRN = \033[0;32m
RED = \033[0;31m
RST = \033[0m
END = \e[0m

NAME = pushswap

HEADERS = push_swap.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I includes

LIBFTPRINTF = ./ft_printf/libftprintf.a

SRCDIR = src/
OBJDIR = obj/
SRC = ft_list_funcs.c ft_lstsize.c linked_lists.c input_check.c operations.c print_functions.c
# ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c 
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)
	@echo "${GRN}[Everything is up-to-date]${RST}"

$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFTPRINTF)
	@echo "${GRN}[$(NAME)]${RST}"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	$(MAKE) -C ./ft_printf

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C ./ft_printf $@
	@echo "${GRN}[CLEAN]${RST}"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./ft_printf $@
	@echo "${GRN}[FCLEAN]${RST}"

re: fclean
	$(MAKE)

.PHONY: all clean fclean re
