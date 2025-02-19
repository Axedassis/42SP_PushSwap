# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsilva-x <lsilva-x@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 18:35:52 by lsilva-x          #+#    #+#              #
#    Updated: 2025/02/19 12:28:27 by lsilva-x         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
NAME		= push_swap
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



OBJ_DIR		= ./build
OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAG) -o $(NAME) $(OBJ) $(LIBFT_LIB)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAG) -c $< -o $@

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5 -n 5))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test25:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-25 -n 25))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					echo -n "Instructions: "
					./push_swap $(ARG) | wc -l

test50:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-50 -n 50))
					valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test149:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-149 -n 149))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell seq -500 500 | shuf | head -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test150:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-150 -n 150))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test200:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-200 -n 200))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					@./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

.PHONY: all clean fclean re
