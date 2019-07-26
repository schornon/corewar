/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:53:44 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 11:53:54 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fun_12(t_maye *qwer, t_prroses *tiagn)
{
	t_list		*odn_vus;
	t_prroses	odn_pr;
	short		odn_pk;

	odn_pr = *tiagn;
	ft_bzero(&odn_pr.opsia, sizeof(t_oper));
	odn_pk = dai_mal_nom(G_VAL(tiagn, 0)) % MOD_IDX;
	odn_pk += tiagn->qw;
	odn_pk = zrobi_tse(odn_pk);
	odn_pr.qw = odn_pk;
	qwer->graf.karta_pk[odn_pk]++;
	da_bude_gra(qwer, &odn_pr);
	odn_vus = ft_lstnew(&odn_pr, sizeof(t_prroses));
	if (!odn_vus)
		pomilka(PECHAL, NULL);
	ft_lstadd(&qwer->diiya, odn_vus);
	qwer->qty_proc = ft_lstlen(qwer->diiya);
}

void	fun_13(t_maye *qwer, t_prroses *tiagn)
{
	char	*chi;
	short	nom_o_r;

	qwer = NULL;
	nom_o_r = NUM_REG(tiagn, 1);
	if (BAD_NUM_REG(nom_o_r))
		return ;
	chi = G_VAL(tiagn, 0);
	ft_memcpy(tiagn->mn_reg[nom_o_r], chi, SIZE_REG);
	CARRY_SET(tiagn, nom_o_r);
}

void	fun_14(t_maye *qwer, t_prroses *tiagn)
{
	char	*pot0;
	char	*pot3;
	short	nom_o_r;
	int		tmmp;

	nom_o_r = NUM_REG(tiagn, 2);
	if (BAD_NUM_REG(nom_o_r))
		return ;
	pot0 = TIP(tiagn, 0) == C_IND ? G_IDX_VAL(tiagn, 0) :
											G_VAL(tiagn, 0);
	pot3 = G_VAL(tiagn, 1);
	tmmp = dai_nomer(pot0, ROZM(tiagn, 0)) +
			dai_nomer(pot3, ROZM(tiagn, 1));
	tmmp = tiagn->qw + tmmp;
	chit_chtoto(qwer, tiagn->mn_reg[nom_o_r], tmmp, SIZE_REG);
	CARRY_SET(tiagn, nom_o_r);
}

void	fun_15(t_maye *qwer, t_prroses *tiagn)
{
	t_list		*odn_vus;
	t_prroses	odn_pr;
	short		qw;

	odn_pr = *tiagn;
	ft_bzero(&odn_pr.opsia, sizeof(t_oper));
	qw = dai_mal_nom(G_VAL(tiagn, 0));
	qw += tiagn->qw;
	qw = zrobi_tse(qw);
	odn_pr.qw = qw;
	qwer->graf.karta_pk[qw]++;
	da_bude_gra(qwer, &odn_pr);
	odn_vus = ft_lstnew(&odn_pr, sizeof(t_prroses));
	if (!odn_vus)
		pomilka(PECHAL, NULL);
	ft_lstadd(&qwer->diiya, odn_vus);
	qwer->qty_proc = ft_lstlen(qwer->diiya);
}

void	fun_16(t_maye *qwer, t_prroses *tiagn)
{
	int		chi;
	short	nom_o_r;

	qwer = NULL;
	nom_o_r = NUM_REG(tiagn, 0);
	if (BAD_NUM_REG(nom_o_r))
		return ;
	chi = dai_sv_nom(G_VAL(tiagn, 0)) % 256;
	ft_printf("Aff: %c\n", chi);
}
