# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 17:24:08 by schornon          #+#    #+#              #
#    Updated: 2019/06/18 17:29:06 by schornon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@make all -C ./libftprintf
	@make -C assembly/
	@make -C vm/
	@cp assembly/asm .
	@cp vm/corewar .

clean:
	@make clean -C ./libftprintf
	@make -C assembly/ clean
	@make -C vm/ clean

fclean:
	@make fclean -C ./libftprintf
	@make -C assembly/ fclean
	@make -C vm/ fclean
	@rm asm
	@rm corewar

re: fclean all
