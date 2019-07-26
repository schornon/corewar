/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:55:43 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/12 18:40:33 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** -------------------------------------------------------------------------- **
**|  filename - ft_fprintf.c                                                 |**
**|                                                                          |**
**|  function(s)                                                             |**
**|         ft_printf - send formatted output to stdout                      |**
** -------------------------------------------------------------------------- **
**                                                                            **
** -------------------------------------------------------------------------- **
**|     Copyright (c) 2018 by sbudilko UnitFactory                           |**
**|     All Rights Reserved.                                                 |**
** -------------------------------------------------------------------------- **
*/

#include "../includes/ft_printf.h"

/*
** -------------------------------------------------------------------------- **
**| Name            ft_fprintf                                               |**
**|                                                                          |**
**| Description     sends formatted output to file descriptor.               |**
**|                                                                          |**
**| Return value    the number of bytes output.                              |**
** -------------------------------------------------------------------------- **
*/

int		ft_fprintf_2(int fd, const char *s, va_list *ap)
{
	int			res;
	int			res_2;
	char		*str;
	t_syntax	syntax;

	res = 0;
	str = (char*)s;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			res_2 = ft_print_param(fd, &str, ap, &syntax);
			res += res_2;
			if (res_2 == -1)
				return (-1);
		}
		if (*str == '\0')
			break ;
		if (*str == '%')
			continue ;
		write(fd, str, 1);
		res++;
		str++;
	}
	return (res);
}

int		ft_fprintf(int fd, const char *s, va_list *ap)
{
	int			res;

	if (fd != 1)
	{
		write(1, "Bad file descriptor\n", 20);
		return (0);
	}
	res = ft_fprintf_2(fd, s, ap);
	return (res);
}
