# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 13:01:16 by schornon          #+#    #+#              #
#    Updated: 2019/06/20 17:19:42 by schornon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a
FLAGS = -Wall -Werror -Wextra
LIBFT_OFILES = $(addprefix libft/, get_next_line.o ft_atoi.o ft_bzero.o ft_reverse_str.o ft_isspace.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o ft_toupper.o ft_pow.o)
PRINTF_OFILES = $(addprefix libftprintf/, ft_fill_func_arr.o ft_fprintf.o ft_parse_syntax.o ft_print_s_conv.o ft_print_ss_conv.o ft_print_without_conv.o ft_printf.o ft_syntax_struct.o ft_syntax.o ft_print_c_conv.o ft_print_cc_conv.o ft_print_ss_conv.o ft_print_d_conv.o ft_d_h.o ft_d_hh.o ft_d_l.o ft_d_ll.o ft_d_j.o ft_d_z.o ft_print_dd_conv.o ft_quantyti_digit.o ft_print_u_conv.o ft_print_uu_conv.o  ft_u_h.o ft_u_hh.o ft_u_j.o ft_u_l.o ft_u_ll.o ft_u_z.o ft_print_o_conv.o ft_print_oo_conv.o ft_o_h.o ft_o_hh.o ft_o_j.o ft_o_l.o ft_o_ll.o ft_o_z.o ft_print_x_conv.o ft_x_h.o ft_x_hh.o ft_x_l.o ft_x_ll.o ft_x_j.o ft_x_z.o ft_print_xx_conv.o ft_xx_h.o ft_xx_hh.o ft_xx_j.o ft_xx_l.o ft_xx_ll.o ft_xx_z.o ft_print_p_conv.o)
INCLUDES = -I ../includes

all: $(NAME)
$(NAME): $(LIBFT_OFILES) $(PRINTF_OFILES)
	@ar rc $(NAME) $(LIBFT_OFILES) $(PRINTF_OFILES)
	@ranlib $(NAME)
	@echo "\033[0;32mlibftprintf compiled.\033[0m "
%.o: %.c
	@gcc -o $@ -c $< $(FLAGS) $(INCLUDES)
clean:
	@rm -f $(LIBFT_OFILES) $(PRINTF_OFILES)
fclean: clean
	@rm -f $(NAME)
re:
	@make fclean
	@make
