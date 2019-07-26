/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_name_com.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:55:52 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:21 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

t_l	*init_name_token(t_s *s, t_l *tmp_l, char *str, char *tok_type)
{
	if (tmp_l->line[s->i] == 34)
	{
		s->i++;
		while (tmp_l->next != NULL)
		{
			if (ft_strchr(&tmp_l->line[s->i], 34))
			{
				ft_strcat(str, &tmp_l->line[s->i]);
				break ;
			}
			ft_strcat(str, &tmp_l->line[s->i]);
			ft_strcat(str, "\n");
			s->i = 0;
			tmp_l = tmp_l->next;
		}
		s->i = 0;
		s->r = 0;
		while (str[s->r] != 34)
			s->r++;
		create_token(s, str, tok_type);
	}
	return (tmp_l);
}

t_l	*init_name_comment_tokens(t_s *s, t_l *tmp_l)
{
	char *str;

	if (ft_strstr(tmp_l->line, NAME_CMD_STRING) != NULL)
	{
		str = (char*)malloc(PROG_NAME_LENGTH + 1);
		str[0] = '\0';
		s->i = -1;
		while (tmp_l->line[++s->i])
			if (tmp_l->line[s->i] == 34)
				break ;
		tmp_l = init_name_token(s, tmp_l, str, NAME_CMD_STRING);
		free(str);
	}
	else if (ft_strstr(tmp_l->line, COMMENT_CMD_STRING) != NULL)
	{
		str = (char*)malloc(COMMENT_LENGTH + 1);
		str[0] = '\0';
		s->i = -1;
		while (tmp_l->line[++s->i])
			if (tmp_l->line[s->i] == 34)
				break ;
		tmp_l = init_name_token(s, tmp_l, str, COMMENT_CMD_STRING);
		free(str);
	}
	return (tmp_l);
}
