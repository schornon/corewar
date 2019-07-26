/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 12:53:49 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/18 17:35:02 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*str_new;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	str_new = ft_strnew(len);
	if (!str_new)
		return (NULL);
	while (len-- > 0)
		str_new[len] = f(s[len]);
	return (str_new);
}
