/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:02:35 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 12:02:37 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	vidal_mert_proc(t_maye *qwer)
{
	t_list	*slid;
	t_list	*overtake;

	slid = qwer->diiya;
	overtake = slid;
	while (slid)
	{
		if (G_LIVE(slid))
		{
			overtake = slid;
			slid = slid->next;
			continue;
		}
		qwer->graf.karta_pk[P_C(slid)]--;
		if (slid == qwer->diiya)
		{
			overtake = slid;
			vidaliti_z_poch(&qwer->diiya, &slid);
		}
		else
			vidal_prok(&slid, &overtake);
	}
}

void	ubei_to(t_maye *qwer)
{
	size_t s_ziv;

	s_ziv = porah_zivi(qwer);
	if (s_ziv == qwer->qty_proc)
		return ;
	vidal_mert_proc(qwer);
	if (FLAG_V)
		poka_igrok(qwer->qty_proc - s_ziv);
	qwer->qty_proc = ft_lstlen(qwer->diiya);
}

int		dai_sv_nom(void *mas)
{
	int				kin;
	unsigned char	*s;

	kin = 0;
	s = (unsigned char *)mas;
	kin += s[3];
	kin += s[2] << 8;
	kin += s[1] << 16;
	kin += s[0] << 24;
	return (kin);
}

short	dai_mal_nom(void *mas)
{
	short			kin;
	unsigned char	*s;

	kin = 0;
	s = (unsigned char *)mas;
	kin += s[1];
	kin += s[0] << 8;
	return (kin);
}

int		dai_nomer(void *mas, int rozm)
{
	int kin;

	kin = 0;
	if (rozm == SIZE_REG)
		kin = dai_sv_nom(mas);
	else if (rozm == SIZE_IND)
		kin = dai_mal_nom(mas);
	return (kin);
}
