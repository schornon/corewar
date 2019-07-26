/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:52:28 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 11:52:30 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	fun_3(t_maye *qwer, t_prroses *tiagn)
{
	char	*chi;
	int		tmmp;
	short	nom_o_r;

	nom_o_r = NUM_REG(tiagn, 0);
	if (BAD_NUM_REG(nom_o_r))
		return ;
	chi = tiagn->mn_reg[nom_o_r];
	if (TIP(tiagn, 1) == C_IND)
	{
		tmmp = tiagn->qw + (G_OFF(tiagn, 1) % MOD_IDX);
		pishi_chtoto(qwer, chi, tmmp, SIZE_REG);
		if (FLAG_V)
			onovi_kol(qwer, tiagn->boets, tmmp, SIZE_REG);
	}
	else if (TIP(tiagn, 1) == C_REG)
	{
		nom_o_r = NUM_REG(tiagn, 1);
		if (BAD_NUM_REG(nom_o_r))
			return ;
		ft_memcpy(tiagn->mn_reg[nom_o_r], chi, SIZE_REG);
	}
}

void	fun_4(t_maye *qwer, t_prroses *tiagn)
{
	int		kin;
	int		j0;
	int		j3;
	short	nom_o_r;

	qwer = NULL;
	if (BAD_NUM_REG(NUM_REG(tiagn, 0)) ||
		BAD_NUM_REG(NUM_REG(tiagn, 1)) ||
		BAD_NUM_REG(NUM_REG(tiagn, 2)))
		return ;
	j0 = dai_sv_nom(G_VAL(tiagn, 0));
	j3 = dai_sv_nom(G_VAL(tiagn, 1));
	kin = j0 + j3;
	nom_o_r = NUM_REG(tiagn, 2);
	kin = dai_sv_nom(&kin);
	ft_memcpy(tiagn->mn_reg[nom_o_r], &kin, SIZE_REG);
	CARRY_SET(tiagn, nom_o_r);
}

void	fun_5(t_maye *qwer, t_prroses *tiagn)
{
	int		kin;
	int		j0;
	int		j3;
	short	nom_o_r;

	qwer = NULL;
	if (BAD_NUM_REG(NUM_REG(tiagn, 0)) ||
		BAD_NUM_REG(NUM_REG(tiagn, 1)) ||
		BAD_NUM_REG(NUM_REG(tiagn, 2)))
		return ;
	j0 = dai_sv_nom(G_VAL(tiagn, 0));
	j3 = dai_sv_nom(G_VAL(tiagn, 1));
	kin = j0 - j3;
	nom_o_r = NUM_REG(tiagn, 2);
	kin = dai_sv_nom(&kin);
	ft_memcpy(tiagn->mn_reg[nom_o_r], &kin, SIZE_REG);
	CARRY_SET(tiagn, nom_o_r);
}

void	fun_6(t_maye *qwer, t_prroses *tiagn)
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
	kin = j0 & j3;
	nom_o_r = NUM_REG(tiagn, 2);
	kin = dai_sv_nom(&kin);
	ft_memcpy(tiagn->mn_reg[nom_o_r], &kin, SIZE_REG);
	CARRY_SET(tiagn, nom_o_r);
}

void	fun_7(t_maye *qwer, t_prroses *tiagn)
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
	kin = j0 | j3;
	nom_o_r = NUM_REG(tiagn, 2);
	kin = dai_sv_nom(&kin);
	ft_memcpy(tiagn->mn_reg[nom_o_r], &kin, SIZE_REG);
	CARRY_SET(tiagn, nom_o_r);
}
