/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:54:15 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/19 12:03:34 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

const t_ur	g_op_tab[QTY_OPERR] =
{
	{0, NULL, NULL, 0, 0, 0, 0, 0, NULL},
	{0x01, "live", "alive", 0, 1, 10, 0, SIZE_REG, zive},
	{0x02, "ld", "load", 1, 2, 5, 1, SIZE_REG, fun_2},
	{0x03, "st", "store", 1, 2, 5, 0, SIZE_REG, fun_3},
	{0x04, "add", "addition", 1, 3, 10, 1, SIZE_REG, fun_4},
	{0x05, "sub", "substruction", 1, 3, 10, 1, SIZE_REG, fun_5},
	{0x06, "and", "r1 & r2 -> r3", 1, 3, 6, 1, SIZE_REG, fun_6},
	{0x07, "or", "r1 | r2 -> r3", 1, 3, 6, 1, SIZE_REG, fun_7},
	{0x08, "xor", "r1 ^ r2 -> r3", 1, 3, 6, 1, SIZE_REG, fun_8},
	{0x09, "zjmp", "jump if zero", 0, 1, 20, 0, SIZE_IND, fun_9},
	{0x0A, "ldi", "load index", 1, 3, 25, 0, SIZE_IND, fun_10},
	{0x0B, "sti", "store index", 1, 3, 25, 0, SIZE_IND, fun_11},
	{0x0C, "fork", "fork procces", 0, 1, 800, 0, SIZE_IND, fun_12},
	{0x0D, "lld", "long load", 1, 2, 10, 1, SIZE_REG, fun_13},
	{0x0E, "lldi", "long load index", 1, 3, 50, 1, SIZE_IND, fun_14},
	{0x0F, "lfork", "long fork", 0, 1, 1000, 0, SIZE_IND, fun_15},
	{0x10, "aff", "aff", 1, 1, 2, 0, SIZE_REG, fun_16},
	{0, NULL, NULL, 0, 0, 0, 0, 0, NULL}
};

void	gfaf_kuk_dan(t_maye *qwer)
{
	if (!KUK_DO_PEREM)
	{
		KUK_DO_PEREM = subwin(qwer->graf.vik_zbok,
										KUK_PEREM_VIS, KYKY_PERE_SHIR,
										KYK_Y_WAS_SAD, KYK_X_WAS_SAD);
		wrefresh(qwer->graf.vik_zbok);
	}
	mvwprintw(KUK_DO_PEREM, 0, 0, "Cycle:\t\t%zu", qwer->cikle);
	mvwprintw(KUK_DO_PEREM, 2, 0, "Processes:\t%zu", qwer->qty_proc);
	mvwprintw(KUK_DO_PEREM, 4, 0, "Total lives:                    ");
	mvwprintw(KUK_DO_PEREM, 4, 0, "Total lives:\t%zu", qwer->vsogo_ziv);
	touchwin(KUK_DO_PEREM);
	wrefresh(KUK_DO_PEREM);
}

void	graf_shoto_to(t_maye *qwer)
{
	size_t	o;

	if (!GRAV_PEREMIG)
	{
		GRAV_PEREMIG = subwin(qwer->graf.vik_zbok,
		GRAV_PER_VIS, GRAV_PER_SHIR, GRAV_Y_WAS_SAD, GRAV_X_WAS_SAD);
		wrefresh(qwer->graf.vik_zbok);
	}
	o = 0;
	while (o < qwer->qty_igrok)
	{
		mvwprintw(GRAV_PEREMIG, o * 4, 0, "Player %o: ",
				qwer->igroks[o].p_signat);
		wattron(GRAV_PEREMIG, COLOR_PAIR(o + 1));
		wprintw(GRAV_PEREMIG, "%.38s", qwer->igroks[o].imiya);
		wattroff(GRAV_PEREMIG, COLOR_PAIR(o + 1));
		mvwprintw(GRAV_PEREMIG, o * 4 + 1, 4, "Last live:\t\t\t%4i",
			qwer->igroks[o].zive_ostan);
		mvwprintw(GRAV_PEREMIG, o * 4 + 2, 4,
				"Lives in current period:\t%4i", qwer->igroks[o].zive);
		o++;
	}
	touchwin(GRAV_PEREMIG);
	wrefresh(GRAV_PEREMIG);
}

void	graf_ti_shtuki(t_maye *qwer)
{
	if (!P_PEREM)
	{
		P_PEREM = subwin(qwer->graf.vik_zbok,
										P_PEREM_VIS, P_PEREM_SHIR,
										P_Y_WAS_SAD, P_X_WAS_SAD);
		wrefresh(qwer->graf.vik_zbok);
	}
	mvwprintw(P_PEREM, 0, 0, "CYCLE_TO_DIE:\t%4i", qwer->sk_cikl_pom);
	mvwprintw(P_PEREM, 2, 0, "CYCLE_DELTA:\t%4i", DELTA_CYCLE);
	mvwprintw(P_PEREM, 4, 0, "NBR_LIVE:\t%4i", LIVE_NUM);
	mvwprintw(P_PEREM, 6, 0, "MAX_CHECKS:\t%4i", CHECKS_MAX);
	touchwin(P_PEREM);
	wrefresh(P_PEREM);
}

void	graf_cafe(t_maye *qwer)
{
	if (!qwer->graf.vik_zbok)
		qwer->graf.vik_zbok = do_nove_vikn(Q_PER_VIS	,
					Q_PER_SHIR	, Q_Y_WAS_SAD, Q_X_WAS_SAD);
	wattron(qwer->graf.vik_zbok, A_BOLD);
	graf_shw_dan(qwer);
	gfaf_kuk_dan(qwer);
	graf_shoto_to(qwer);
	graf_ti_shtuki(qwer);
	wrefresh(qwer->graf.vik_zbok);
}

int		main(int argc, char **argv)
{
	t_maye qwer;

	if (argc == 1)
		klasika();
	ft_bzero(&qwer, sizeof(t_maye));
	read_vhidni_d(&qwer, ++argv);
	stav_grav(&qwer);
	if (!qwer.qty_igrok)
		pomilka("No players were specified", NULL);
	stav_prok(&qwer);
	stav_gde(&qwer);
	if (qwer.vhidni_dani.v)
		graf_igra(&qwer);
	else
	{
		hello_igrok(&qwer);
		while (igrai_ty(&qwer))
			;
		hto_batia(&qwer);
	}
	return (0);
}
