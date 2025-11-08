# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahja <abahja@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 00:01:16 by abahja            #+#    #+#              #
#    Updated: 2025/02/08 16:23:24 by abahja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Werror -Wextra -Wall
MAKEFLAGS += --no-print-directory
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
SRC = pipex.c pipex_tools.c  error_list.c finalstep.c tools2.c token.c
OBJ = $(SRC:.c=.o)

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
RESET = \033[0m

.SECONDARY : $(OBJ)
.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)
	@echo "$"                                                                                         \033[1;36m------PIPEX IS already set BY : abahja{h3nix}------\n$(RESET)"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)


$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@echo "||$(RED)tiki taka-->>$(GREEN)" $< "<--\033[1;36mbroski wait$(BLUE)|| \n |> ------cmd-------->"
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

