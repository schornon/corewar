/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:59:48 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/06 11:59:49 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	new_n;

	new_n = n;
	if (new_n < 0)
	{
		ft_putchar_fd('-', fd);
		new_n = -new_n;
	}
	if (new_n >= 10)
		ft_putnbr_fd(new_n / 10, fd);
	ft_putchar_fd(new_n % 10 + 48, fd);
}
