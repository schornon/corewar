/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:35:59 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/23 12:36:02 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *ptr_dest;

	ptr_dest = dest;
	while (*src != '\0' && len > 0)
	{
		*ptr_dest++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*ptr_dest++ = '\0';
		len--;
	}
	return (dest);
}
