/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:44:46 by sbudilko          #+#    #+#             */
/*   Updated: 2017/11/11 18:44:50 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, const char *src)
{
	char *ptr_dest;
	char *ptr_src;

	ptr_dest = dest;
	ptr_src = (char*)src;
	while (*ptr_src != '\0')
		*ptr_dest++ = *ptr_src++;
	*ptr_dest = '\0';
	return (dest);
}
