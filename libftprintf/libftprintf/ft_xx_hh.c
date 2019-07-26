/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xx_hh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:50:35 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/12 14:50:37 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_xx_hh(int fd, t_syntax *syntax, va_list *ap)
{
	int				len;
	int				new_arg;
	unsigned char	arg;

	arg = va_arg(*ap, int);
	new_arg = (uintmax_t)arg;
	len = ft_xx_j_2(fd, syntax, new_arg);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
