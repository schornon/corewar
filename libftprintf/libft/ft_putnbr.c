/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:02:15 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/06 11:02:17 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	new_n;

	new_n = n;
	if (new_n < 0)
	{
		ft_putchar('-');
		new_n = -new_n;
	}
	if (new_n >= 10)
		ft_putnbr(new_n / 10);
	ft_putchar(new_n % 10 + 48);
}
