/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:26:53 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/11 12:26:56 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *ptr_dest;
	unsigned char *ptr_src;

	ptr_dest = (unsigned char*)dest;
	ptr_src = (unsigned char*)src;
	if (ptr_dest < ptr_src)
		while (len-- > 0)
			*ptr_dest++ = *ptr_src++;
	else
		while (len-- > 0)
			*(ptr_dest + len) = *(ptr_src + len);
	return (dest);
}
