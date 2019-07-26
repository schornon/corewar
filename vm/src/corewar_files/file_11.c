/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_11.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:10:43 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 12:10:47 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			read_vh_ar(t_maye *qwer, t_prroses *tiagn)
{
	int		num_o_a;
	int		k;
	int		dah;
	char	hzsho;

	dah = g_op_tab[tiagn->opsia.c_of_op].hzsho ? 1 : 0;
	if (!g_op_tab[tiagn->opsia.c_of_op].hzsho)
		chit_priam_znach(qwer, &dah, tiagn);
	else
	{
		num_o_a = g_op_tab[tiagn->opsia.c_of_op].num_o_a;
		hzsho = qwer->scene[(tiagn->qw + dah) % SIZE_MEM];
		while (num_o_a--)
		{
			k = (hzsho & 0b11000000) >> 6;
			if (k == C_REG)
				chitai_reg(qwer, &dah, tiagn);
			else if (k == C_DIR)
				chit_priam_znach(qwer, &dah, tiagn);
			else if (k == C_IND)
				chit_krivi_dani(qwer, &dah, tiagn);
			hzsho = hzsho << 2;
		}
	}
	tiagn->dah = dah + 1;
}

void			chit_vse(t_maye *qwer, char *lll, size_t *num_a)
{
	if (!lll)
		pomilka("demp value wasn`t specified", NULL);
	if (!ft_is_number(lll))
		pomilka("demp value should be non-negative number", NULL);
	qwer->vhidni_dani.val_demp = ft_atoi(lll);
	if (qwer->vhidni_dani.val_demp < 0)
		pomilka("demp value should be non-negative number", NULL);
	qwer->vhidni_dani.demp = 1;
	(*num_a)++;
}

void			perev_sho_ti_o(t_maye *qwer, int kilkist)
{
	size_t	o;

	o = 0;
	while (o < MAX_PLAYERS && qwer->vhidni_dani.inf_igrok[o].vikor)
	{
		if (qwer->vhidni_dani.inf_igrok[o].p_signat == kilkist)
			pomilka("player with the same number is already exist", NULL);
		o++;
	}
}

void			zberi_infu(t_maye *qwer, char **p_args, size_t *num_a)
{
	size_t	o;
	int		kilkist;

	if (!p_args[0] || !p_args[1])
		pomilka("some parameter is missing", NULL);
	if (!ft_is_number(p_args[0]))
		pomilka("player number should be numeric", NULL);
	o = 0;
	while (qwer->vhidni_dani.inf_igrok[o].vikor)
		o++;
	qwer->vhidni_dani.inf_igrok[o].doroga_f = p_args[1];
	kilkist = ft_atoi(p_args[0]);
	perev_sho_ti_o(qwer, kilkist);
	qwer->vhidni_dani.inf_igrok[o].p_signat = kilkist;
	qwer->vhidni_dani.inf_igrok[o].vikor = 1;
	*num_a += 2;
}

void			porah_infu(t_maye *qwer, char *doroga_f)
{
	size_t	o;
	int		kilkist;

	o = 0;
	while (qwer->vhidni_dani.inf_igrok[o].vikor)
		o++;
	qwer->vhidni_dani.inf_igrok[o].doroga_f = doroga_f;
	if (o == 0)
		kilkist = 1;
	else
		kilkist = qwer->vhidni_dani.inf_igrok[o - 1].p_signat + 1;
	perev_sho_ti_o(qwer, kilkist);
	qwer->vhidni_dani.inf_igrok[o].p_signat = kilkist;
	qwer->vhidni_dani.inf_igrok[o].vikor = 1;
}
