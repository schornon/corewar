/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:01:48 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/12 18:47:23 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** -------------------------------------------------------------------------- **
**|  filename - ft_syntax.c                                                  |**
**|                                                                          |**
**|  function(s)                                                             |**
**|         ft_parse_syntax - parse syntax                                   |**
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
**| Name            ft_parse_syntax                                          |**
**|                                                                          |**
**| Description     Param. #1 - adress of the pointer to "format" str.       |**
**|                 Param. #2 - adress of the variable "ap" (va_list).       |**
**|                 Param. #3 - adress of the struct "syntax" (t_syntax).    |**
**|                                                                          |**
**| Return value    None.                                                    |**
** -------------------------------------------------------------------------- **
*/

void	ft_parse_syntax(char **str, va_list *ap, t_syntax *syntax)
{
	ft_parse_flags(str, syntax);
	ft_parse_width(str, ap, syntax);
	if ((*str)[0] == '.')
	{
		(*str)++;
		ft_parse_precision(str, ap, syntax);
	}
	while ((*str)[0] == 'h' || (*str)[0] == 'l' || (*str)[0] == 'j' ||
			(*str)[0] == 'z')
	{
		ft_parse_length(str, syntax);
		(*str)++;
	}
	ft_parse_type(syntax, (*str)[0]);
	if ((*syntax).type >= 0)
		(*str)++;
	if ((*syntax).width < 0)
		(*syntax).width = (*syntax).width * (-1);
}
