/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:44:01 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:59 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	check_command_live(char *str, t_label *label, char *name)
{
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str != DIRECT_CHAR)
		asm_error("Wrong argument, command ", name);
	str++;
	check_t_dir(&str, label, name);
}

void	check_command_ld(char *str, t_label *label, char *name)
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

void	check_command_st(char *str, t_label *label, char *name)
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
	check_reg(arg_1, name);
	while (*arg_2 == ' ' || *arg_2 == '\t')
		arg_2++;
	if (arg_2[0] == 'r')
		check_reg(arg_2, name);
	else
		check_t_ind(&arg_2, label, name);
	free_arg(args, i + 1);
}

void	check_command_add(char *str, t_label *label, char *name)
{
	char	**args;
	char	*arg_1;
	char	*arg_2;
	char	*arg_3;
	int		i;

	label = label->next;
	i = count_args(str);
	if (i != 2)
		asm_error("Wrong arguments, command ", name);
	args = ft_strsplit(str, SEPARATOR_CHAR);
	arg_1 = args[0];
	arg_2 = args[1];
	arg_3 = args[2];
	check_reg(arg_1, name);
	check_reg(arg_2, name);
	check_reg(arg_3, name);
	free_arg(args, i + 1);
}

void	check_command_sub(char *str, t_label *label, char *name)
{
	char	**args;
	char	*arg_1;
	char	*arg_2;
	char	*arg_3;
	int		i;

	label = label->next;
	i = count_args(str);
	if (i != 2)
		asm_error("Wrong arguments, command ", name);
	args = ft_strsplit(str, SEPARATOR_CHAR);
	arg_1 = args[0];
	arg_2 = args[1];
	arg_3 = args[2];
	check_reg(arg_1, name);
	check_reg(arg_2, name);
	check_reg(arg_3, name);
	free_arg(args, i + 1);
}
