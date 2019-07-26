# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 16:37:20 by schornon          #+#    #+#              #
#    Updated: 2019/06/18 17:29:15 by schornon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  asm
FLAGS = -Wall -Werror -Wextra
ASM_FILES = $(addprefix src/asm_files/, asm.c init.c parsing.c validation.c validation2.c validation3.c checkers.c checkers2.c checkers3.c check_command1.c check_command2.c check_command3.c tokenization.c luf.c token_creator.c tokens_name_com.c translator.c translator_luf.c encode_tokens.c encode_tokens_2.c encode_tokens_arg.c bonus.c)
INCLUDES = -I ./includes
LIBFTPRINTF_LIB = ./../libftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(ASM_FILES)
	@gcc $(FLAGS) $(INCLUDES) -o $(NAME) $(ASM_FILES) $(LIBFTPRINTF_LIB)
	@echo "\033[0;94masm compiled.\033[0m "

clean:
	@echo "\033[1;91mCLEANED asm\033[0m "
	@echo "\033[1;91mCLEANED libftprintf\033[0m "

fclean: clean
	@rm -f $(NAME)

re:
	@make fclean
	@make
