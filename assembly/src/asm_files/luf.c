/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   luf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:50:31 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:32 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

int		count_rows(t_s *s)
{
	t_l *tmp;
	int count;

	count = 0;
	tmp = s->l;
	while (tmp != NULL)
	{
		if (tmp->line[0] != '\0')
			count++;
		tmp = tmp->next;
	}
	return (count);
}

int		skip_spaces_tabs(t_s *s, t_l *tmp_l)
{
	int tmp;

	tmp = s->i;
	while (tmp_l->line[s->i] && (tmp_l->line[s->i] == ' ' ||
		tmp_l->line[s->i] == '\t'))
		s->i++;
	if (tmp_l->line[s->i] == COMMENT_CHAR ||
		tmp_l->line[s->i] == ALT_COMMENT_CHAR)
		return (2);
	s->r = s->i;
	if (tmp == s->i)
		return (0);
	return (1);
}

void	get_flags(int ac, char **av, t_s *new)
{
	int i;

	new->flag_c = 0;
	new->flag_pt = 0;
	if (ac == 3 && av[ac - 2][0] == '-')
	{
		i = 0;
		while (av[ac - 2][++i])
		{
			if (av[ac - 2][i] == 'c')
				new->flag_c = 1;
			else if (av[ac - 2][i] == 't')
				new->flag_pt = 1;
			else
				asm_error("Error. Bad flag: ", ft_strsub(av[ac - 2], i, 1));
		}
	}
}

void	tokens_printer(t_s *s)
{
	t_tok *tmp;

	ft_printf("|%16s|%16s|%s|%10s|%4s|%10s|\n",
		"______type______", "____content_____",
		"num", "_tok->code", "size", "_arg_code_");
	tmp = s->t->next;
	while (tmp != NULL)
	{
		ft_printf("|%16s|%16s|%3d|%10x|%4d|%10x|\n",
			tmp->type, tmp->con, tmp->num, tmp->code, tmp->size, tmp->arg_code);
		tmp = tmp->next;
	}
}

void	bonus(t_s *s)
{
	if (s->flag_c == 1)
		tokens_hex_bonus(s);
	if (s->flag_pt == 1)
		tokens_printer(s);
}
