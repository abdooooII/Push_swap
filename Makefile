# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 04:25:43 by abouafso          #+#    #+#              #
#    Updated: 2024/06/20 13:51:16 by abouafso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror
CFLAGS = -fsanitize=address -g

RM = rm -rf

SRC = push_swap.c utils.c split.c init_stack.c lists_libft.c rotate.c \
	push.c swap.c reverse.c sort.c algo.c

BONUS_SRC = bonus/push_swap_bonus.c bonus/utils_bonus.c bonus/split_bonus.c bonus/init_stack_bonus.c \
    bonus/lists_libft_bonus.c bonus/rotate_bonus.c bonus/push_bonus.c bonus/swap_bonus.c \
    bonus/reverse_bonus.c bonus/sort_bonus.c bonus/algo_bonus.c bonus/get_next_line_bonus.c \
    bonus/get_next_line_utils_bonus.c

OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:bonus/%.c=$(BONUS_OBJ_DIR)/%.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) $(CFLAGS) -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: %.c push_swap.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: bonus/%.c bonus/push_swap_bonus.h
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all
