/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_tokens_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:08:53 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:37 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

int		from_curr_to_label_up(t_tok *tok)
{
	int		res;
	t_tok	*tmp;

	res = 0;
	tmp = tok;
	while (tmp)
	{
		res += tmp->size;
		tmp = tmp->prev;
		if (tmp && ft_strcmp(tmp->type, "INSTRUCTION") == 0)
		{
			res += tmp->size;
			tmp->arg_code != -1 ? res += 1 : 0;
			res += 1;
			break ;
		}
	}
	return (res);
}

void	encode_arg_down(t_s *s, t_tok *tok, int k, t_tok *tmp)
{
	tok->code += from_curr_to_label_up(tok);
	tmp = tok->next;
	while (s && tmp && k && tmp->num <= tok->dir_lbl->num)
	{
		tok->code += tmp->size;
		tmp->arg_code != -1 ? tok->code += 1 : 0;
		tmp = tmp->next;
	}
}

void	encode_arg_up(t_s *s, t_tok *tok, int k, t_tok *tmp)
{
	tmp = tok;
	while (tmp && ft_strcmp(tmp->type, "INSTRUCTION") != 0)
		tmp = tmp->prev;
	tmp = tmp->prev;
	while (s && tmp && k && tmp->num >= tok->dir_lbl->num)
	{
		tok->code += tmp->size;
		tmp->arg_code != -1 ? tok->code += 1 : 0;
		tmp = tmp->prev;
	}
	tok->code += 1;
	tok->code = ~tok->code + 1;
}

void	encode_arg_in_dir_label(t_s *s, t_tok *tok, int k)
{
	t_tok *tmp;

	tmp = NULL;
	if (tok->num < tok->dir_lbl->num)
		encode_arg_down(s, tok, k, tmp);
	else if (tok->num > tok->dir_lbl->num)
		encode_arg_up(s, tok, k, tmp);
}
