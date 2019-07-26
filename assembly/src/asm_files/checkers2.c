/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 12:17:06 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:48 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	check_t_dir(char **str, t_label *label, char *name)
{
	if (**str == LABEL_CHAR)
		add_label_arg(label, str);
	else if (ft_isdigit(**str) || **str == '-')
	{
		if (**str == '-')
			(*str)++;
		while (ft_isdigit(**str))
			(*str)++;
	}
	else
		asm_error("Wrong argument, command ", name);
	while (**str == ' ' || **str == '\t')
		(*str)++;
	if (**str != COMMENT_CHAR && **str != ALT_COMMENT_CHAR
		&& **str != '\0')
		asm_error("Wrong command ", name);
}

void	check_reg(char *str, char *name)
{
	int	reg;

	reg = -1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str != 'r')
		asm_error("Wrong argument, command ", name);
	str++;
	if (ft_isdigit(*str))
	{
		reg = ((*str) - '0');
		str++;
	}
	if (ft_isdigit(*str))
	{
		reg = reg * 10 + ((*str) - '0');
		str++;
	}
	if (reg > REG_NUMBER || reg < 1)
		asm_error("Wrong registry, command ", name);
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str != COMMENT_CHAR && *str != ALT_COMMENT_CHAR && *str != '\0')
		asm_error("Wrong command ", name);
}

void	check_t_ind(char **str, t_label *label, char *name)
{
	if (**str == LABEL_CHAR)
		add_label_arg(label, str);
	else if (ft_isdigit(**str) || **str == '-')
	{
		if (**str == '-')
			(*str)++;
		while (ft_isdigit(**str))
			(*str)++;
	}
	else
		asm_error("Wrong argument, command ", name);
	while (**str == ' ' || **str == '\t')
		(*str)++;
	if (**str != COMMENT_CHAR && **str != ALT_COMMENT_CHAR
		&& **str != '\0')
		asm_error("Wrong command ", name);
}

void	check_command_aff(char *str, t_label *label, char *name)
{
	t_label	*l;

	l = label;
	check_reg(str, name);
}
