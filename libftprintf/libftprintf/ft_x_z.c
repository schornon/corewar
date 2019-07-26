/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:55:13 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/12 13:55:15 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_x_z(int fd, t_syntax *syntax, va_list *ap)
{
	int			len;
	size_t		arg;
	uintmax_t	arg_new;

	arg = va_arg(*ap, size_t);
	arg_new = (uintmax_t)arg;
	len = ft_x_j_2(fd, syntax, arg_new);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
