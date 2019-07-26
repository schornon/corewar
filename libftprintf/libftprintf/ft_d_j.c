/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_j.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:12:13 by sbudilko          #+#    #+#             */
/*   Updated: 2018/05/08 13:12:14 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_intmax_t(intmax_t n, int fd)
{
	if (n >= 10)
		ft_putnbr_intmax_t(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

void	ft_d_j_4(int fd, t_syntax *syntax, intmax_t arg, int len_prec)
{
	char		str[len_prec];

	ft_memset(str, '0', (size_t)(len_prec));
	if (arg < 0)
	{
		write(fd, "-", 1);
		if (arg != LLONG_MIN)
			arg = -arg;
	}
	else if ((*syntax).falgs.plus == 1)
		write(fd, "+", 1);
	else if ((*syntax).falgs.space == 1)
		write(fd, " ", 1);
	write(fd, str, len_prec);
	if (arg == LLONG_MIN)
		write(fd, "9223372036854775808", 19);
	else if (arg == 0 && (*syntax).precision == 0)
	{
		if ((*syntax).width != 0)
			ft_putchar_fd(' ', fd);
		return ;
	}
	else
		ft_putnbr_intmax_t(arg, fd);
}

void	ft_d_j_3(int fd, t_syntax *syntax, intmax_t arg, int *len)
{
	char	str[(*syntax).width - len[0]];

	if ((*syntax).falgs.minus == 1)
	{
		ft_d_j_4(fd, syntax, arg, len[1]);
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
	}
	else if ((*syntax).falgs.zero == 1)
		if ((*syntax).precision == -1)
			ft_d_j_4(fd, syntax, arg, (*syntax).width - len[0]);
		else
			ft_d_j_4(fd, syntax, arg, len[1]);
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
		ft_d_j_4(fd, syntax, arg, len[1]);
	}
}

int		ft_d_j_2(int fd, t_syntax *syntax, intmax_t arg)
{
	int		len[2];
	int		sign;

	len[1] = 0;
	sign = 0;
	len[0] = ft_quantity_digit_ll(arg);
	if (arg < 0 || (*syntax).falgs.plus == 1 ||
		(*syntax).falgs.space == 1)
		sign = 1;
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - len[0];
	len[0] = len[0] + sign + len[1];
	if ((*syntax).width > len[0])
	{
		ft_d_j_3(fd, syntax, arg, len);
		return ((*syntax).width);
	}
	else
	{
		ft_d_j_4(fd, syntax, arg, len[1]);
		return (len[0]);
	}
}

int		ft_d_j(int fd, t_syntax *syntax, va_list *ap)
{
	int			len;
	intmax_t	arg;

	arg = va_arg(*ap, intmax_t);
	len = ft_d_j_2(fd, syntax, arg);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
