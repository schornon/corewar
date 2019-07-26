/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 13:19:58 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/08 13:20:00 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *head_lst;
	t_list *new_lst;

	if (!lst)
		return (NULL);
	new_lst = f(lst);
	if (!(fresh = ft_lstnew(new_lst->content, new_lst->content_size)))
		return (NULL);
	head_lst = fresh;
	lst = lst->next;
	while (lst)
	{
		new_lst = f(lst);
		if (!(fresh->next = ft_lstnew(new_lst->content, new_lst->content_size)))
			return (NULL);
		lst = lst->next;
		fresh = fresh->next;
	}
	return (head_lst);
}
