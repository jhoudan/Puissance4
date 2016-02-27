#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klonger <klonger@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 10:50:51 by klonger           #+#    #+#              #
#    Updated: 2016/01/29 13:03:27 by mdezitte         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

HEADER = includes/libft.h

FLAGS = -Wall -Wextra -Werror

SRC = $(shell ls -1 | grep "\.c")

OBJET = $(SRC:%.c=obj/%.o)

all: prepare compile_lib $(NAME)

prepare:
		@/bin/mkdir -p obj/

norm:
		@norminette $(SRC) $(HEADER)

$(NAME): $(OBJET)
		@ar rc $@ $(OBJET)
		@ranlib $(NAME)

compile_lib:
		@echo "\033[31mCompiling Libft Please wait ...\033[39m"

obj/%.o: %.c
		@gcc $(FLAGS) -I includes/ -o $@ -c $<
		@printf "\033[35m. \033[39m"

clean:
		@/bin/rm -rf obj/

fclean: clean
		@/bin/rm -f $(NAME)

re: fclean all
