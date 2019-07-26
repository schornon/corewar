/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:28:49 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/05 18:28:52 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_str(char *s)
{
	size_t	len;
	char	*ptr_pref;
	char	*ptr_suff;
	char	buff;

	len = ft_strlen(s);
	ptr_pref = s;
	ptr_suff = s + len - 1;
	len = len / 2;
	while (len--)
	{
		buff = *ptr_suff;
		*ptr_suff-- = *ptr_pref;
		*ptr_pref++ = buff;
	}
	return (s);
}
