/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:23:01 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:51 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	check_op_code(t_pair *pair)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = pair->str;
	while (*str != ' ' && *str != '\t' && *str != '%' && *str != '\0')
		str++;
	while (i < 16)
	{
		j = ft_strncmp(pair->op_code[i], pair->str, str - pair->str);
		if (j == 0)
			break ;
		i++;
	}
	if (j != 0)
		asm_error("Wrong command!", "");
	pair->str = str;
	pair->func_arr[i](pair->str, pair->labels_arg, pair->op_code[i]);
	pair->status = 1;
}

void	label(t_pair *pair, int j, int i)
{
	t_label		*tmp;

	tmp = pair->labels;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = (t_label *)malloc(sizeof(t_label));
	tmp->next->flag = i;
	tmp->next->status = 0;
	tmp->next->content = ft_strnew(j + 1);
	ft_strncpy(tmp->next->content, pair->str, j);
	tmp->next->next = NULL;
	pair->str += j + 1;
	while (*(pair->str) == ' ' || *(pair->str) == '\t')
		(pair->str)++;
	if (*(pair->str) == COMMENT_CHAR || *(pair->str) == ALT_COMMENT_CHAR
		|| !(*(pair->str)))
		return ;
	check_op_code(pair);
	tmp->next->status = 1;
}

void	check_line(t_pair *pair)
{
	char	*str;

	str = pair->str;
	while (ft_strchr(LABEL_CHARS, *str) != NULL)
		str++;
	if (*str == LABEL_CHAR)
		label(pair, (str - pair->str), 1);
	else if (*str == ' ' || *str == '\t' || *str == DIRECT_CHAR)
		check_op_code(pair);
	else
		asm_error("Lexical error", "");
}

void	check_ins(t_pair *pair)
{
	while (get_next_line(pair->fd, &(pair->str_todel)))
	{
		pair->str = pair->str_todel;
		while (*(pair->str) == ' ' || *(pair->str) == '\t')
			(pair->str)++;
		if (*(pair->str) == COMMENT_CHAR || *(pair->str) == ALT_COMMENT_CHAR
			|| !(*(pair->str)))
		{
			free((pair->str_todel));
			continue ;
		}
		check_line(pair);
		free(pair->str_todel);
	}
}
