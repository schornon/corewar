/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o_j.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:28:41 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/04 16:28:43 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_dec_to_octal_3(uintmax_t arg, int len, t_syntax *syntax)
{
	char	*str;
	int		i;
	int		remainder;

	i = 0;
	if (arg == 0 && (*syntax).falgs.hash == 1)
		(*syntax).precision = 0;
	if ((*syntax).falgs.hash == 1)
		str = ft_strnew(len + 4);
	else
		str = ft_strnew(len + 3);
	while (arg > 7)
	{
		remainder = (int)(arg % 8);
		str[i] = remainder + '0';
		i++;
		arg = arg / 8;
	}
	str[i] = arg + '0';
	i++;
	if ((*syntax).falgs.hash == 1)
		str[i] = '0';
	return (ft_reverse_str(str));
}

void	ft_o_j_4(int fd, t_syntax *syn, char *str, int len_pre)
{
	char	str2[len_pre];

	ft_memset(str2, '0', (size_t)(len_pre));
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

void	ft_o_j_3(int fd, t_syntax *syntax, char *str2, int *len)
{
	char	str[(*syntax).width - len[0]];

	if ((*syntax).falgs.minus == 1)
	{
		ft_o_j_4(fd, syntax, str2, len[1]);
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
	}
	else if ((*syntax).falgs.zero == 1)
		if ((*syntax).precision == -1)
			ft_o_j_4(fd, syntax, str2, (*syntax).width - len[0]);
		else
			ft_o_j_4(fd, syntax, str2, len[1]);
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
		ft_o_j_4(fd, syntax, str2, len[1]);
	}
}

int		ft_o_j_2(int fd, t_syntax *syntax, uintmax_t arg)
{
	int		len[2];
	char	*str;

	len[1] = 0;
	len[0] = ft_quantity_digit_ull(arg);
	str = ft_dec_to_octal_3(arg, len[0], syntax);
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - len[0];
	len[0] = ft_strlen(str) + len[1];
	if ((*syntax).width > len[0])
	{
		ft_o_j_3(fd, syntax, str, len);
		free(str);
		str = NULL;
		return ((*syntax).width);
	}
	else
	{
		ft_o_j_4(fd, syntax, str, len[1]);
		free(str);
		str = NULL;
		return (len[0]);
	}
}

int		ft_o_j(int fd, t_syntax *syntax, va_list *ap)
{
	int			len;
	uintmax_t	arg;

	arg = va_arg(*ap, uintmax_t);
	len = ft_o_j_2(fd, syntax, arg);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
