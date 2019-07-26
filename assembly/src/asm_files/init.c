/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:16:36 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:34 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

t_l		*create_lnode(char *line)
{
	t_l *tmpl;

	tmpl = (t_l*)malloc(sizeof(t_l));
	tmpl->line = ft_strdup(line);
	tmpl->next = NULL;
	return (tmpl);
}

char	**init_operations_tab(void)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*) * 16);
	tab[0] = strdup("live");
	tab[1] = strdup("ld");
	tab[2] = strdup("st");
	tab[3] = strdup("add");
	tab[4] = strdup("sub");
	tab[5] = strdup("and");
	tab[6] = strdup("or");
	tab[7] = strdup("xor");
	tab[8] = strdup("zjmp");
	tab[9] = strdup("ldi");
	tab[10] = strdup("sti");
	tab[11] = strdup("fork");
	tab[12] = strdup("lld");
	tab[13] = strdup("lldi");
	tab[14] = strdup("lfork");
	tab[15] = strdup("aff");
	return (tab);
}

int		*init_operations_tdir_tab(void)
{
	int *tab;

	tab = (int*)malloc(sizeof(int) * 16);
	tab[0] = 4;
	tab[1] = 4;
	tab[2] = 4;
	tab[3] = 4;
	tab[4] = 4;
	tab[5] = 4;
	tab[6] = 4;
	tab[7] = 4;
	tab[8] = 2;
	tab[9] = 2;
	tab[10] = 2;
	tab[11] = 2;
	tab[12] = 4;
	tab[13] = 2;
	tab[14] = 2;
	tab[15] = 4;
	return (tab);
}

t_tok	*init_tokens_head(void)
{
	t_tok *t;

	t = (t_tok*)malloc(sizeof(t_tok));
	t->type = ft_strdup("head");
	t->num = 0;
	t->size = 0;
	t->arg_code = -1;
	t->code = -1;
	t->next = NULL;
	t->prev = NULL;
	t->dir_lbl = NULL;
	return (t);
}

t_s		*create_struct(int ac, char **av)
{
	t_s *new;

	if (!(new = (t_s*)malloc(sizeof(t_s))))
		asm_error("Malloc error", "");
	new->i = 0;
	new->r = 0;
	new->fd = get_fd(ac, av);
	new->fd_name = get_fd_name(ac, av);
	get_flags(ac, av, new);
	new->out = (char*)malloc(CHAMP_MAX_SIZE + 50);
	new->out[0] = '\0';
	new->header = (t_header*)malloc(sizeof(t_header));
	ft_bzero(new->header->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(new->header->comment, COMMENT_LENGTH + 1);
	new->header->prog_size = 0;
	new->l = file_to_lists(new);
	new->op_tab = init_operations_tab();
	new->op_tdir = init_operations_tdir_tab();
	new->t = init_tokens_head();
	return (new);
}
