/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:49:47 by sbudilko          #+#    #+#             */
/*   Updated: 2017/12/05 10:49:48 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_quantity(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s == c)
		s++;
	while (*s)
		if (*s++ != c)
			if (*s == c || *s == '\0')
				count++;
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str_split;
	int		word_quantity;
	int		word_len;
	int		i;
	int		k;

	i = -1;
	if (!s)
		return (NULL);
	word_quantity = ft_word_quantity(s, c);
	if (!(str_split = (char**)malloc(sizeof(*str_split) * (word_quantity + 1))))
		return (NULL);
	while (++i < word_quantity)
	{
		k = 0;
		while (*s == c)
			s++;
		word_len = ft_word_len(s, c);
		if (!(str_split[i] = ft_strnew(word_len)))
			return (NULL);
		while (k < word_len)
			str_split[i][k++] = *s++;
	}
	str_split[i] = 0;
	return (str_split);
}
