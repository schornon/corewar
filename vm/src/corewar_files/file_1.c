/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:52:20 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 11:52:22 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_lstlen(t_list *beg)
{
	t_list		*tmp;
	int			i;

	i = 0;
	if (beg == NULL)
		return (0);
	tmp = beg;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int		ft_is_number(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		chiy_nomer(t_maye *qwer, int chi)
{
	size_t	o;

	o = 0;
	while (o < qwer->qty_igrok)
	{
		if (qwer->igroks[o].p_signat == chi)
			return (o);
		o++;
	}
	return (-42);
}

void	zive(t_maye *qwer, t_prroses *tiagn)
{
	int			chi;
	int			tmp;

	chi = dai_sv_nom(G_VAL(tiagn, 0));
	tochno_mozesh();
	if ((tmp = chiy_nomer(qwer, chi)) != -42)
	{
		qwer->igroks[tmp].zive++;
		qwer->igroks[tmp].zive_ostan = qwer->cikle;
		if (FLAG_V)
		{
			qwer->graf.mihno_pomer[tiagn->qw] = tmp + 11;
			qwer->graf.kart_yark[tiagn->qw] = qwer->cikle;
		}
	}
	tiagn->zive++;
	qwer->vsogo_ziv++;
}

void	fun_2(t_maye *qwer, t_prroses *tiagn)
{
	char	*chi;
	short	nom_o_r;

	qwer = NULL;
	nom_o_r = NUM_REG(tiagn, 1);
	if (BAD_NUM_REG(nom_o_r))
		return ;
	if (TIP(tiagn, 0) == C_DIR)
		chi = G_VAL(tiagn, 0);
	else if (TIP(tiagn, 0) == C_IND)
		chi = G_IDX_VAL(tiagn, 0);
	else
		return ;
	ft_memcpy(tiagn->mn_reg[nom_o_r], chi, SIZE_REG);
	CARRY_SET(tiagn, nom_o_r);
}
