/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:29:26 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/09 17:47:41 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char *ptr_dest;
	unsigned char *ptr_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr_dest = (unsigned char*)dest;
	ptr_src = (unsigned char*)src;
	while (len-- > 0)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}
