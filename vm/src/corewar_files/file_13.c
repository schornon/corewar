/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_13.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:11:02 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 12:11:04 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		igrai_ty(t_maye *qwer)
{
	if (qwer->sk_cikl_pom <= 0)
		return (0);
	if (DAPNUT && qwer->cikle == VAL_DAMPNUT && !FLAG_V)
		chto_ar(qwer);
	rahui_shto_del(qwer);
	if (qwer->rahunok == qwer->sk_cikl_pom)
	{
		if (!qwer->vsogo_ziv)
			return (0);
		zber_cikl(qwer);
		ubei_to(qwer);
		nul_for_ziv(qwer);
		if (FLAG_V)
			graf_cafe(qwer);
	}
	if (FLAG_V)
		gfaf_kuk_dan(qwer);
	qwer->cikle++;
	qwer->rahunok++;
	return (1);
}

void	graf_koord(WINDOW *a_win)
{
	size_t	o;

	wmove(a_win, Y_PADDAW - 2, X_PADDAW);
	wattron(a_win, COLOR_PAIR(43));
	o = 0;
	while (o < ROZM_RIDK)
		wprintw(a_win, "%02hhi ", o++);
	o = 0;
	wmove(a_win, Y_PADDAW - 1, X_PADDAW - 2);
	while (o++ < ROZM_RIDK * 3 + 1)
		wprintw(a_win, "-");
	o = Y_PADDAW;
	while (o < ROZM_RIDK + 4)
	{
		mvwprintw(a_win, o, X_PADDAW - 6, "%02hhi |", o - 4);
		o++;
	}
	wrefresh(a_win);
	wattroff(a_win, COLOR_PAIR(10));
}

int		postav_atr(t_maye *qwer, size_t o)
{
	int	bu;

	bu = 0;
	if (qwer->graf.mihno_pomer[o] &&
		qwer->cikle - qwer->graf.kart_yark[o] <= 50)
		bu = qwer->graf.mihno_pomer[o];
	if (qwer->graf.karta_pk[o])
		bu = qwer->graf.karta_kol[o] + 4;
	else if (!bu)
		bu = qwer->graf.karta_kol[o];
	if ((qwer->graf.kart_yark[o] &&
		qwer->cikle - qwer->graf.kart_yark[o] <= 50))
		wattron(qwer->graf.vik_arena, A_BOLD);
	wattron(qwer->graf.vik_arena, COLOR_PAIR(bu));
	return (bu);
}

void	graff_scene(t_maye *qwer)
{
	WINDOW	*a_win;
	size_t	o;
	int		y;
	int		l;
	int		bu;

	a_win = qwer->graf.vik_arena;
	wmove(a_win, Y_PADDAW, X_PADDAW);
	o = 0;
	while (o < SIZE_MEM)
	{
		bu = postav_atr(qwer, o);
		wprintw(a_win, "%02hhx", qwer->scene[o]);
		wattroff(a_win, COLOR_PAIR(bu));
		wattroff(a_win, A_BOLD);
		wprintw(a_win, " ");
		o++;
		if (o % ROZM_RIDK == 0)
		{
			getyx(a_win, y, l);
			wmove(a_win, y + 1, X_PADDAW);
		}
	}
	wrefresh(a_win);
}

void	graf_perem(t_maye *qwer)
{
	if (!qwer->graf.vik_arena)
		qwer->graf.vik_arena = do_nove_vikn(VISOTA,
							SHIRINA, Y_WASSAD, X_WAS_SAD);
	graf_koord(qwer->graf.vik_arena);
	graff_scene(qwer);
}
