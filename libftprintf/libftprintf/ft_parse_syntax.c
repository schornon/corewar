/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_syntax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:01:01 by sbudilko          #+#    #+#             */
/*   Updated: 2018/03/26 14:01:03 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** -------------------------------------------------------------------------- **
**|  filename - ft_parse_syntax.c                                            |**
**|                                                                          |**
**|  function(s)                                                             |**
**|         ft_parse_flags - parse flags                                     |**
**|         ft_parse_width - parse width                                     |**
**|         ft_parse_precision - parse precision                             |**
**|         ft_parse_length - parse length                                   |**
**|         ft_parse_type - parse type (conversion specifiers)               |**
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
**| Name            ft_parse_flags                                           |**
**|                                                                          |**
**| Description     Param. #1 - adress of the pointer to "format" str.       |**
**|                 Param. #2 - adress of the struct "syntax" (va_list).     |**
**|                 Function takes zero element of str, if it equal to       |**
**|                 parametr, func. finds which field of structure           |**
**|                 (*syntax).falgs corresponds to the flag and assigns it   |**
**|                 the value 1, after this, the pointer moves to one        |**
**|                 position and recursively calls the function.             |**
**|                                                                          |**
**| Return value    None.                                                    |**
** -------------------------------------------------------------------------- **
*/

void	ft_parse_flags(char **str, t_syntax *syntax)
{
	if ((*str)[0] == '-' || (*str)[0] == '+' || (*str)[0] == ' ' ||
		(*str)[0] == '0' || (*str)[0] == '#')
	{
		if ((*str)[0] == '-')
			(*syntax).falgs.minus = 1;
		else if ((*str)[0] == '+')
			(*syntax).falgs.plus = 1;
		else if ((*str)[0] == ' ')
			(*syntax).falgs.space = 1;
		else if ((*str)[0] == '0')
			(*syntax).falgs.zero = 1;
		else if ((*str)[0] == '#')
			(*syntax).falgs.hash = 1;
		(*str)++;
		ft_parse_flags(str, syntax);
	}
}

/*
** -------------------------------------------------------------------------- **
**| Name            ft_parse_width                                           |**
**|                                                                          |**
**| Description     Param. #1 - adress of the pointer to "format" str.       |**
**|                 Param. #2 - adress of the variable "ap" (va_list).       |**
**|                 Param. #3 - adress of the struct "syntax" (t_syntax).    |**
**|                                                                          |**
**| Return value    None.                                                    |**
** -------------------------------------------------------------------------- **
*/

void	ft_parse_width(char **str, va_list *ap, t_syntax *syntax)
{
	if (ft_isdigit((*str)[0]) == 1)
		(*syntax).width = 0;
	while (ft_isdigit((*str)[0]) == 1)
	{
		(*syntax).width = (*syntax).width * 10 + (*str)[0] - '0';
		(*str)++;
	}
	if ((*str)[0] == '*')
	{
		(*syntax).width = va_arg(*ap, int);
		(*str)++;
		ft_parse_width(str, ap, syntax);
	}
}

/*
** -------------------------------------------------------------------------- **
**| Name            ft_parse_precision                                       |**
**|                                                                          |**
**| Description     Param. #1 - adress of the pointer to "format" str.       |**
**|                 Param. #2 - adress of the variable "ap" (va_list).       |**
**|                 Param. #3 - adress of the struct "syntax" (t_syntax).    |**
**|                                                                          |**
**| Return value    None.                                                    |**
** -------------------------------------------------------------------------- **
*/

void	ft_parse_precision(char **str, va_list *ap, t_syntax *syntax)
{
	if (ft_isdigit((*str)[0]) == 1 || (*syntax).precision == -1)
		(*syntax).precision = 0;
	if ((*str)[0] == '%')
		return ;
	while (ft_isdigit((*str)[0]) == 1)
	{
		(*syntax).precision = (*syntax).precision * 10 + (*str)[0] - '0';
		(*str)++;
	}
	if ((*str)[0] == '*')
	{
		(*syntax).precision = va_arg(*ap, int);
		(*str)++;
		ft_parse_precision(str, ap, syntax);
	}
	else if ((*str)[0] == '.')
	{
		(*str)++;
		ft_parse_precision(str, ap, syntax);
	}
}

/*
** -------------------------------------------------------------------------- **
**| Name            ft_parse_length                                          |**
**|                                                                          |**
**| Description     Param. #1 - adress of the pointer to "format" str.       |**
**|                 Param. #2 - adress of the struct "syntax" (t_syntax).    |**
**|                                                                          |**
**| Return value    None.                                                    |**
** -------------------------------------------------------------------------- **
*/

void	ft_parse_length(char **str, t_syntax *syntax)
{
	if ((*str)[0] == 'h')
		if ((*str)[1] == 'h')
		{
			(*syntax).length.hh = 1;
			(*str)++;
		}
		else
			(*syntax).length.h = 1;
	else if ((*str)[0] == 'l')
		if ((*str)[1] == 'l')
		{
			(*syntax).length.ll = 1;
			(*str)++;
		}
		else
			(*syntax).length.l = 1;
	else if ((*str)[0] == 'j')
		(*syntax).length.j = 1;
	else if ((*str)[0] == 'z')
		(*syntax).length.z = 1;
}

/*
** -------------------------------------------------------------------------- **
**| Name            ft_parse_type                                            |**
**|                                                                          |**
**| Description     Param. #1 - adress of the struct "syntax" (t_syntax).    |**
**|                 Function searches in array "TYPE" character "c". If "c"  |**
**|                 contained in array - (*syntax).type becomes equal to     |**
**|                 index of array. Else (*syntax).type = -1                 |**
**|                                                                          |**
**| Return value    None.                                                    |**
** -------------------------------------------------------------------------- **
*/

void	ft_parse_type(t_syntax *syntax, char c)
{
	int		i;

	i = 0;
	while (TYPE[i] != '\0')
	{
		if (TYPE[i] == c)
		{
			(*syntax).type = i;
			return ;
		}
		i++;
	}
	(*syntax).type = -1;
}
