/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:48:55 by schornon          #+#    #+#             */
/*   Updated: 2019/06/03 16:25:20 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_pow(int x, unsigned int n)
{
	if (n == 0)
		return (1);
	if (n % 2 == 0)
		return (ft_pow(x, n / 2) * ft_pow(x, n / 2));
	else
		return (x * ft_pow(x, n / 2) * ft_pow(x, n / 2));
}
