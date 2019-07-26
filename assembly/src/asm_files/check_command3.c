/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:50:05 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:53 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	check_command_sti(char *str, t_label *label, char *name)
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
	check_reg(arg_1, name);
	while (*arg_2 == ' ' || *arg_2 == '\t')
		arg_2++;
	check_arg(arg_2, label, name);
	while (*arg_3 == ' ' || *arg_3 == '\t')
		arg_3++;
	check_arg2(arg_3, label, name);
	free_arg(args, i + 1);
}

void	check_command_fork(char *str, t_label *label, char *name)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str != DIRECT_CHAR)
		asm_error("Wrong argument, command ", name);
	str++;
	check_t_dir(&str, label, name);
}

void	check_command_lld(char *str, t_label *label, char *name)
{
	char	**args;
	char	*arg_1;
	char	*arg_2;
	int		i;

	i = count_args(str);
	if (i != 1)
		asm_error("Wrong arguments, command ", name);
	args = ft_strsplit(str, SEPARATOR_CHAR);
	arg_1 = args[0];
	arg_2 = args[1];
	while (*arg_1 == ' ' || *arg_1 == '\t')
		arg_1++;
	if (*arg_1 == DIRECT_CHAR)
	{
		arg_1++;
		check_t_dir(&arg_1, label, name);
	}
	else
		check_t_ind(&arg_1, label, name);
	check_reg(arg_2, name);
	free_arg(args, i + 1);
}

void	check_command_lldi(char *str, t_label *label, char *name)
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

void	check_command_lfork(char *str, t_label *label, char *name)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str != DIRECT_CHAR)
		asm_error("Wrong argument, command ", name);
	str++;
	check_t_dir(&str, label, name);
}
