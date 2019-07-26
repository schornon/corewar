/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cc_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:00:11 by sbudilko          #+#    #+#             */
/*   Updated: 2018/04/24 16:00:12 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_cc_conv_2(int fd, wchar_t cc)
{
	if (cc <= 0x7F)
		ft_putchar_fd(cc, fd);
	else if (cc <= 0x7FF)
	{
		ft_putchar_fd((cc >> 6) + 0xC0, fd);
		ft_putchar_fd((cc & 0x3F) + 0x80, fd);
	}
	else if (cc <= 0xFFFF)
	{
		ft_putchar_fd((cc >> 12) + 0xE0, fd);
		ft_putchar_fd(((cc >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((cc & 0x3F) + 0x80, fd);
	}
	else if (cc <= 0x10FFFF)
	{
		ft_putchar_fd((cc >> 18) + 0xF0, fd);
		ft_putchar_fd(((cc >> 12) & 0x3F) + 0x80, fd);
		ft_putchar_fd(((cc >> 6) & 0x3F) + 0x80, fd);
		ft_putchar_fd((cc & 0x3F) + 0x80, fd);
	}
}

void	ft_print_cc_conv_3(int fd, wchar_t cc, int len, t_syntax *syntax)
{
	char	str[(*syntax).width - len];

	if ((*syntax).falgs.minus == 1)
	{
		ft_print_cc_conv_2(fd, cc);
		ft_memset(str, ' ', (size_t)((*syntax).width - len));
		write(fd, str, (size_t)((*syntax).width - len));
	}
	else if ((*syntax).falgs.zero == 1)
	{
		ft_memset(str, '0', (size_t)((*syntax).width - len));
		write(fd, str, (size_t)((*syntax).width - len));
		ft_print_cc_conv_2(fd, cc);
	}
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - len));
		write(fd, str, (size_t)((*syntax).width - len));
		ft_print_cc_conv_2(fd, cc);
	}
}

int		ft_print_cc_conv(int fd, t_syntax *syntax, va_list *ap)
{
	wchar_t		cc;
	int			len;

	len = 0;
	if (MB_CUR_MAX == 1)
		return (-1);
	cc = va_arg(*ap, wchar_t);
	if (cc <= 0x7F)
		len = 1;
	else if (cc <= 0x7FF)
		len = 2;
	else if (cc <= 0xFFFF)
		len = 3;
	else if (cc <= 0x10FFFF)
		len = 4;
	if ((*syntax).width > len)
	{
		ft_print_cc_conv_3(fd, cc, len, syntax);
		return ((*syntax).width);
	}
	else
		ft_print_cc_conv_2(fd, cc);
	return (len);
}
