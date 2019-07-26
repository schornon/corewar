/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:25:29 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:08 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	fill_func_arr(t_pair *pair)
{
	pair->func_arr[0] = check_command_live;
	pair->func_arr[1] = check_command_ld;
	pair->func_arr[2] = check_command_st;
	pair->func_arr[3] = check_command_add;
	pair->func_arr[4] = check_command_sub;
	pair->func_arr[5] = check_command_and;
	pair->func_arr[6] = check_command_or;
	pair->func_arr[7] = check_command_xor;
	pair->func_arr[8] = check_command_zjmp;
	pair->func_arr[9] = check_command_ldi;
	pair->func_arr[10] = check_command_sti;
	pair->func_arr[11] = check_command_fork;
	pair->func_arr[12] = check_command_lld;
	pair->func_arr[13] = check_command_lldi;
	pair->func_arr[14] = check_command_lfork;
	pair->func_arr[15] = check_command_aff;
}

void	init_pair(t_pair *pair, t_s *s)
{
	pair->i = 0;
	pair->j = 0;
	pair->status = 0;
	pair->fd = s->fd;
	pair->labels = (t_label *)malloc(sizeof(t_label));
	pair->labels->content = ft_strdup("dd02c5e6eec4693d9a069");
	pair->labels->next = NULL;
	pair->labels_arg = (t_label *)malloc(sizeof(t_label));
	pair->labels_arg->content = ft_strdup("dd02c5e6eec4693d9a069");
	pair->labels_arg->next = NULL;
	pair->op_code = s->op_tab;
	fill_func_arr(pair);
}

void	check_label(t_pair *pair)
{
	int		flag;
	t_label	*tmp;
	t_label	*tmp_2;

	tmp = pair->labels_arg;
	while (tmp != NULL)
	{
		flag = 0;
		tmp_2 = pair->labels;
		while (tmp_2 != NULL)
		{
			if (ft_strcmp(tmp->content, tmp_2->content) == 0)
				flag = 1;
			tmp_2 = tmp_2->next;
		}
		if (flag == 0)
			asm_error("Label doesn`t exist - ", tmp->content);
		tmp = tmp->next;
	}
}

void	check_last_symbol(t_s *s)
{
	t_l		*l;
	char	*str;
	char	buff[2];

	l = s->l;
	buff[1] = '\0';
	while (l->next != NULL)
		l = l->next;
	str = l->line;
	while (*str == ' ' || *str == '\t')
		str++;
	if (str[0] != COMMENT_CHAR && str[0] != '\0')
	{
		if (lseek(s->fd, -1, SEEK_END) == -1L)
			asm_error("seek error", "");
		if (read(s->fd, buff, 1) == 0)
			asm_error("Read Error", "");
		if (buff[0] != '\n')
		{
			asm_error("Syntax error - unexpected end of input",
			"(Perhaps you forgot to end with a newline ?)");
		}
	}
}

void	validation(t_pair *pair, t_s *s)
{
	init_pair(pair, s);
	if (lseek(s->fd, 0, SEEK_SET) == -1L)
		asm_error("seek error", "");
	validate_name_comment(pair);
	check_ins(pair);
	check_label(pair);
	check_last_symbol(s);
	if (pair->status == 0)
		asm_error("No cammands", "");
}
