# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sudelory <sudelory@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/09 00:58:36 by sudelory          #+#    #+#              #
#    Updated: 2025/02/28 03:16:42 by sudelory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c\
		check_stack.c\
		push_and_swap.c\
		rotate.c\
		reverse_rotate.c\
		algorithm.c\
		ft_printf.c\
		ft_putint.c\
		ft_putsorc.c\
		utils.c\
		ft_strcmp.c\
		preprocess_index.c\
		special_case.c

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re