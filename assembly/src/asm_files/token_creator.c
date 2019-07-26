/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:10:29 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:27 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	create_token(t_s *s, char *line, char *tok_type)
{
	t_tok *tmp_t;
	t_tok *new_tok;

	tmp_t = s->t;
	while (tmp_t->next != NULL)
		tmp_t = tmp_t->next;
	new_tok = (t_tok*)malloc(sizeof(t_tok));
	new_tok->con = ft_strsub(line, s->i, s->r - s->i);
	new_tok->type = ft_strdup(tok_type);
	new_tok->num = tmp_t->num + 1;
	tmp_t->next = new_tok;
	new_tok->prev = tmp_t;
	new_tok->code = -1;
	new_tok->arg_code = -1;
	new_tok->size = 0;
	new_tok->next = NULL;
	new_tok->dir_lbl = NULL;
	s->i = s->r;
}

int		move_sr(t_s *s, t_l *tmp_l, int k)
{
	if (tmp_l->line[s->r] == DIRECT_CHAR)
		s->r++;
	while (tmp_l->line[s->r] &&
		tmp_l->line[s->r] != ' ' &&
		tmp_l->line[s->r] != '\t' &&
		tmp_l->line[s->r] != SEPARATOR_CHAR &&
		tmp_l->line[s->r] != DIRECT_CHAR)
		s->r++;
	k == 3 ? s->r++ : 0;
	return (1);
}

void	create_in_direct_label_tok(t_s *s, t_l *tmp_l, int k)
{
	if (k == 1)
	{
		if (tmp_l->line[s->i + 1] == LABEL_CHAR)
			create_token(s, tmp_l->line, "DIRECT_LABEL");
		else
			create_token(s, tmp_l->line, "DIRECT");
	}
	if (k == 2)
	{
		if (tmp_l->line[s->i] == LABEL_CHAR && tmp_l->line[s->i + 1] != '\0')
			create_token(s, tmp_l->line, "INDIRECT_LABEL");
		else if (tmp_l->line[s->i] != LABEL_CHAR)
			create_token(s, tmp_l->line, "INDIRECT");
	}
}

void	arguments_tokenizator(t_s *s, t_l *tmp_l)
{
	int		prev_r;
	char	c;
	int		flag;

	while ((c = tmp_l->line[s->i]))
	{
		flag = s->i;
		prev_r = s->r;
		if (c == 'r' && move_sr(s, tmp_l, 2))
			create_token(s, tmp_l->line, "REGISTER");
		else if (c == DIRECT_CHAR && move_sr(s, tmp_l, 2))
			create_in_direct_label_tok(s, tmp_l, 1);
		else if ((ft_isdigit(c) || tmp_l->line[s->i] == LABEL_CHAR ||
			tmp_l->line[s->i] == '-') && move_sr(s, tmp_l, 2))
			create_in_direct_label_tok(s, tmp_l, 2);
		if (tmp_l->line[s->r] == SEPARATOR_CHAR && move_sr(s, tmp_l, 3))
			create_token(s, tmp_l->line, "SEPARATOR");
		skip_spaces_tabs(s, tmp_l);
		if (flag == s->i)
			break ;
	}
}
