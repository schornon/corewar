/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:02:30 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 12:02:32 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	stav_grav(t_maye *qwer)
{
	size_t	o;

	o = 0;
	while (o < qwer->qty_igrok)
	{
		chit_perem(&(qwer->igroks[o]), DOROGA_DO_FILE(o));
		perev_perem(&(qwer->igroks[o]), DOROGA_DO_FILE(o));
		qwer->igroks[o].kilkist = o + 1;
		qwer->igroks[o].p_signat = SIGN_GETTER(o);
		o++;
	}
}

void	stav_prok(t_maye *qwer)
{
	size_t		o;
	t_prroses	tiagn;
	t_list		*odn_vus;
	int			p_signat;

	qwer->qty_proc = qwer->qty_igrok;
	odn_vus = NULL;
	o = 0;
	while (o < qwer->qty_proc)
	{
		ft_bzero(&tiagn, sizeof(t_prroses));
		tiagn.boets = o;
		tiagn.qw = SIZE_MEM / qwer->qty_igrok * o;
		p_signat = dai_sv_nom(&SIGN_GETTER(o));
		ft_memcpy(&tiagn.mn_reg[1], &p_signat, SIZE_REG);
		odn_vus = ft_lstnew(&tiagn, sizeof(t_prroses));
		ft_lstadd(&qwer->diiya, odn_vus);
		qwer->graf.karta_pk[tiagn.qw]++;
		o++;
	}
}

size_t	porah_zivi(t_maye *qwer)
{
	size_t s_ziv;
	t_list *slid;

	s_ziv = 0;
	slid = qwer->diiya;
	while (slid)
	{
		if (G_LIVE(slid))
			s_ziv++;
		slid = slid->next;
	}
	return (s_ziv);
}

void	vidaliti_z_poch(t_list **head, t_list **slid)
{
	*head = (*head)->next;
	ft_memdel(&((*slid)->content));
	free(*slid);
	*slid = *head;
}

void	vidal_prok(t_list **slid, t_list **overtake)
{
	(*overtake)->next = (*slid)->next;
	ft_memdel(&((*slid)->content));
	free(*slid);
	*slid = (*overtake)->next;
}
