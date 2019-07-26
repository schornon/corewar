/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_14.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:11:07 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 12:11:09 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	onovi_kol(t_maye *qwer, char boets, int poch, size_t n)
{
	size_t	o;
	int		jjjj;
	int		star_kol;

	star_kol = boets + 1;
	o = 0;
	while (o < n)
	{
		jjjj = zrobi_tse(poch);
		qwer->graf.karta_kol[jjjj] = star_kol;
		qwer->graf.kart_yark[jjjj] = qwer->cikle;
		poch++;
		o++;
	}
}

void	hz_sho_rob(t_maye *qwer, int bu)
{
	if (bu == 's')
		qwer->graf.shvidkist -= 100;
	else if (bu == 'q')
		qwer->graf.shvidkist -= 10;
	else if (bu == 'w')
		qwer->graf.shvidkist -= 1;
	else if (bu == 'e')
		qwer->graf.shvidkist += 1;
	else if (bu == 'r')
		qwer->graf.shvidkist += 10;
	else if (bu == 'd')
		qwer->graf.shvidkist += 100;
	if (qwer->graf.shvidkist < 1)
		qwer->graf.shvidkist = 1;
	if (qwer->graf.shvidkist > 1000)
		qwer->graf.shvidkist = 1000;
}

void	dai_shvidk(t_maye *qwer)
{
	int bu;

	while ((bu = getch()) != ' ')
	{
		qwer->graf.zupinka = 1;
		graf_shw_dan(qwer);
		hz_sho_rob(qwer, bu);
		if (bu == 'o')
		{
			IHOHO_GETTT = 1;
			break ;
		}
		graf_shw_dan(qwer);
	}
	qwer->graf.zupinka = !qwer->graf.zupinka;
	graf_shw_dan(qwer);
}

void	hz_shto_to(t_maye *qwer)
{
	int bu;

	while ((bu = getch()) != 'o')
		if (bu == ' ')
		{
			IHOHO_GETTT = 0;
			graf_shw_dan(qwer);
			break ;
		}
}

WINDOW	*do_nove_vikn(int visot, int shir, int poch_y, int poch_x)
{
	WINDOW *local_win;

	local_win = newwin(visot, shir, poch_y, poch_x);
	refresh();
	wattron(local_win, COLOR_PAIR(42) | A_DIM);
	box(local_win, MEZA_V, MEZA_H);
	wattroff(local_win, COLOR_PAIR(42) | A_DIM);
	wrefresh(local_win);
	return (local_win);
}
