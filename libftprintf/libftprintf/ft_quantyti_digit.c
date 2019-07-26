/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quantyti_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 13:20:00 by sbudilko          #+#    #+#             */
/*   Updated: 2018/05/08 13:20:01 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_quantity_digit(int n)
{
	int		i;
	long	new_n;

	new_n = n;
	if (new_n < 0)
		new_n = -new_n;
	i = 1;
	while (new_n >= 10)
	{
		new_n /= 10;
		i++;
	}
	return (i);
}

int		ft_quantity_digit_ll(long long int n)
{
	int		i;

	if (n == LLONG_MIN)
		return (19);
	if (n < 0)
		n = -n;
	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_quantity_digit_ull(unsigned long long int n)
{
	int		i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_quantity_digit_l(long int n)
{
	int		i;

	if (n == 2147483648)
		return (10);
	if (n < 0)
		n = -n;
	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}
