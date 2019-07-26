/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:54:31 by sbudilko          #+#    #+#             */
/*   Updated: 2018/04/24 15:54:32 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_2_c_conv(int fd, t_syntax *syntax, char c)
{
	char	str[(*syntax).width - 1];

	if ((*syntax).falgs.minus == 1)
	{
		write(fd, &c, 1);
		ft_memset(str, ' ', (size_t)((*syntax).width - 1));
		write(fd, str, (size_t)((*syntax).width - 1));
	}
	else if ((*syntax).falgs.zero == 1)
	{
		ft_memset(str, '0', (size_t)((*syntax).width - 1));
		write(fd, str, (size_t)((*syntax).width - 1));
		write(fd, &c, 1);
	}
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - 1));
		write(fd, str, (size_t)((*syntax).width - 1));
		write(fd, &c, 1);
	}
}

int		ft_print_c_conv(int fd, t_syntax *syntax, va_list *ap)
{
	int		len;
	char	c;

	if ((*syntax).length.l == 1)
		len = ft_print_cc_conv(fd, syntax, ap);
	else
	{
		c = va_arg(*ap, int);
		if ((*syntax).width > 1)
		{
			ft_print_2_c_conv(fd, syntax, c);
			return ((*syntax).width);
		}
		else
		{
			write(fd, &c, 1);
			return (1);
		}
	}
	return (len);
}
