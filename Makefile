# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdumouli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/10 10:00:41 by mressier          #+#    #+#              #
#    Updated: 2016/02/27 21:18:06 by mvarzari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance4

HEADER = includes/puissance.h

CORE = alloc_struct.c \
		error.c \
		free.c \
		init_game.c \
		init_game_2.c \
		put_in_grid.c \
		main.c

DISPLAY = drawshell.c \

CHECK = checker.c \

NCURSES = ncurses_display.c 

TOOLS = tools.c \
		read_one_line.c \
		copy_struct_game.c

MULTI = multi_player.c \
		multi_player_2.c

RECURS = find_value_to_ret.c \
		 get_column_to_play.c \
		 get_line_pos_when_put_the_piece.c \
		 get_valid_column.c \
		 get_weight_pos_tab.c \
		 grid_is_full.c

WEIGHT = ft_weight.c \
		 ft_weight_player.c

ifdef DEBUG
FLAGS = -Wall -Werror -Wextra -g

else
FLAGS = -Wall -Werror -Wextra
endif

LIB = libft

SRC_CORE = $(addprefix Core/, $(CORE))

SRC_CHECK = $(addprefix Check/, $(CHECK))

SRC_NCURSES = $(addprefix Ncurses/, $(NCURSES))

SRC_DISPLAY = $(addprefix Display/, $(DISPLAY))

SRC_TOOLS = $(addprefix Tools/, $(TOOLS))

SRC_MULTI  = $(addprefix Multi/, $(MULTI))

SRC_RECURS = $(addprefix Recurs_Min_Max/, $(RECURS))

SRC_WEIGHT = $(addprefix weight_values/, $(WEIGHT))

SRC = $(SRC_CORE) $(SRC_CHECK) $(SRC_TERMCAP) $(SRC_TOOLS) $(SRC_DISPLAY) $(SRC_MULTI) $(SRC_NCURSES) $(SRC_RECURS) $(SRC_WEIGHT)

OBJ = $(SRC:%.c=.tmp/%.o)

.SILENT:

all: prepare compile_lib compile_p $(NAME) exec

exec:
		printf "\n\n\033[32mRun like this:\n ./$(NAME)\033[39m\n"

prepare:
		mkdir -p .tmp/Core
		mkdir -p .tmp/Check
		mkdir -p .tmp/Ncurses
		mkdir -p .tmp/Termcap
		mkdir -p .tmp/Display
		mkdir -p .tmp/Tools
		mkdir -p .tmp/Multi
		mkdir -p .tmp/Recurs_Min_Max
		mkdir -p .tmp/weight_values

norm:
		norminette $(SRC) $(HEADER)

compile_lib:
		make -C $(LIB)/

$(NAME): $(OBJ)
		gcc $(FLAGS) $(OBJ) -o $(NAME) -L $(LIB)/ -lft -L /usr/lib/ -lncurses

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
