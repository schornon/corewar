/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_hh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:10:59 by sbudilko          #+#    #+#             */
/*   Updated: 2018/05/08 13:11:00 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_d_hh_2(int fd, t_syntax *syntax, int arg)
{
	int		len[2];
	int		sign;

	len[1] = 0;
	sign = 0;
	len[0] = ft_quantity_digit(arg);
	if (arg < 0 || (*syntax).falgs.plus == 1 ||
		(*syntax).falgs.space == 1)
		sign = 1;
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - len[0];
	len[0] = len[0] + sign + len[1];
	if ((*syntax).width > len[0])
	{
		ft_print_d_conv_3(fd, syntax, arg, len);
		return ((*syntax).width);
	}
	else
	{
		ft_print_d_conv_4(fd, syntax, arg, len[1]);
		return (len[0]);
	}
}

int		ft_d_hh(int fd, t_syntax *syntax, va_list *ap)
{
	int			len;
	int			new_arg;
	signed char	arg;

	arg = va_arg(*ap, int);
	new_arg = (int)arg;
	len = ft_d_hh_2(fd, syntax, new_arg);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
