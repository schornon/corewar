/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:39:37 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/11 15:39:40 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	while (len-- > 0)
	{
		if (*(unsigned char*)(s1++) != *(unsigned char*)(s2++))
			return (*(unsigned char*)(--s1) - *(unsigned char*)(--s2));
	}
	return (0);
}
