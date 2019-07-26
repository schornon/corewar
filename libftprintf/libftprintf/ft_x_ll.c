/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_ll.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:55:07 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/12 13:55:08 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_x_ll(int fd, t_syntax *syntax, va_list *ap)
{
	int						len;
	unsigned long long int	arg;
	uintmax_t				new_arg;

	arg = va_arg(*ap, unsigned long long int);
	new_arg = (uintmax_t)arg;
	len = ft_x_j_2(fd, syntax, new_arg);
	if (arg == 0 && (*syntax).precision == 0 &&
		(*syntax).width == 0)
		len--;
	return (len);
}
