/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:37:52 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/18 18:16:30 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_lst;

	new_lst = (t_list*)malloc(sizeof(t_list));
	if (!new_lst)
		return (0);
	if (!content)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		new_lst->content = malloc(content_size);
		new_lst->content_size = content_size;
		ft_memcpy(new_lst->content, content, content_size);
	}
	new_lst->next = NULL;
	return (new_lst);
}
