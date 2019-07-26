/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:52:33 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 11:52:35 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fun_8(t_maye *qwer, t_prroses *tiagn)
{
	int		kin;
	int		j0;
	int		j3;
	short	nom_o_r;

	qwer = NULL;
	if ((TIP(tiagn, 0) == C_REG &&
		BAD_NUM_REG(NUM_REG(tiagn, 0))) ||
		(TIP(tiagn, 1) == C_REG &&
		BAD_NUM_REG(NUM_REG(tiagn, 1))) ||
		BAD_NUM_REG(NUM_REG(tiagn, 2)))
		return ;
	j0 = dai_sv_nom(G_VAL(tiagn, 0));
	j3 = dai_sv_nom(G_VAL(tiagn, 1));
	kin = j0 ^ j3;
	nom_o_r = NUM_REG(tiagn, 2);
	kin = dai_sv_nom(&kin);
	ft_memcpy(tiagn->mn_reg[nom_o_r], &kin, SIZE_REG);
	CARRY_SET(tiagn, nom_o_r);
}

void	fun_9(t_maye *qwer, t_prroses *tiagn)
{
	short ofsad;

	if (!tiagn->cary)
		return ;
	ofsad = dai_mal_nom(G_VAL(tiagn, 0));
	ofsad %= MOD_IDX;
	rah_pk(qwer, tiagn, ofsad);
}

void	fun_10(t_maye *qwer, t_prroses *tiagn)
{
	char		*pot0;
	char		*pot3;
	short		nom_o_r;
	int			tmmp;

	nom_o_r = NUM_REG(tiagn, 2);
	if (BAD_NUM_REG(nom_o_r))
		return ;
	pot0 = TIP(tiagn, 0) == C_IND ? G_IDX_VAL(tiagn, 0) :
											G_VAL(tiagn, 0);
	pot3 = G_VAL(tiagn, 1);
	tmmp = dai_nomer(pot0, ROZM(tiagn, 0)) +
			dai_nomer(pot3, ROZM(tiagn, 1));
	tmmp %= MOD_IDX;
	tmmp = tiagn->qw + tmmp;
	chit_chtoto(qwer, tiagn->mn_reg[nom_o_r], tmmp, SIZE_REG);
}

void	fun_11(t_maye *qwer, t_prroses *tiagn)
{
	char		*pot0;
	char		*pot3;
	char		*pot5;
	int			tmmp;

	if (BAD_NUM_REG(NUM_REG(tiagn, 0)))
		return ;
	pot0 = G_VAL(tiagn, 0);
	pot3 = TIP(tiagn, 0) == C_IND ? G_IDX_VAL(tiagn, 1) :
											G_VAL(tiagn, 1);
	pot5 = G_VAL(tiagn, 2);
	tmmp = dai_nomer(pot3, ROZM(tiagn, 1)) +
			dai_nomer(pot5, ROZM(tiagn, 2));
	tmmp %= MOD_IDX;
	tmmp = tiagn->qw + tmmp;
	pishi_chtoto(qwer, pot0, tmmp, SIZE_REG);
	if (FLAG_V)
		onovi_kol(qwer, tiagn->boets, tmmp, SIZE_REG);
}

void	da_bude_gra(t_maye *qwer, t_prroses *tiagn)
{
	if (YE_C_OP(qwer->scene[tiagn->qw]))
	{
		tiagn->opsia.c_of_op = qwer->scene[tiagn->qw];
		tiagn->opsia.doloi = g_op_tab[tiagn->opsia.c_of_op].doloi - 1;
	}
}
