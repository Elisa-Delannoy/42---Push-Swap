# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edelanno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:35:52 by edelanno          #+#    #+#              #
#    Updated: 2024/12/09 13:36:06 by edelanno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./
NAME = push_swap
SRC = push_swap.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJ) $(LIBFT) 
	$(CC) $(OBJ)  -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re : fclean all
