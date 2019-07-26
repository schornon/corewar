/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_ll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 14:22:46 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/04 14:22:48 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_u_long_long(unsigned long long int n, int fd)
{
	if (n >= 10)
		ft_putnbr_u_long_long(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

void	ft_u_ll_4(int f, t_syntax *s, unsigned long long int arg, int len_prec)
{
	char		str[len_prec];

	ft_memset(str, '0', (size_t)(len_prec));
	write(f, str, len_prec);
	if (arg == 0 && (*s).precision == 0)
	{
		if ((*s).width != 0)
			ft_putchar_fd(' ', f);
		return ;
	}
	else
		ft_putnbr_u_long_long(arg, f);
}

void	ft_u_ll_3(int fd, t_syntax *synt, unsigned long long int arg, int *len)
{
	char	str[(*synt).width - len[0]];

	if ((*synt).falgs.minus == 1)
	{
		ft_u_ll_4(fd, synt, arg, len[1]);
		ft_memset(str, ' ', (size_t)((*synt).width - len[0]));
		write(fd, str, (size_t)((*synt).width - len[0]));
	}
	else if ((*synt).falgs.zero == 1)
		if ((*synt).precision == -1)
			ft_u_ll_4(fd, synt, arg, (*synt).width - len[0]);
		else
			ft_u_ll_4(fd, synt, arg, len[1]);
	else
	{
		ft_memset(str, ' ', (size_t)((*synt).width - len[0]));
		write(fd, str, (size_t)((*synt).width - len[0]));
		ft_u_ll_4(fd, synt, arg, len[1]);
	}
}

int		ft_u_ll_2(int fd, t_syntax *syntax, unsigned long long int arg)
{
	int		len[2];

	len[1] = 0;
	len[0] = ft_quantity_digit_ull(arg);
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - len[0];
	len[0] = len[0] + len[1];
	if ((*syntax).width > len[0])
	{
		ft_u_ll_3(fd, syntax, arg, len);
		return ((*syntax).width);
	}
	else
	{
		ft_u_ll_4(fd, syntax, arg, len[1]);
		return (len[0]);
	}
}

int		ft_u_ll(int fd, t_syntax *syntax, va_list *ap)
{
	int						len;
	unsigned long long int	arg;

	arg = va_arg(*ap, unsigned long long int);
	len = ft_u_ll_2(fd, syntax, arg);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
