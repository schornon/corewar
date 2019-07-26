/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_h.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:21:55 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/04 14:22:14 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_u_h_2(int fd, t_syntax *syntax, int arg)
{
	int		len[2];

	len[1] = 0;
	len[0] = ft_quantity_digit(arg);
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - len[0];
	len[0] = len[0] + len[1];
	if ((*syntax).width > len[0])
	{
		ft_print_u_conv_3(fd, syntax, arg, len);
		return ((*syntax).width);
	}
	else
	{
		ft_print_u_conv_4(fd, syntax, arg, len[1]);
		return (len[0]);
	}
}

int		ft_u_h(int fd, t_syntax *syntax, va_list *ap)
{
	int					len;
	int					new_arg;
	unsigned short int	arg;

	arg = va_arg(*ap, int);
	new_arg = (int)arg;
	len = ft_u_h_2(fd, syntax, new_arg);
	if (arg == 0 && (*syntax).width == 0 &&
		(*syntax).precision == 0)
		len--;
	return (len);
}
