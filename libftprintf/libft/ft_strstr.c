/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:29:31 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/27 17:29:33 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t shift;
	size_t count_haystack;
	size_t count_needle;
	size_t flag;

	shift = 0;
	flag = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[shift])
	{
		count_needle = 0;
		count_haystack = shift++;
		while (needle[count_needle])
		{
			if (needle[count_needle++] != haystack[count_haystack++])
				break ;
			if (flag == count_needle)
				return ((char*)haystack + shift - 1);
		}
	}
	return (NULL);
}
