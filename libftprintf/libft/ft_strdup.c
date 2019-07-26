/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:10:49 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/18 17:59:22 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		len;
	int		shift_ptr;

	len = ft_strlen(s);
	shift_ptr = len;
	if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len-- > 0)
		*new_str++ = *s++;
	*new_str = '\0';
	return (new_str - shift_ptr);
}
