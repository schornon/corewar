/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:53:57 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/19 12:03:13 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*chit_chtoto(t_maye *qwer, char *tmmp, int poch, size_t n)
{
	size_t	o;
	int		jjjj;

	o = 0;
	while (o < n)
	{
		jjjj = zrobi_tse(poch);
		tmmp[o] = qwer->scene[jjjj];
		poch++;
		o++;
	}
	return (tmmp);
}

void	pishi_chtoto(t_maye *qwer, char *src, int poch, size_t n)
{
	size_t	o;
	int		jjjj;

	o = 0;
	while (o < n)
	{
		jjjj = zrobi_tse(poch);
		qwer->scene[jjjj] = src[o];
		poch++;
		o++;
	}
}

void	nul_for_ziv(t_maye *qwer)
{
	t_list	*slid;
	size_t	o;

	qwer->vsogo_ziv = 0;
	o = 0;
	while (o < qwer->qty_igrok)
		qwer->igroks[o++].zive = 0;
	slid = qwer->diiya;
	while (slid)
	{
		G_LIVE(slid) = 0;
		slid = slid->next;
	}
}

void	hello_igrok(t_maye *qwer)
{
	size_t o;

	ft_printf("Introducing contestants...\n");
	o = 0;
	while (o < qwer->qty_igrok)
	{
		ft_printf("* Player %o, weighing %u bytes, \"%s\" (\"%s\") !\n",
					qwer->igroks[o].p_signat,
					qwer->igroks[o].rozm_code_exec,
					qwer->igroks[o].imiya,
					qwer->igroks[o].coment);
		o++;
	}
}

size_t	hto_batia(t_maye *qwer)
{
	size_t	o;
	size_t	tmp;

	o = 1;
	tmp = 0;
	while (o < qwer->qty_igrok)
	{
		if (qwer->igroks[o].zive_ostan > qwer->igroks[tmp].zive_ostan)
			tmp = o;
		o++;
	}
	if (FLAG_V)
		return (tmp);
	ft_printf("Contestant %d, \"%s\", has won !\n",
				qwer->igroks[tmp].p_signat,
				qwer->igroks[tmp].imiya);
	ft_printf("The game end on %d cycle\n", qwer->cikle);
	return (0);
}
