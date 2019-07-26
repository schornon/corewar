/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:10:46 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:13 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	asm_error(char *message1, char *message2)
{
	ft_putstr(message1);
	ft_putstr(message2);
	ft_putchar('\n');
	exit(-1);
}

int		valid_is_label(char *line)
{
	int i;

	if (ft_strchr(line, LABEL_CHAR) != NULL)
	{
		i = -1;
		while (line[++i] && line[i] != LABEL_CHAR)
		{
			if (ft_strchr(LABEL_CHARS, line[i]) == NULL)
				return (0);
		}
		if (line[i] == LABEL_CHAR)
			return (1);
	}
	return (0);
}

int		valid_new_token_list(t_s *s, t_l *tmp_l)
{
	char	*p;
	int		len;

	p = tmp_l->line;
	if (ft_strchr(p, '"'))
		return (0);
	while (*p == ' ' || *p == '\t')
		p++;
	if (tmp_l != NULL && *p != '\0' &&
		ft_strstr(tmp_l->line, NAME_CMD_STRING) == NULL &&
		ft_strstr(tmp_l->line, COMMENT_CMD_STRING) == NULL &&
		*p != COMMENT_CHAR && *p != ALT_COMMENT_CHAR)
	{
		if (valid_is_label(tmp_l->line) == 1)
			return (1);
		s->i = 16;
		while (--s->i >= 0)
		{
			len = (int)ft_strlen(s->op_tab[s->i]);
			if ((p = ft_strstr(tmp_l->line, s->op_tab[s->i])) != NULL &&
				(int)ft_strlen(p) > len && *(p + len) != SEPARATOR_CHAR)
				return (1);
		}
	}
	return (0);
}
