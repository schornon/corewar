/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:09:03 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:18 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	init_header(t_s *s)
{
	write_data_rev(s->fd_out, &s->header->magic, 4);
	write_data(s->fd_out, s->header->prog_name, PROG_NAME_LENGTH);
	s->r = 0;
	write_data(s->fd_out, &s->r, 4);
	count_ex_code_size(s);
	write_data_rev(s->fd_out, &s->t->size, 4);
	write_data(s->fd_out, s->header->comment, COMMENT_LENGTH);
	write_data(s->fd_out, &s->r, 4);
}

void	init_exec_code(t_s *s)
{
	t_tok *tok;

	tok = s->t->next;
	while (tok)
	{
		if (tok->code != -1 || tok->size != 0)
		{
			write_data_rev(s->fd_out, &tok->code, tok->size);
			if (tok->arg_code != -1)
				write_data_rev(s->fd_out, &tok->arg_code, 1);
		}
		tok = tok->next;
	}
}

void	translator(t_s *s)
{
	init_out_fd(s);
	data_to_header(s);
	init_header(s);
	init_exec_code(s);
	ft_printf("Writing output program to %s\n", s->fd_out_name);
	close(s->fd_out);
	close(s->fd);
}
