/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ss_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 15:53:22 by sbudilko          #+#    #+#             */
/*   Updated: 2018/04/05 15:53:26 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_print_3_ss_conv(int fd, wchar_t *str)
{
	while (*str)
	{
		ft_print_cc_conv_2(fd, *str);
		str++;
	}
}

void	ft_print_2_ss_conv(int fd, t_syntax *syntax, wchar_t *arg, int len)
{
	char	str[(*syntax).width - len];

	if ((*syntax).falgs.minus == 1)
	{
		ft_print_3_ss_conv(fd, arg);
		ft_memset(str, ' ', (size_t)((*syntax).width - len));
		write(fd, str, (size_t)((*syntax).width - len));
	}
	else if ((*syntax).falgs.zero == 1)
	{
		ft_memset(str, '0', (size_t)((*syntax).width - len));
		write(fd, str, (size_t)((*syntax).width - len));
		ft_print_3_ss_conv(fd, arg);
	}
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - len));
		write(fd, str, (size_t)((*syntax).width - len));
		ft_print_3_ss_conv(fd, arg);
	}
}

int		ft_lstrlen(wchar_t *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			len += 1;
		else if (*str <= 0x7FF)
			len += 2;
		else if (*str <= 0xFFFF)
			len += 3;
		else if (*str <= 0x10FFFF)
			len += 4;
		str++;
	}
	return (len);
}

int		ft_print_ss_conv(int fd, t_syntax *syntax, va_list *ap)
{
	int			len;
	wchar_t		*arg;

	if (MB_CUR_MAX == 1)
		return (-1);
	arg = va_arg(*ap, wchar_t *);
	if (arg == NULL)
		arg = NSTR_L;
	len = ft_lstrlen(arg);
	if ((*syntax).width > len)
	{
		ft_print_2_ss_conv(fd, syntax, arg, len);
		return ((*syntax).width);
	}
	else
		ft_print_3_ss_conv(fd, arg);
	return (len);
}
