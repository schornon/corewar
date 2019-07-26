/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:14:18 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:24 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

char	*ft_strstr_op(t_s *s, t_l *tmp_l)
{
	int		i;
	char	*p;

	p = NULL;
	i = 16;
	while (--i >= 0)
	{
		if ((p = ft_strstr(&tmp_l->line[s->r], s->op_tab[i])) != NULL)
			return (p);
	}
	return (p);
}

int		detect_token_type(t_s *s, t_l *tmp_l)
{
	s->r = s->i;
	while (tmp_l->line[s->r] && ft_strchr(LABEL_CHARS, tmp_l->line[s->r]))
		s->r++;
	if (tmp_l->line[s->r] == LABEL_CHAR && s->r++)
		create_token(s, tmp_l->line, "LABEL");
	else if (s->i > 0)
		s->r = --s->i;
	if (skip_spaces_tabs(s, tmp_l) == 2)
		return (0);
	if (tmp_l->line[s->r] == COMMENT_CHAR ||
		tmp_l->line[s->r] == ALT_COMMENT_CHAR)
		return (0);
	s->r = s->i;
	if (ft_strstr_op(s, tmp_l) != NULL && move_sr(s, tmp_l, 2))
		create_token(s, tmp_l->line, "INSTRUCTION");
	skip_spaces_tabs(s, tmp_l);
	s->r = s->i;
	arguments_tokenizator(s, tmp_l);
	return (0);
}

void	init_token_list(t_s *s, t_l *tmp_l)
{
	s->i = 0;
	skip_spaces_tabs(s, tmp_l);
	while (1)
	{
		if (detect_token_type(s, tmp_l) == 0)
			break ;
	}
}

void	tokenization(t_s *s)
{
	t_l *tmp_l;

	tmp_l = s->l;
	while (tmp_l != NULL)
	{
		tmp_l = init_name_comment_tokens(s, tmp_l);
		if (valid_new_token_list(s, tmp_l) != 0)
			init_token_list(s, tmp_l);
		tmp_l = tmp_l->next;
	}
}
