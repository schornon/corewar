/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:01:11 by sbudilko          #+#    #+#             */
/*   Updated: 2018/03/26 14:01:14 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** -------------------------------------------------------------------------- **
**|  filename - ft_syntax_struct.c                                           |**
**|                                                                          |**
**|  function(s)                                                             |**
**|         ft_cleaning_struct - fill an array of pointers to a function     |**
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
**| Name            ft_cleaning_struct                                       |**
**|                                                                          |**
**| Description     Param #1 - adress of the struct "syntax" (t_syntax)      |**
**|                 Function equates the fields of "syntax" struct to zero   |**
**|                 precision = -1 because precison can be equal to zero     |**
**|                                                                          |**
**| Return value    None.                                                    |**
** -------------------------------------------------------------------------- **
*/

void	ft_cleaning_struct(t_syntax *syntax)
{
	(*syntax).falgs.minus = 0;
	(*syntax).falgs.plus = 0;
	(*syntax).falgs.space = 0;
	(*syntax).falgs.zero = 0;
	(*syntax).falgs.hash = 0;
	(*syntax).width = 0;
	(*syntax).precision = -1;
	(*syntax).length.h = 0;
	(*syntax).length.hh = 0;
	(*syntax).length.l = 0;
	(*syntax).length.ll = 0;
	(*syntax).length.j = 0;
	(*syntax).length.z = 0;
	(*syntax).type = 0;
}
