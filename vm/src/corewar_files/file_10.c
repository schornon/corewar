/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:02:43 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 12:02:44 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		zrobi_tse(int jjjj)
{
	jjjj = jjjj % SIZE_MEM;
	if (jjjj < 0)
		jjjj += SIZE_MEM;
	return (jjjj);
}

int		vismem_nast_norm(t_prroses *tiagn)
{
	int o;

	o = 0;
	while (USAV(tiagn, o))
		o++;
	return (o);
}

void	chitai_reg(t_maye *qwer, int *dah, t_prroses *tiagn)
{
	int o;
	int nom_o_r;

	if ((o = vismem_nast_norm(tiagn)) > 2)
		return ;
	(*dah)++;
	nom_o_r = qwer->scene[(tiagn->qw + *dah) % SIZE_MEM];
	NUM_REG(tiagn, o) = nom_o_r;
	ROZM(tiagn, o) = SIZE_REG;
	TIP(tiagn, o) = C_REG;
	USAV(tiagn, o) = 1;
	if (BAD_NUM_REG(nom_o_r))
		return ;
	ft_memcpy(G_VAL(tiagn, o), tiagn->mn_reg[nom_o_r], SIZE_REG);
}

void	chit_priam_znach(t_maye *qwer, int *dah,
									t_prroses *tiagn)
{
	int		o;
	int		rozm;
	char	poki[SIZE_DIR];

	if ((o = vismem_nast_norm(tiagn)) > 2)
		return ;
	(*dah)++;
	rozm = g_op_tab[tiagn->opsia.c_of_op].rozm_lab;
	ft_bzero(poki, sizeof(poki));
	chit_chtoto(qwer, poki, tiagn->qw + *dah, rozm);
	if (poki[0] & 0b10000000)
		ft_memset(&G_VAL(tiagn, o), -1, SIZE_DIR);
	ft_memcpy(G_VAL(tiagn, o), poki, rozm);
	ROZM(tiagn, o) = rozm;
	TIP(tiagn, o) = C_DIR	;
	USAV(tiagn, o) = 1;
	(*dah) += rozm - 1;
}

void	chit_krivi_dani(t_maye *qwer, int *dah,
										t_prroses *tiagn)
{
	int		o;
	short	ofsad;
	char	poki[IND_T];

	if ((o = vismem_nast_norm(tiagn)) > 2)
		return ;
	(*dah)++;
	ft_bzero(poki, sizeof(poki));
	chit_chtoto(qwer, poki, tiagn->qw + *dah, SIZE_IND);
	ofsad = dai_mal_nom(poki);
	G_OFF(tiagn, o) = ofsad;
	ft_bzero(poki, sizeof(poki));
	chit_chtoto(qwer, poki, tiagn->qw + ofsad, IND_T);
	ft_memcpy(G_VAL(tiagn, o), poki, IND_T);
	ft_bzero(poki, sizeof(poki));
	chit_chtoto(qwer, poki, tiagn->qw + (ofsad % MOD_IDX), IND_T);
	ft_memcpy(G_IDX_VAL(tiagn, o), poki, IND_T);
	ROZM(tiagn, o) = SIZE_REG;
	TIP(tiagn, o) = C_IND;
	USAV(tiagn, o) = 1;
	(*dah) += SIZE_IND - 1;
}
