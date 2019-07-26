/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:13:53 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:43 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	encode_instruction_code(t_s *s, t_tok *tok)
{
	int i;

	i = 16;
	while (--i >= 0)
	{
		if (ft_strcmp(tok->con, s->op_tab[i]) == 0)
		{
			tok->code = i + 1;
			break ;
		}
	}
	s->header->prog_size += 1;
}

int		find_tdir_size(t_s *s, t_tok *tok_i)
{
	int i;

	i = 16;
	while (--i >= 0)
	{
		if (ft_strcmp(tok_i->con, s->op_tab[i]) == 0)
			return (s->op_tdir[i]);
	}
	return (0);
}

void	encode_instruction_arg_type(t_s *s, t_tok *tok, t_tok *tok_i)
{
	char *binstr;

	binstr = ft_strnew(8);
	tok = tok->next;
	while (tok && ft_strcmp(tok->type, "INSTRUCTION") != 0)
	{
		if (ft_strcmp(tok->type, "REGISTER") == 0 && (tok->size = 1))
			ft_strcat(binstr, "01");
		if (ft_strnstr(tok->type, "DIRECT", 6) != NULL)
		{
			tok->size = find_tdir_size(s, tok_i);
			ft_strcat(binstr, "10");
		}
		if (ft_strstr(tok->type, "INDIRECT") != NULL && (tok->size = 2))
			ft_strcat(binstr, "11");
		tok = tok->next;
	}
	if ((s->r = ft_strlen(binstr)) > 2)
	{
		s->r > 4 ? ft_strcat(binstr, "00") : ft_strcat(binstr, "0000");
		tok_i->arg_code = binstr_to_int(binstr);
		s->header->prog_size += 1;
	}
	free(binstr);
}

t_tok	*encode_instruction(t_s *s, t_tok *tok)
{
	t_tok *tok_i;

	encode_instruction_code(s, tok);
	tok_i = tok;
	encode_instruction_arg_type(s, tok, tok_i);
	if (ft_strcmp(tok_i->con, "aff") == 0)
		tok_i->arg_code = 64;
	tok_i->size = 1;
	return (tok);
}

void	encode_tokens(t_s *s)
{
	t_tok *tok;

	tok = s->t;
	while (tok != NULL)
	{
		if (ft_strcmp(tok->type, "INSTRUCTION") == 0)
			tok = encode_instruction(s, tok);
		if (tok != NULL)
			tok = tok->next;
	}
	encode_tokens_2(s);
}
