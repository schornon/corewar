/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:49:42 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/27 16:49:45 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*ptr_new;
	int		flag;

	ptr = (char*)s;
	ptr_new = (char*)s;
	flag = 0;
	if ((char)c == '\0')
		return (ptr + ft_strlen(s));
	while (*ptr != '\0')
		if (*ptr++ == (char)c)
		{
			ptr_new = ptr;
			flag = 1;
		}
	if (flag)
		return (--ptr_new);
	else
		return (NULL);
}
