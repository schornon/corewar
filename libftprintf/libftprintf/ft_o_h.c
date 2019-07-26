/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_hh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:28:30 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/04 16:28:35 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_dec_to_octal_2(int arg, int len, t_syntax *syntax)
{
	char	*str;
	int		i;
	int		remainder;

	i = 0;
	if ((*syntax).falgs.hash == 1)
		str = ft_strnew(len + 2);
	else
		str = ft_strnew(len + 1);
	while (arg > 7)
	{
		remainder = (int)(arg % 8);
		str[i] = remainder + '0';
		i++;
		arg = arg / 8;
	}
	str[i] = arg + '0';
	i++;
	if ((*syntax).falgs.hash == 1)
		str[i] = '0';
	return (ft_reverse_str(str));
}

int		ft_o_h_2(int fd, t_syntax *syntax, int arg)
{
	int		len[2];
	char	*str;

	len[1] = 0;
	len[0] = ft_quantity_digit_ll(arg);
	str = ft_dec_to_octal_2(arg, len[0], syntax);
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - len[0];
	len[0] = ft_strlen(str) + len[1];
	if ((*syntax).width > len[0])
	{
		ft_print_o_conv_3(fd, syntax, str, len);
		free(str);
		str = NULL;
		return ((*syntax).width);
	}
	else
	{
		ft_print_o_conv_4(fd, syntax, str, len[1]);
		free(str);
		str = NULL;
		return (len[0]);
	}
}

int		ft_o_h(int fd, t_syntax *syntax, va_list *ap)
{
	int					len;
	int					new_arg;
	unsigned short int	arg;

	arg = va_arg(*ap, int);
	new_arg = (int)arg;
	len = ft_o_h_2(fd, syntax, new_arg);
	if (arg == 0 && (*syntax).width == 0 &&
		(*syntax).precision == 0)
		len--;
	return (len);
}
