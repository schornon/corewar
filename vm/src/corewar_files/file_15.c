/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_15.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:11:15 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 12:11:20 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	go_kolori(void)
{
	if (!has_colors())
	{
		endwin();
		pomilka("Your terminal does not support color", NULL);
	}
	start_color();
	init_color(COLOR_MAGENTA, 500, 500, 500);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_GREEN);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_RED);
	init_pair(8, COLOR_BLACK, COLOR_CYAN);
	init_pair(11, COLOR_WHITE, COLOR_GREEN);
	init_pair(12, COLOR_WHITE, COLOR_BLUE);
	init_pair(13, COLOR_WHITE, COLOR_RED);
	init_pair(14, COLOR_WHITE, COLOR_CYAN);
	init_pair(42, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(43, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(47, COLOR_BLACK, COLOR_MAGENTA);
}

WINDOW	*g_vikn;

void	graf_per(t_maye *qwer)
{
	size_t	perem;

	graf_cafe(qwer);
	perem = hto_batia(qwer);
	g_vikn = qwer->graf.vik_zbok;
	mvwprintw(g_vikn, PEREM_WAS_SAD, PEREM_X_WAS_SAD, "The winner is: ");
	wattron(g_vikn, COLOR_PAIR(perem + 1));
	wprintw(g_vikn, "%.34s", qwer->igroks[perem].imiya);
	wattroff(g_vikn, COLOR_PAIR(perem + 1));
	mvwprintw(g_vikn, PEREM_WAS_SAD + 2, PEREM_X_WAS_SAD,
				"Press any key to finish");
	wrefresh(qwer->graf.vik_zbok);
	wgetch(g_vikn);
}

void	poch_vikno(t_maye *qwer)
{
	qwer->graf.gol_vik = initscr();
	curs_set(0);
	go_kolori();
	noecho();
	qwer->graf.shvidkist = 50;
	qwer->graf.zupinka = 1;
	graf_cafe(qwer);
	graf_perem(qwer);
}

int		graf_igra(t_maye *qwer)
{
	int bu;

	poch_vikno(qwer);
	dai_shvidk(qwer);
	while (1)
	{
		if (IHOHO_GETTT)
			hz_shto_to(qwer);
		if (!igrai_ty(qwer))
			break ;
		if (!IHOHO_GETTT)
		{
			timeout(1000 / ((qwer->graf.shvidkist) * 1.4));
			if ((bu = getch()) == ' ')
				dai_shvidk(qwer);
		}
	}
	graf_per(qwer);
	delwin(qwer->graf.vik_arena);
	delwin(qwer->graf.vik_zbok);
	endwin();
	return (0);
}

void	graf_shw_dan(t_maye *qwer)
{
	if (!SHW_PEREM)
	{
		SHW_PEREM = subwin(qwer->graf.vik_zbok,
								SHW_PEREM_VIS, SHW_PEREM_DOW,
								SHW_Y_WAS_SAD, SHW_X_WAS_SAD);
		wrefresh(qwer->graf.vik_zbok);
	}
	if (IHOHO_GETTT)
		mvwprintw(SHW_PEREM, 0, 0, "** INTERACTIVE MODE **");
	else
	{
		if (qwer->graf.zupinka)
			mvwprintw(SHW_PEREM, 0, 0, "     ** PAUSED **     ");
		if (!qwer->graf.zupinka)
			mvwprintw(SHW_PEREM, 0, 0, "     ** RUNNING **    ");
	}
	mvwprintw(SHW_PEREM, 2, 0, "Max Speed: %4i cycle/second",
				qwer->graf.shvidkist);
	touchwin(SHW_PEREM);
	wrefresh(SHW_PEREM);
}
