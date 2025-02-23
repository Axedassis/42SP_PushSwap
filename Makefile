# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 13:48:09 by lsilva-x          #+#    #+#              #
#    Updated: 2025/02/23 15:08:26 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
NAME		= bin/push_swap
NAME_BONUS	= bin/checker
CFLAG		= -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

LIBFT_DIR	= ./lib/libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

SRC_DIR		= mandatory
BONUS_DIR	=	checker

SRC			=	main.c \
				common_functions.c \
				input_checker.c \
				stack_functions.c \
				utils_functions.c \
				a_operations.c \
				b_operations.c \
				ab_operations.c \
				sort_stack.c \
				auxiliary_functions.c \
				debug.c 

SRC_BONUS	=	checker_bonus.c \
				checker_utils_bonus.c \
				common_functions_bonus.c \
				input_checker_bonus.c \
				stack_functions_bonus.c \
				utils_functions_bonus.c \
				a_operations_bonus.c \
				b_operations_bonus.c \
				ab_operations_bonus.c \
				sort_stack_bonus.c \
				auxiliary_functions_bonus.c \
				debug_bonus.c 

OBJ_DIR_MANDATORY	= build/mandatory
OBJ_DIR_BONUS		= build/bonus

OBJ			= $(addprefix $(OBJ_DIR_MANDATORY)/, $(SRC:.c=.o))
OBJ_BONUS	= $(addprefix $(OBJ_DIR_BONUS)/, $(SRC_BONUS:.c=.o))

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT_LIB)
	@mkdir -p $(@D)
	$(CC) $(CFLAG) -o $@ $^

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_LIB)
	@mkdir -p $(@D)
	$(CC) $(CFLAG) -o $@ $^

$(OBJ_DIR_MANDATORY)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAG) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAG) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -rf build
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re