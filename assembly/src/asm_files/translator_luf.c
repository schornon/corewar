/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator_luf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:14:43 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:16 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	write_data(int fd, void *data, int size)
{
	write(fd, data, size);
}

void	write_data_rev(int fd, void *data, int size)
{
	while (--size >= 0)
		write(fd, &data[size], 1);
}

void	data_to_header(t_s *s)
{
	t_tok *tmp;

	s->header->magic = COREWAR_EXEC_MAGIC;
	s->header->prog_name[0] = '\0';
	tmp = s->t;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->type, NAME_CMD_STRING) == 0)
		{
			ft_strcat(s->header->prog_name, tmp->con);
			break ;
		}
		tmp = tmp->next;
	}
	s->header->comment[0] = '\0';
	tmp = s->t;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->type, COMMENT_CMD_STRING) == 0)
		{
			ft_strcat(s->header->comment, tmp->con);
			break ;
		}
		tmp = tmp->next;
	}
}

int		count_ex_code_size(t_s *s)
{
	t_tok	*tok;
	int		count;

	count = 0;
	tok = s->t;
	while (tok)
	{
		count += tok->size;
		tok->arg_code != -1 ? count++ : 0;
		tok = tok->next;
	}
	s->t->size = count;
	return (count);
}

void	init_out_fd(t_s *s)
{
	char	*fd_out_name;

	fd_out_name = (char*)malloc(ft_strlen(s->fd_name) + 5);
	fd_out_name[0] = '\0';
	ft_strcat(fd_out_name, s->fd_name);
	ft_strcat(fd_out_name, ".cor");
	fd_out_name[ft_strlen(s->fd_name) + 4] = '\0';
	s->fd_out = open(fd_out_name, O_CREAT | O_RDWR | O_TRUNC | O_APPEND,
	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	s->fd_out_name = fd_out_name;
}
