/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 11:28:49 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/04 11:28:51 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str_new;
	char	*ptr;

	str_new = (char*)malloc(sizeof(char) * size + 1);
	ptr = str_new;
	if (!str_new)
		return (NULL);
	while (size-- > 0)
		*ptr++ = '\0';
	*ptr = '\0';
	return (str_new);
}
