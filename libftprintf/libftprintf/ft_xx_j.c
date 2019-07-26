/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_j.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 16:00:30 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/12 16:00:31 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_xx_j_4(int fd, t_syntax *syn, char *str, int len_pre)
{
	char	str2[len_pre];

	ft_memset(str2, '0', (size_t)(len_pre));
	if ((*syn).falgs.hash == 1 && ft_strlen(str) > 2)
	{
		str += 2;
		ft_putstr_fd("0X", fd);
	}
	write(fd, str2, len_pre);
	if (str[0] == '0' && (*syn).precision == 0
		&& (str[1] == '0' || str[1] == '\0'))
	{
		if ((*syn).width != 0 && ft_strlen(str) == 1)
			ft_putchar_fd(' ', fd);
		else if (ft_strlen(str) != 1)
		{
			if ((*syn).width > 1)
				ft_putchar_fd(' ', fd);
			ft_putchar_fd('0', fd);
		}
		else
			return ;
	}
	else
		ft_putstr_fd(str, fd);
}

void	ft_xx_j_3(int fd, t_syntax *syntax, char *str2, int *len)
{
	char	str[(*syntax).width - len[0]];

	if ((*syntax).falgs.minus == 1)
	{
		ft_xx_j_4(fd, syntax, str2, len[1]);
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
	}
	else if ((*syntax).falgs.zero == 1)
		if ((*syntax).precision == -1)
			ft_xx_j_4(fd, syntax, str2, (*syntax).width - len[0]);
		else
			ft_xx_j_4(fd, syntax, str2, len[1]);
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
		ft_xx_j_4(fd, syntax, str2, len[1]);
	}
}

int		ft_xx_j_2(int fd, t_syntax *syntax, uintmax_t arg)
{
	int		len[2];
	char	*str;

	len[1] = 0;
	len[0] = ft_quantity_digit_ull(arg);
	if (arg == 0)
		str = ft_strdup("0");
	else
		str = ft_dec_to_hex_2(arg, len[0], syntax);
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - ft_strlen(str);
	len[0] = ft_strlen(str) + len[1];
	if ((*syntax).width > len[0])
	{
		ft_xx_j_3(fd, syntax, str, len);
		free(str);
		return ((*syntax).width);
	}
	else
	{
		ft_xx_j_4(fd, syntax, str, len[1]);
		free(str);
		return (len[0]);
	}
}

int		ft_xx_j(int fd, t_syntax *syntax, va_list *ap)
{
	int			len;
	uintmax_t	arg;

	arg = va_arg(*ap, uintmax_t);
	len = ft_xx_j_2(fd, syntax, arg);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
