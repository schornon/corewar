/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:04:54 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/04 17:05:12 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_white_space(int c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

static size_t	ft_prefix_spaces(char const *s)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (ft_is_white_space(s[i]))
			count++;
		else
			break ;
		i++;
	}
	return (count);
}

static size_t	ft_suffix_spaces(char const *s)
{
	int count;
	int i;

	count = 0;
	i = ft_strlen(s);
	while (i-- > 0)
	{
		if (ft_is_white_space(s[i]))
			count++;
		else
			break ;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char	*new_str;
	size_t	prefix_spces;
	size_t	suffix_spaces;
	size_t	len;

	if (s == NULL)
		return (NULL);
	prefix_spces = ft_prefix_spaces(s);
	suffix_spaces = ft_suffix_spaces(s);
	len = ft_strlen(s) - prefix_spces - suffix_spaces;
	if (-len == prefix_spces)
		len = 0;
	new_str = ft_strsub(s, prefix_spces, len);
	return (new_str);
}
