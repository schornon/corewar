/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 12:43:37 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/12 12:43:38 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_dec_to_hex(uintmax_t arg, int len, t_syntax *syntax)
{
	char	*str;
	int		i;

	i = 0;
	if (arg == 0)
		return (ft_strdup("0"));
	str = ft_strnew(len + 10);
	while (arg > 15)
	{
		if ((arg % 16) >= 10)
			str[i++] = arg % 16 + 87;
		else
			str[i++] = arg % 16 + '0';
		arg = arg / 16;
	}
	if (arg >= 10)
		str[i++] = arg + 87;
	else
		str[i++] = arg + '0';
	if ((*syntax).falgs.hash == 1)
	{
		str[i++] = 'x';
		str[i] = '0';
	}
	return (ft_reverse_str(str));
}

void	ft_print_x_conv_4(int fd, t_syntax *syn, char *str, int len_pre)
{
	char	str2[len_pre];

	ft_memset(str2, '0', (size_t)(len_pre));
	if ((*syn).falgs.hash == 1 && ft_strlen(str) > 2)
	{
		str += 2;
		ft_putstr_fd("0x", fd);
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

void	ft_print_x_conv_3(int fd, t_syntax *syntax, char *str2, int *len)
{
	char	str[(*syntax).width - len[0]];

	if ((*syntax).falgs.minus == 1)
	{
		ft_print_x_conv_4(fd, syntax, str2, len[1]);
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
	}
	else if ((*syntax).falgs.zero == 1)
		if ((*syntax).precision == -1)
			ft_print_x_conv_4(fd, syntax, str2, (*syntax).width - len[0]);
		else
		{
			ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
			write(fd, str, (size_t)((*syntax).width - len[0]));
			ft_print_x_conv_4(fd, syntax, str2, len[1]);
		}
	else
	{
		ft_memset(str, ' ', (size_t)((*syntax).width - len[0]));
		write(fd, str, (size_t)((*syntax).width - len[0]));
		ft_print_x_conv_4(fd, syntax, str2, len[1]);
	}
}

int		ft_print_x_conv_2(int fd, t_syntax *syntax, va_list *ap)
{
	unsigned int	arg;
	int				len[2];
	char			*str;

	len[1] = 0;
	arg = va_arg(*ap, unsigned int);
	len[0] = ft_quantity_digit_ull(arg);
	str = ft_dec_to_hex(arg, 19, syntax);
	if ((*syntax).precision != -1 && ((*syntax).precision - len[0]) > 0)
		len[1] = (*syntax).precision - ft_strlen(str);
	len[0] = ft_strlen(str) + len[1];
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len[0]--;
	if ((*syntax).width > len[0])
	{
		ft_print_x_conv_3(fd, syntax, str, len);
		free(str);
		return ((*syntax).width);
	}
	else
		ft_print_x_conv_4(fd, syntax, str, len[1]);
	free(str);
	return (len[0]);
}

int		ft_print_x_conv(int fd, t_syntax *syntax, va_list *ap)
{
	int		len;

	if ((*syntax).length.hh == 1)
		len = ft_x_hh(fd, syntax, ap);
	else if ((*syntax).length.h == 1)
		len = ft_x_h(fd, syntax, ap);
	else if ((*syntax).length.l == 1)
		len = ft_x_l(fd, syntax, ap);
	else if ((*syntax).length.ll == 1)
		len = ft_x_ll(fd, syntax, ap);
	else if ((*syntax).length.j == 1)
		len = ft_x_j(fd, syntax, ap);
	else if ((*syntax).length.z == 1)
		len = ft_x_z(fd, syntax, ap);
	else
		len = ft_print_x_conv_2(fd, syntax, ap);
	return (len);
}
