/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:50:42 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/12 14:50:43 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_xx_l(int fd, t_syntax *syntax, va_list *ap)
{
	int					len;
	unsigned long int	arg;
	uintmax_t			new_arg;

	arg = va_arg(*ap, unsigned long int);
	new_arg = (uintmax_t)arg;
	len = ft_xx_j_2(fd, syntax, new_arg);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
