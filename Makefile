# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouafso <abouafso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 04:25:43 by abouafso          #+#    #+#              #
#    Updated: 2024/06/08 16:50:57 by abouafso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = CC

# CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = push_swap.c utils.c split.c init_stack.c lists_libft.c rotate.c \
	push.c swap.c reverse.c sort.c
	

OBJ = $(addprefix obj/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

obj/%.o: %.c push_swap.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) obj

fclean: clean
	$(RM) $(NAME)

re: fclean all