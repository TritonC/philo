# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mluis-fu <mluis-fu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 11:22:32 by mluis-fu          #+#    #+#              #
#    Updated: 2023/03/24 16:54:47 by mluis-fu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CHECKER = checker

CC = gcc

INCLUDES = -I inc

CFLAGS = -Wall -Werror -Wextra $(INCLUDES) -g3

SRC_DIR = src

BONUS_SRC = bonus

CHECKER_FILE = src/checker.c

SRC_FILES = main.c parser.c utils.c ft_split.c time.c

OBJ_FILES = $(SRC_FILES:.c=.o)

OBJ_DIR = obj

SRC_BONUS =

BONUS_FILES = $(SRC_BONUS:.c=.o)

BONUS_DIR = bonus/obj

BONUS_OBJ = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))

OBJECTS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) 

${CHECKER}: ${BONUS_OBJ} ${LIBFT_MAKE}
		$(CC) $(CFLAGS) $(LIBFT_MAKE) -o ${CHECKER} $(BONUS_OBJ)

$(BONUS_DIR)/%.o: $(BONUS_SRC)/%.c
	@mkdir -p $(BONUS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: ${CHECKER}

clean:
	@rm -rf $(BONUS_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME) $(CHECKER)

re: fclean all

print-%:
	$(info '$*'='$($*)')
info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

.PHONY:	re clean fclean all