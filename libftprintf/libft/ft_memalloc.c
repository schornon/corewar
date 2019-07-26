/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:27:02 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/18 17:56:24 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	res = (void*)malloc(size);
	if (res != NULL)
		while (i < size)
		{
			((char*)res)[i] = 0;
			i++;
		}
	return (res);
}
