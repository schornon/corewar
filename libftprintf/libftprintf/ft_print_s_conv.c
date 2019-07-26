/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:18:12 by sbudilko          #+#    #+#             */
/*   Updated: 2018/03/27 14:18:14 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_2_s_conv(int fd, t_syntax *syntax, char *arg, int len)
{
	char	str[(*syntax).width - len];

	if ((*syntax).falgs.minus == 1)
	{
		write(fd, arg, len);
		ft_memset(str, ' ', (size_t)((*syntax).width - len));
		write(fd, str, (size_t)((*syntax).width - len));
	}
	else if ((*syntax).falgs.zero == 1)
	{
		ft_memset(str, '0', (size_t)((*syntax).width - len));
		write(fd, str, (size_t)((*syntax).width - len));
		write(fd, arg, len);
	}
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - len));
		write(fd, str, (size_t)((*syntax).width - len));
		write(fd, arg, len);
	}
}

int		ft_print_s_conv(int fd, t_syntax *syntax, va_list *ap)
{
	int		len;
	char	*arg;

	if ((*syntax).length.l == 1)
		len = ft_print_ss_conv(fd, syntax, ap);
	else
	{
		arg = va_arg(*ap, char *);
		if (arg == NULL)
			arg = NSTR;
		len = ft_strlen(arg);
		if ((*syntax).precision < len && (*syntax).precision != -1)
			len = (*syntax).precision;
		if ((*syntax).width > len)
		{
			ft_print_2_s_conv(fd, syntax, arg, len);
			return ((*syntax).width);
		}
		else
			write(fd, arg, len);
	}
	return (len);
}
