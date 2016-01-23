# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperraul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/14 16:14:09 by aperraul          #+#    #+#              #
#    Updated: 2016/01/03 14:43:38 by cchameyr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	sources/check_array.c \
		sources/check_linked.c \
		sources/compactor.c \
		sources/edit_square.c \
		sources/get_form.c \
		sources/lst_form.c \
		sources/lst_str.c \
		sources/main.c

OBJS =	check_array.o \
		check_linked.o \
		compactor.o \
		edit_square.o \
		get_form.o \
		lst_form.o \
		lst_str.o \
		main.o

LIBFT =	lib/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(OBJS): $(LIBFT)
	$(CC) $(FLAGS) -c $(SRCS)

$(LIBFT):
	make -C ./lib/

clean:
	rm -f $(OBJS)
	make clean -C ./lib/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/

re: fclean all
