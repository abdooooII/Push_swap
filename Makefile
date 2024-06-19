# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 04:25:43 by abouafso          #+#    #+#              #
#    Updated: 2024/06/19 18:24:32 by abouafso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = push_swap_bonus

CC = CC

# CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -fsanitize=address -g

RM = rm -rf

SRC = push_swap.c utils.c split.c init_stack.c lists_libft.c rotate.c \
	push.c swap.c reverse.c sort.c algo.c

BONUS_SRC = push_swap.c utils.c split.c init_stack.c lists_libft.c rotate.c \
	push.c swap.c reverse.c sort.c algo.c get_next_line.c get_next_line_utils.c

OBJ = $(addprefix obj/, $(SRC:.c=.o))
BONUS_OBJ = $(addprefix obj_bonus/, $(BONUS_SRC:.c=.o))

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(BONUS_OBJ) $(CFLAGS) -o $(BONUS_NAME)

obj/%.o: %.c push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

obj_bonus/%.o: bonus/%.c push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) obj obj_bonus

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all
