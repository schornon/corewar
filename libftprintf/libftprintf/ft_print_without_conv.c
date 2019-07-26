/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_without_conv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 19:44:36 by sbudilko          #+#    #+#             */
/*   Updated: 2018/04/02 19:44:37 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_2_without_conv(int fd, t_syntax *syntax, char c)
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

int		ft_print_without_conv(int fd, t_syntax *syntax, char c)
{
	if (c == '\0')
		return (0);
	if ((*syntax).width > 1)
	{
		ft_print_2_without_conv(fd, syntax, c);
		return ((*syntax).width);
	}
	else
		write(fd, &c, 1);
	return (1);
}
