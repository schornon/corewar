/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:49:17 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:56 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	check_command_and(char *str, t_label *label, char *name)
{
	char	**args;
	char	*arg_1;
	char	*arg_2;
	char	*arg_3;
	int		i;

	i = count_args(str);
	if (i != 2)
		asm_error("Wrong arguments, command ", name);
	args = ft_strsplit(str, SEPARATOR_CHAR);
	arg_1 = args[0];
	arg_2 = args[1];
	arg_3 = args[2];
	while (*arg_1 == ' ' || *arg_1 == '\t')
		arg_1++;
	check_arg(arg_1, label, name);
	while (*arg_2 == ' ' || *arg_2 == '\t')
		arg_2++;
	check_arg(arg_2, label, name);
	check_reg(arg_3, name);
	free_arg(args, i + 1);
}

void	check_command_or(char *str, t_label *label, char *name)
{
	char	**args;
	char	*arg_1;
	char	*arg_2;
	char	*arg_3;
	int		i;

	i = count_args(str);
	if (i != 2)
		asm_error("Wrong arguments, command ", name);
	args = ft_strsplit(str, SEPARATOR_CHAR);
	arg_1 = args[0];
	arg_2 = args[1];
	arg_3 = args[2];
	while (*arg_1 == ' ' || *arg_1 == '\t')
		arg_1++;
	check_arg(arg_1, label, name);
	while (*arg_2 == ' ' || *arg_2 == '\t')
		arg_2++;
	check_arg(arg_2, label, name);
	check_reg(arg_3, name);
	free_arg(args, i + 1);
}

void	check_command_xor(char *str, t_label *label, char *name)
{
	char	**args;
	char	*arg_1;
	char	*arg_2;
	char	*arg_3;
	int		i;

	i = count_args(str);
	if (i != 2)
		asm_error("Wrong arguments, command ", name);
	args = ft_strsplit(str, SEPARATOR_CHAR);
	arg_1 = args[0];
	arg_2 = args[1];
	arg_3 = args[2];
	while (*arg_1 == ' ' || *arg_1 == '\t')
		arg_1++;
	check_arg(arg_1, label, name);
	while (*arg_2 == ' ' || *arg_2 == '\t')
		arg_2++;
	check_arg(arg_2, label, name);
	check_reg(arg_3, name);
	free_arg(args, i + 1);
}

void	check_command_zjmp(char *str, t_label *label, char *name)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str != DIRECT_CHAR)
		asm_error("Wrong argument, command ", name);
	str++;
	check_t_dir(&str, label, name);
}

void	check_command_ldi(char *str, t_label *label, char *name)
{
	char	**args;
	char	*arg_1;
	char	*arg_2;
	char	*arg_3;
	int		i;

	i = count_args(str);
	if (i != 2)
		asm_error("Wrong arguments, command ", name);
	args = ft_strsplit(str, SEPARATOR_CHAR);
	arg_1 = args[0];
	arg_2 = args[1];
	arg_3 = args[2];
	while (*arg_1 == ' ' || *arg_1 == '\t')
		arg_1++;
	check_arg(arg_1, label, name);
	while (*arg_2 == ' ' || *arg_2 == '\t')
		arg_2++;
	check_arg2(arg_2, label, name);
	check_reg(arg_3, name);
	free_arg(args, i + 1);
}
