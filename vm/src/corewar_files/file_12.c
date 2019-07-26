/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_12.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:10:56 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/19 12:06:48 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_vhidni_d(t_maye *qwer, char **argv)
{
	size_t	o;

	o = 0;
	qwer->qty_igrok = 0;
	while (argv[o])
	{
		if (ft_strequ(argv[o], "--V"))
		{
			qwer->vhidni_dani.v = 1;
			o++;
		}
		else if (ft_strequ(argv[o], "--dump"))
			chit_vse(qwer, argv[++o], &o);
		else
		{
			if (qwer->qty_igrok == MAX_PLAYERS)
				pomilka("limit of players is exceeded", NULL);
			if (ft_strequ(argv[o], "-n"))
				zberi_infu(qwer, &(argv[++o]), &o);
			else
				porah_infu(qwer, argv[o++]);
			qwer->qty_igrok++;
		}
	}
}

void	rah_pk(t_maye *qwer, t_prroses *tiagn, int krok)
{
	qwer->graf.karta_pk[tiagn->qw]--;
	tiagn->qw = zrobi_tse(tiagn->qw + krok);
	qwer->graf.karta_pk[tiagn->qw]++;
	if (FLAG_V)
		graff_scene(qwer);
}

void	yakis_instr(t_maye *qwer, t_list *slid)
{
	t_prroses *test;

	test = slid->content;
	read_vh_ar(qwer, slid->content);
	g_op_tab[C_OF_OP(slid)].diy(qwer, slid->content);
	if (C_OF_OP(slid) != 9 || !CARY(slid))
		rah_pk(qwer, slid->content, G_PADD(slid));
	if (FLAG_V)
		graff_scene(qwer);
	if (FLAG_V && C_OF_OP(slid) == 1)
		graf_shoto_to(qwer);
	ft_bzero(&G_OPER(slid), sizeof(t_oper));
}

void	rahui_shto_del(t_maye *qwer)
{
	t_list	*slid;

	slid = qwer->diiya;
	while (slid)
	{
		if (!C_OF_OP(slid) && !YE_C_OP(VAL_PC(slid)))
			rah_pk(qwer, slid->content, 1);
		if (C_OF_OP(slid) && DO_DEL(slid) == 0)
			yakis_instr(qwer, slid);
		if (!C_OF_OP(slid) && YE_C_OP(VAL_PC(slid)))
		{
			C_OF_OP(slid) = VAL_PC(slid);
			DO_DEL(slid) = g_op_tab[C_OF_OP(slid)].doloi;
		}
		if (DO_DEL(slid))
			DO_DEL(slid)--;
		slid = slid->next;
	}
}

void	zber_cikl(t_maye *qwer)
{
	qwer->rahunok = 0;
	if (qwer->vsogo_ziv >= LIVE_NUM)
	{
		qwer->sk_cikl_pom -= DELTA_CYCLE;
		qwer->chi_zives = CHECKS_MAX;
	}
	else
		qwer->chi_zives--;
	if (!qwer->chi_zives)
	{
		qwer->sk_cikl_pom -= DELTA_CYCLE;
		qwer->chi_zives = CHECKS_MAX;
	}
}
