# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathou <mathou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/10 10:00:41 by mressier          #+#    #+#              #
#    Updated: 2016/02/22 11:46:31 by mressier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = NAME

C_DIR =	srcs
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)
C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep ".*\.c")

O_DIR =	.tmp/obj
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

ifdef DEBUG
	FLAGS = -Wall -Wextra -Werror -g
else
	FLAGS = -Wall -Wextra -Werror
endif

INCLUDES = -I ./includes

all: $(NAME)

$(NAME): $(O_FILES)
	@gcc $(FLAGS) $(INCLUDES) -c $(NAME)
	@echo "\\n\033[33m $(NAME) has successfully been played ღ \033[0;0m\\n"

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir -p $(O_DIRS) $(O_DIR)
	@echo "\033[32m♪♫\033[0m"\\c
	@gcc $(INCLUDES) -o $@

clean:
	@echo "\\n\033[44m Clean objects ... ⊗_⊙ \033[0;0m\\n"
	@rm -rf $(O_DIR)

fclean: clean
	@echo "\033[44m Clean $(NAME) ... ⊛﹏⊛ \033[0;0m\\n"
	@rm -rf $(NAME)
	@rm -rf .tmp/

re: fclean all
