# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/10 10:00:41 by mressier          #+#    #+#              #
#    Updated: 2016/02/27 15:07:14 by jhoudan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance4

HEADER = includes/puissance.h

CORE = alloc_struct.c \
		error.c \
		free.c \
		init_game.c \
		read_one_line.c \
		main.c


CHECK = checker.c \

TERMCAP = get_values.c \
		init_terminal.c

ifdef DEBUG
FLAGS = -Wall -Werror -Wextra -g

else
FLAGS = -Wall -Werror -Wextra
endif

LIB = libft

SRC_CORE = $(addprefix Core/, $(CORE))

SRC_CHECK = $(addprefix Check/, $(CHECK))

SRC_TERMCAP = $(addprefix Termcap/, $(TERMCAP))

SRC = $(SRC_CORE) $(SRC_CHECK) $(SRC_TERMCAP)

OBJ = $(SRC:%.c=.tmp/%.o)

.SILENT:

all: prepare compile_lib compile_p $(NAME) exec

exec:
		printf "\n\n\033[32mRun like this:\n ./$(NAME)\033[39m\n"

prepare:
		mkdir -p .tmp/Core
		mkdir -p .tmp/Check
		mkdir -p .tmp/Termcap

norm:
		norminette $(SRC) $(HEADER)

compile_lib:
		make -C $(LIB)/

$(NAME): $(OBJ)
		gcc $(FLAGS) $(OBJ) -o $(NAME) -L $(LIB)/ -lft -L /usr/lib/ -ltermcap

compile_p:
		echo "\n\033[34mCompiling $(NAME) wait...\033[39m"

.tmp/%.o: %.c $(HEADER)
		gcc $(FLAGS) -I $(LIB)/includes -I includes/ -o $@ -c $<
		printf "\033[33m. \033[39m"

clean:
		make -C $(LIB)/ fclean
		/bin/rm -rf -- .tmp/
		echo "\033[41;36mRemoving Objects Wait...\033[49;39m"

clean_proj:
		/bin/rm -f $(OBJ_SERV) $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)
		make -C $(LIB)/ fclean
		echo "\033[41;33mRemoving Binary Wait...\033[49;39m\n"

re: fclean all
