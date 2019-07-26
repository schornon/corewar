/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:50:59 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/12 14:51:01 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_xx_z(int fd, t_syntax *syntax, va_list *ap)
{
	int			len;
	size_t		arg;
	uintmax_t	arg_new;

	arg = va_arg(*ap, size_t);
	arg_new = (uintmax_t)arg;
	len = ft_xx_j_2(fd, syntax, arg_new);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
