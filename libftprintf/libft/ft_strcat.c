/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 13:40:32 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/23 13:40:34 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	shift;
	size_t	count;
	char	*ptr_s1;

	count = 0;
	shift = ft_strlen(s1);
	ptr_s1 = s1 + shift;
	while (*s2 != '\0')
		*ptr_s1++ = *s2++;
	*ptr_s1 = '\0';
	return (s1);
}
