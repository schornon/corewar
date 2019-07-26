/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:13:14 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/29 14:13:16 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	cmp;
	unsigned long long	result;

	sign = 1;
	result = 0;
	cmp = 9223372036854775807;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + *str++ - '0';
		if (result > cmp && sign == 1)
			return (-1);
		if (result > cmp && sign == -1)
			return (0);
	}
	return ((int)result * sign);
}
