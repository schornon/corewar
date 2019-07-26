/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:21:34 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/23 14:21:36 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	shift;
	char	*ptr_s1;

	shift = ft_strlen(s1);
	ptr_s1 = s1 + shift;
	while (*s2 != '\0' && n-- > 0)
		*ptr_s1++ = *s2++;
	*ptr_s1 = '\0';
	return (s1);
}
