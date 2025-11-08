# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abahja <abahja@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 13:00:24 by abahja            #+#    #+#              #
#    Updated: 2025/02/08 15:44:45 by abahja           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS := ft_atoi.c    ft_isalpha.c ft_memchr.c  ft_memset.c  ft_strlcat.c ft_strnstr.c	\
		ft_bzero.c   ft_isascii.c ft_memcmp.c  ft_strchr.c  ft_strlcpy.c ft_strrchr.c	\
		ft_calloc.c  ft_isdigit.c ft_memcpy.c  ft_strdup.c  ft_strlen.c  ft_substr.c	\
		ft_isalnum.c ft_isprint.c ft_memmove.c ft_strncmp.c ft_tolower.c ft_toupper.c	\
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c		\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCSB := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c  \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS := $(SRCS:.c=.o)

OBJSB := $(SRCSB:.c=.o)

CFLAGS := -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

bonus: $(OBJSB)
	@ar -crs $(NAME) $^

$(NAME): $(OBJS)
	@ar -crs $@ $^

%.o: %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJSB) $(OBJS)


fclean: clean
	@rm -f $(NAME)

.phony : fclean all re