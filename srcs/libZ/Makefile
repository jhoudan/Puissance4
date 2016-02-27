# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathou <mathou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/10 10:00:41 by mressier          #+#    #+#              #
#    Updated: 2016/02/22 11:32:14 by mressier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libZ.a

C_DIR =	srcs
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)
C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep "\.c")

O_DIR =	.tmp/obj
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

FLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rcs $@ $^
	@ranlib $@
	@echo "\\n\033[33m $(NAME) has successfully been played ღ \033[0;0m\\n"

$(O_DIR)%.o: $(C_DIR)%.c
	@mkdir -p $(O_DIRS) $(O_DIR)
	@echo "\033[32m♪♫\033[0m"\\c
	@gcc $(INCLUDES) -o $@ -c $<

clean:
	@echo "\\n\033[44m Clean objects ... ⊗_⊙ \033[0;0m\\n"
	@rm -rf $(O_DIR)

fclean: clean
	@echo "\033[44m Clean $(NAME) ... ⊛﹏⊛ \033[0;0m\\n"
	@rm -rf $(NAME)
	@rm -rf .tmp/

re: fclean all
