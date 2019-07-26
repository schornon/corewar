/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:27:38 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/04 16:27:39 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res_of_conc;
	char	*ptr;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res_of_conc = ft_strnew(len_s1 + len_s2);
	ptr = res_of_conc;
	if (!res_of_conc)
		return (NULL);
	while (len_s1-- > 0)
		*ptr++ = *s1++;
	ft_strcat(res_of_conc, s2);
	return (res_of_conc);
}
