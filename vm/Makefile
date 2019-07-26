# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 16:37:04 by schornon          #+#    #+#              #
#    Updated: 2019/06/19 12:59:54 by sbudilko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  corewar
FLAGS = -Wall -Werror -Wextra -lncurses
COREWAR_FILES = $(addprefix src/corewar_files/, corewar.c file_1.c file_2.c file_3.c file_4.c file_5.c file_6.c file_7.c file_8.c file_9.c file_10.c file_11.c file_12.c file_13.c file_14.c file_15.c)
INCLUDES = -I ./../includes
LIBFTPRINTF_LIB = ./../libftprintf/libftprintf.a 

all: $(NAME)

$(NAME): $(COREWAR_FILES)
	@gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(COREWAR_FILES) $(LIBFTPRINTF_LIB)
	@echo "\033[0;94mcorewar compiled.\033[0m "

clean:
	@echo "\033[1;91mCLEANED corewar\033[0m "
	@echo "\033[1;91mCLEANED libftprintf\033[0m "

fclean: clean
	@rm -f $(NAME)

re:
	@make fclean
	@make
