/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:12:25 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/05 15:12:28 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_quantity_char(long n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;
	long	new_n;

	sign = 0;
	i = 0;
	new_n = (long)n;
	if (new_n < 0)
	{
		sign = 1;
		new_n = -new_n;
	}
	str = ft_strnew(ft_quantity_char(new_n) + sign);
	if (!str)
		return (NULL);
	while (new_n >= 10)
	{
		str[i++] = new_n % 10 + 48;
		new_n /= 10;
	}
	str[i] = new_n + 48;
	if (sign)
		str[++i] = '-';
	return (ft_reverse_str(str));
}
