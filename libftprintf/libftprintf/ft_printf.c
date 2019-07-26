/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:14:25 by sbudilko          #+#    #+#             */
/*   Updated: 2018/02/27 14:14:28 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** -------------------------------------------------------------------------- **
**|  filename - ft_printf.c                                                  |**
**|                                                                          |**
**|  function(s)                                                             |**
**|         ft_printf - send formatted output to stdout                      |**
**|         ft_print_param - print argument to file descriptor               |**
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
**| Name           ft_printf_param                                           |**
**|                                                                          |**
**| Description    Param. #1 - adress of the pointer to "format" str.        |**
**|                Param. #2 - adress of the variable "ap" (va_list).        |**
**|                Param. #3 - adress of the struct "syntax" (t_syntax).     |**
**|                Function equates the fields of "syntax" struct to zero,   |**
**|                because it may contain garbage after previous use.        |**
**|                Parsing syntax and outputting an argument according to    |**
**|                the syntax.                                               |**
**|                                                                          |**
**| Return value   the number of bytes output.                               |**
** -------------------------------------------------------------------------- **
*/

int		ft_print_param(int fd, char **str, va_list *ap, t_syntax *syntax)
{
	int		i;
	int		(*func_arr[NB_CS])(int, t_syntax *, va_list *);

	ft_fill_func_arr(func_arr);
	(*str)++;
	if ((*str)[0] == '\0')
		return (0);
	ft_cleaning_struct(syntax);
	ft_parse_syntax(str, ap, syntax);
	if ((*syntax).type >= 0)
		i = func_arr[(*syntax).type](fd, syntax, ap);
	else
	{
		i = ft_print_without_conv(fd, syntax, (*str)[0]);
		if ((*str)[0] == '\0')
			return (i);
		(*str)++;
	}
	return (i);
}

/*
** -------------------------------------------------------------------------- **
**| Name            ft_printf                                                |**
**|                                                                          |**
**| Description     sends formatted output to stdout.                        |**
**|                                                                          |**
**| Return value    the number of bytes output.                              |**
** -------------------------------------------------------------------------- **
*/

int		ft_printf(const char *s, ...)
{
	int			res;
	int			fd;
	va_list		ap;

	fd = 0;
	va_start(ap, s);
	if (ft_strlen(s) >= 5 && ft_strncmp(s, FD, 5) == 0)
	{
		fd = va_arg(ap, int);
		s += 5;
	}
	else
		fd = 1;
	res = ft_fprintf(fd, s, &ap);
	va_end(ap);
	return (res);
}
