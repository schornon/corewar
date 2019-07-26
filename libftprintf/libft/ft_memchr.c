/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:10:06 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/11 14:10:08 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)s;
	while (len-- > 0)
		if (*ptr++ == (unsigned char)c)
			return (--ptr);
	return (NULL);
}
