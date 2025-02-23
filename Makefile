# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 13:48:09 by lsilva-x          #+#    #+#              #
#    Updated: 2025/02/23 13:53:55 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
NAME		= push_swap
NAME_BONUS	= checker
CFLAG		= -Wall -Wextra -Werror -Wunreachable-code -Ofast -g

LIBFT_DIR	= libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a

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

SRC_BONUS	=	checker.c \
				checker_utils.c 

BONUS_SRC	= $(filter-out main.c, $(SRC)) $(SRC_BONUS)

OBJ_DIR		= ./build
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_BONUS	= $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAG) -o $@ $^

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT_LIB)
	$(CC) $(CFLAG) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAG) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re