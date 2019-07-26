/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_z.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:12:23 by sbudilko          #+#    #+#             */
/*   Updated: 2018/05/08 13:12:25 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_d_z(int fd, t_syntax *syntax, va_list *ap)
{
	int			len;
	intmax_t	arg;
	ssize_t		new_arg;

	arg = va_arg(*ap, intmax_t);
	new_arg = (ssize_t)arg;
	len = ft_d_j_2(fd, syntax, arg);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
