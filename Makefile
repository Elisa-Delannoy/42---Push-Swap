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
CC = cc -g
CFLAGS = -Wall -Wextra -Werror -I ./
NAME = push_swap
SRC = push_swap.c

OBJ = $(SRC:.c=.o)

all : $(NAME)
	@echo "\033[32mCompilation successful !\033[0m"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "Compilating $@"

$(NAME) : $(OBJ) $(LIBFT) 
	@$(CC) $(OBJ)  -o $(NAME) $(LIBFT)

%.o: %.c
	@echo "Compilating $@"
	@$(CC) $(CFLAGS) -c $< -o $@
	

clean : 
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@rm -f $(OBJ)
	@echo "\033[32mClean ok\033[0m"

fclean : clean
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re : fclean all
