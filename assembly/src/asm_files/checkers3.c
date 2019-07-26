/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:52:23 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:45 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	add_label_arg(t_label *label, char **str)
{
	t_label		*l;
	char		*str2;

	(*str)++;
	str2 = *str;
	while (ft_strchr(LABEL_CHARS, *str2) != NULL)
		str2++;
	if (*str2 != COMMENT_CHAR && *str2 != ALT_COMMENT_CHAR
		&& *str2 != ' ' && *str2 != '\t'
			&& *str2 != '\0')
		asm_error("Wrong argument", "");
	l = label;
	while (l->next != NULL)
		l = l->next;
	l->next = (t_label *)malloc(sizeof(t_label));
	l->next->flag = 0;
	l->next->next = NULL;
	l->next->content = ft_strnew(str2 - (*str) + 1);
	ft_strncpy(l->next->content, (*str), str2 - (*str));
	(*str) = str2;
}

void	is_comment(char *s, char *name)
{
	char	*str;

	str = s;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str != COMMENT_CHAR && *str != ALT_COMMENT_CHAR
		&& *str != '\0')
		asm_error("Wrong command ", name);
}

int		count_args(char *s)
{
	char	*str;
	int		i;

	str = s;
	i = 0;
	while (*str != '\0' && *str != COMMENT_CHAR && *str != ALT_COMMENT_CHAR)
	{
		if (*str == SEPARATOR_CHAR)
		{
			i++;
			str++;
			if (*str == '\0' || *str == SEPARATOR_CHAR)
				return (-1);
			str--;
		}
		str++;
	}
	return (i);
}

void	check_arg(char *str, t_label *label, char *name)
{
	if (str[0] == 'r')
		check_reg(str, name);
	else if (str[0] == DIRECT_CHAR)
	{
		str++;
		check_t_dir(&str, label, name);
	}
	else
		check_t_ind(&str, label, name);
}

void	check_arg2(char *str, t_label *label, char *name)
{
	if (str[0] == 'r')
		check_reg(str, name);
	else if (str[0] == DIRECT_CHAR)
	{
		str++;
		check_t_dir(&str, label, name);
	}
	else
		asm_error("Wrong arguments, command ", name);
}
