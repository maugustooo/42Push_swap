# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maugusto <maugusto@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 11:56:43 by maugusto          #+#    #+#              #
#    Updated: 2024/07/11 14:28:52 by maugusto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -Iheaders/
RM = rm -rf

LIBFT = libft/libft.a


SRCS = 	main.c\
		commands/swap.c commands/push.c commands/rotate.c commands/reverse_rotate.c\
		utils/error.c utils/stack_functions.c utils/find.c\
		algorithm/push_swap.c
		
OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS)
	
fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

download:
	@wget https://cdn.intra.42.fr/document/document/25705/checker_linux
re: fclean all