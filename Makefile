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
RM = rm -rf
SRC = push_swap.c utils.c split.c init_stack.c lists_libft.c rotate.c \
	push.c swap.c reverse.c sort.c algo.c
BONUS_SRC = push_swap_bonus.c utils_bonus.c split_bonus.c init_stack_bonus.c \
	lists_libft_bonus.c rotate_bonus.c push_bonus.c swap_bonus.c \
	reverse_bonus.c sort_bonus.c algo_bonus.c get_next_line_bonus.c \
	get_next_line_utils_bonus.c
OBJS = $(addprefix obj/, $(SRC:.c=.o))
OBJS_BONUS = $(addprefix obj/, $(BONUS_SRC:.c=.o))

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(BONUS_NAME)

obj/%.o: %.c push_swap.h push_swap_bonus.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all
