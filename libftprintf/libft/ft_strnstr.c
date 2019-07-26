/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:49:24 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/27 18:49:26 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t shift;
	size_t count_haystack;
	size_t count_needle;
	size_t flag;

	shift = 0;
	flag = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (shift < len && haystack[shift])
	{
		count_needle = 0;
		count_haystack = shift++;
		while (needle[count_needle] && (count_haystack < len))
		{
			if (needle[count_needle++] != haystack[count_haystack++])
				break ;
			if (flag == count_needle)
				return ((char*)haystack + shift - 1);
		}
	}
	return (NULL);
}
