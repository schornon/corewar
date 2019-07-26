/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:48:09 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:30 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

int		get_fd(int ac, char **av)
{
	int		fd;
	int		len;
	char	b;
	int		f_fd;

	if (ac != 2 && ac != 3)
		asm_error("Usage: ./asm [-ct] <sourcefile.s>\n",
		"	-c: Printing each instruction to hex\n	-t: Printing tokens\n");
	if (ac == 3 && av[ac - 2][0] != '-')
		asm_error("Usage: ./asm [-ct] <sourcefile.s>\n",
		"	-c: Printing each instruction to hex\n	-t: Printing tokens\n");
	len = ft_strlen(av[ac - 1]);
	if (len < 3 || av[ac - 1][len - 1] != 's' || av[ac - 1][len - 2] != '.')
		asm_error("Wrong file name", "");
	fd = open(av[ac - 1], O_RDONLY);
	f_fd = open(av[ac - 1], O_RDONLY);
	if (fd < 0)
		asm_error("Can`t read file", "");
	if (read(f_fd, &b, 1) <= 0)
		asm_error("Can`t read file", "");
	return (fd);
}

char	*get_fd_name(int ac, char **av)
{
	int i;

	i = ft_strlen(av[ac - 1]) - 2;
	return (ft_strsub(av[ac - 1], 0, i));
}

t_l		*file_to_lists(t_s *s)
{
	t_l		*l;
	t_l		*tmpl;
	t_l		*prevl;
	char	*buff;

	l = (t_l*)malloc(sizeof(t_l));
	l->next = NULL;
	prevl = l;
	while (get_next_line(s->fd, &buff) > 0)
	{
		tmpl = create_lnode(buff);
		prevl->next = tmpl;
		prevl = prevl->next;
		ft_strdel(&buff);
	}
	tmpl = l;
	l = l->next;
	free(tmpl);
	return (l);
}
