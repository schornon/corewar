/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 16:48:59 by sbudilko          #+#    #+#             */
/*   Updated: 2018/05/01 16:49:02 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_long_fd(long int n, int fd)
{
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

void	ft_print_d_conv_4(int fd, t_syntax *syntax, int arg, int len_prec)
{
	long	new_arg;
	char	str[len_prec];

	new_arg = (long)arg;
	ft_memset(str, '0', (size_t)(len_prec));
	if (new_arg < 0)
	{
		write(fd, "-", 1);
		new_arg = -new_arg;
	}
	else if ((*syntax).falgs.plus == 1)
		write(fd, "+", 1);
	else if ((*syntax).falgs.space == 1)
		write(fd, " ", 1);
	write(fd, str, len_prec);
	if (arg == 0 && (*syntax).precision == 0)
	{
		if ((*syntax).width != 0)
			ft_putchar_fd(' ', fd);
		else
			return ;
	}
	else
		ft_putnbr_long_fd(new_arg, fd);
}

void	ft_print_d_conv_3(int fd, t_syntax *syntax, int arg, int *len)
{
	char	str[(*syntax).width - len[0]];

	if ((*syntax).falgs.minus == 1)
	{
		ft_print_d_conv_4(fd, syntax, arg, len[1]);
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
	}
	else if ((*syntax).falgs.zero == 1)
		if ((*syntax).precision == -1)
			ft_print_d_conv_4(fd, syntax, arg, (*syntax).width - len[0]);
		else
		{
			ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
			write(fd, str, (size_t)((*syntax).width - len[0]));
			ft_print_d_conv_4(fd, syntax, arg, len[1]);
		}
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
		ft_print_d_conv_4(fd, syntax, arg, len[1]);
	}
}

int		ft_print_d_conv_2(int fd, t_syntax *syntax, va_list *ap)
{
	int		arg;
	int		len[2];
	int		sign;

	len[1] = 0;
	sign = 0;
	arg = va_arg(*ap, int);
	len[0] = ft_quantity_digit(arg);
	if (arg < 0 || (*syntax).falgs.plus == 1 || (*syntax).falgs.space == 1)
		sign = 1;
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - len[0];
	len[0] = len[0] + sign + len[1];
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len[0]--;
	if ((*syntax).width > len[0])
	{
		ft_print_d_conv_3(fd, syntax, arg, len);
		return ((*syntax).width);
	}
	else
		ft_print_d_conv_4(fd, syntax, arg, len[1]);
	return (len[0]);
}

int		ft_print_d_conv(int fd, t_syntax *syntax, va_list *ap)
{
	int		len;

	if ((*syntax).length.hh == 1)
		len = ft_d_hh(fd, syntax, ap);
	else if ((*syntax).length.h == 1)
		len = ft_d_h(fd, syntax, ap);
	else if ((*syntax).length.l == 1)
		len = ft_d_ll(fd, syntax, ap);
	else if ((*syntax).length.ll == 1)
		len = ft_d_ll(fd, syntax, ap);
	else if ((*syntax).length.j == 1)
		len = ft_d_j(fd, syntax, ap);
	else if ((*syntax).length.z == 1)
		len = ft_d_z(fd, syntax, ap);
	else
		len = ft_print_d_conv_2(fd, syntax, ap);
	return (len);
}
