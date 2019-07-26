/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_tokens_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:12:38 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:39 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

int		binstr_to_int(char *binstr)
{
	int i;
	int j;
	int res;

	res = 0;
	j = 0;
	i = 7;
	while (i >= 0)
	{
		res += (ft_pow(2, j)) * (binstr[i] - '0');
		j++;
		i--;
	}
	return (res);
}

void	connect_in_dir_whith_label(t_s *s, char *tok_type, int k)
{
	t_tok *tok;
	t_tok *tmp;

	tok = s->t;
	while (tok)
	{
		if (ft_strcmp(tok->type, tok_type) == 0)
		{
			tmp = s->t;
			while (tmp)
			{
				if (ft_strcmp(tmp->type, "LABEL") == 0)
					if (ft_strncmp(&tok->con[k], tmp->con,
						ft_strlen(&tok->con[k])) == 0 &&
					tmp->con[ft_strlen(&tok->con[k])] == LABEL_CHAR)
					{
						tok->dir_lbl = tmp;
						break ;
					}
				tmp = tmp->next;
			}
		}
		tok = tok->next;
	}
}

void	encode_arg(t_s *s, t_tok *tok)
{
	if (ft_strcmp(tok->type, "REGISTER") == 0)
		tok->code = ft_atoi(&tok->con[1]);
	else if (ft_strcmp(tok->type, "DIRECT_LABEL") == 0)
		encode_arg_in_dir_label(s, tok, 2);
	else if (ft_strcmp(tok->type, "DIRECT") == 0)
		tok->code = ft_atoi(&tok->con[1]);
	else if (ft_strcmp(tok->type, "INDIRECT") == 0)
		tok->code = ft_atoi(tok->con);
	else if (ft_strcmp(tok->type, "INDIRECT_LABEL") == 0)
		encode_arg_in_dir_label(s, tok, 1);
}

t_tok	*encode_instruction_2(t_s *s, t_tok *tok)
{
	t_tok *tok_i;

	tok_i = tok;
	tok = tok->next;
	while (tok && ft_strcmp(tok->type, "INSTRUCTION") != 0)
	{
		encode_arg(s, tok);
		if (tok->next == NULL)
			break ;
		tok = tok->next;
	}
	return (tok);
}

void	encode_tokens_2(t_s *s)
{
	t_tok *tok;

	connect_in_dir_whith_label(s, "DIRECT_LABEL", 2);
	connect_in_dir_whith_label(s, "INDIRECT_LABEL", 1);
	tok = s->t;
	while (tok != NULL)
	{
		if (ft_strcmp(tok->type, "INSTRUCTION") == 0)
			tok = encode_instruction_2(s, tok);
		else if (tok != NULL)
			tok = tok->next;
		if (tok->next == NULL)
			break ;
	}
}
