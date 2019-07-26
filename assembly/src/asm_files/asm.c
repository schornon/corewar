/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 16:48:55 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 17:28:16 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

void	my_exit(int ec)
{
	if (ec == 0)
		ft_printf("Error.\n");
	else if (ec == -1)
		ft_printf("Error. '%s' len > 128.\n", NAME_CMD_STRING);
	else if (ec == -2)
		ft_printf("Error. '%s' len > 2048.\n", COMMENT_CMD_STRING);
	else if (ec == -3)
		ft_printf("Error. Not valid char in one of labels.\n");
	exit(0);
}

int		main(int ac, char **av)
{
	t_s		*s;
	t_pair	pair;

	s = create_struct(ac, av);
	validation(&pair, s);
	tokenization(s);
	encode_tokens(s);
	translator(s);
	bonus(s);
	return (0);
}
