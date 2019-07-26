/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_func_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 14:08:00 by sbudilko          #+#    #+#             */
/*   Updated: 2018/03/27 14:08:01 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** -------------------------------------------------------------------------- **
**|  filename - ft_fill_func_arr.c                                           |**
**|                                                                          |**
**|  function(s)                                                             |**
**|         ft_fill_func_arr - fill an array of pointers to a function       |**
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
**| Name            ft_fill_func_arr                                         |**
**|                                                                          |**
**| Description     fills an array of pointers to a function.                |**
**|                 The size of the array is determined by the macro NB_CS   |**
**|                                                                          |**
**| Return value    None.                                                    |**
** -------------------------------------------------------------------------- **
*/

void	ft_fill_func_arr(int (*func_arr[])(int, t_syntax *, va_list *))
{
	func_arr[0] = ft_print_s_conv;
	func_arr[1] = ft_print_ss_conv;
	func_arr[2] = ft_print_p_conv;
	func_arr[3] = ft_print_d_conv;
	func_arr[4] = ft_print_dd_conv;
	func_arr[5] = ft_print_d_conv;
	func_arr[6] = ft_print_o_conv;
	func_arr[7] = ft_print_oo_conv;
	func_arr[8] = ft_print_u_conv;
	func_arr[9] = ft_print_uu_conv;
	func_arr[10] = ft_print_x_conv;
	func_arr[11] = ft_print_xx_conv;
	func_arr[12] = ft_print_c_conv;
	func_arr[13] = ft_print_cc_conv;
}
