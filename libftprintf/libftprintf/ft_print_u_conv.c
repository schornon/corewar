/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:39:32 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/04 13:39:33 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_u_conv_4(int fd, t_syntax *syn, unsigned int arg, int len_pre)
{
	char	str[len_pre];

	ft_memset(str, '0', (size_t)(len_pre));
	write(fd, str, len_pre);
	if (arg == 0 && (*syn).precision == 0)
	{
		if ((*syn).width != 0)
			ft_putchar_fd(' ', fd);
		else
			return ;
	}
	else
		ft_putnbr_long_long(arg, fd);
}

void	ft_print_u_conv_3(int fd, t_syntax *syntax, unsigned int arg, int *len)
{
	char	str[(*syntax).width - len[0]];

	if ((*syntax).falgs.minus == 1)
	{
		ft_print_u_conv_4(fd, syntax, arg, len[1]);
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
	}
	else if ((*syntax).falgs.zero == 1)
		if ((*syntax).precision == -1)
			ft_print_u_conv_4(fd, syntax, arg, (*syntax).width - len[0]);
		else
		{
			ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
			write(fd, str, (size_t)((*syntax).width - len[0]));
			ft_print_u_conv_4(fd, syntax, arg, len[1]);
		}
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
		ft_print_u_conv_4(fd, syntax, arg, len[1]);
	}
}

int		ft_print_u_conv_2(int fd, t_syntax *syntax, va_list *ap)
{
	unsigned int	arg;
	int				len[2];

	len[1] = 0;
	arg = va_arg(*ap, unsigned int);
	len[0] = ft_quantity_digit_ll(arg);
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - len[0];
	len[0] = len[0] + len[1];
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len[0]--;
	if ((*syntax).width > len[0])
	{
		ft_print_u_conv_3(fd, syntax, arg, len);
		return ((*syntax).width);
	}
	else
		ft_print_u_conv_4(fd, syntax, arg, len[1]);
	return (len[0]);
}

int		ft_print_u_conv(int fd, t_syntax *syntax, va_list *ap)
{
	int		len;

	if ((*syntax).length.hh == 1)
		len = ft_u_hh(fd, syntax, ap);
	else if ((*syntax).length.h == 1)
		len = ft_u_h(fd, syntax, ap);
	else if ((*syntax).length.l == 1)
		len = ft_u_l(fd, syntax, ap);
	else if ((*syntax).length.ll == 1)
		len = ft_u_ll(fd, syntax, ap);
	else if ((*syntax).length.j == 1)
		len = ft_u_j(fd, syntax, ap);
	else if ((*syntax).length.z == 1)
		len = ft_u_z(fd, syntax, ap);
	else
		len = ft_print_u_conv_2(fd, syntax, ap);
	return (len);
}
