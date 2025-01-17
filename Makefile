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

FTPRINTF_DIR = printf
FTPRINTF = $(FTPRINTF_DIR)/ftprintf

CC = cc -g
CFLAGS = -Wall -Wextra -Werror -I ./
NAME = push_swap
SRC = push_swap.c push_swap_main.c push_swap_lst.c push_swap_check_rr.c \
	push_swap_check_rrr.c push_swap_create_b.c push_swap_ft_utils.c \
	push_swap_groups.c push_swap_main.c push_swap_rev_rot.c push_swap_rotate.c \
	push_swap_ss.c push_swap_way.c \

OBJ = $(SRC:.c=.o)

all : $(NAME)
	@echo "\033[32mCompilation successful !\033[0m"

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)
	@echo "Compilating $@"

$(FTPRINTF):
	@$(MAKE) -s -C $(FTPRINTF_DIR)
	@echo "Compilating $@"

$(NAME) : $(OBJ) $(LIBFT) $(FTPRINTF)
	@$(CC) $(OBJ)  -o $(NAME) $(LIBFT) $(FTPRINTF)

%.o: %.c
	@echo "Compilating $@"
	@$(CC) $(CFLAGS) -c $< -o $@
	

clean : 
	@$(MAKE) -s clean -C $(LIBFT_DIR)
	@$(MAKE) -s clean -C $(FTPRINTF_DIR)
	@rm -f $(OBJ)
	@echo "\033[32mClean ok\033[0m"

fclean : clean
	@$(MAKE) -s fclean -C $(LIBFT_DIR)
	@$(MAKE) -s fclean -C $(FTPRINTF_DIR)
	@rm -f $(NAME)

re : fclean all