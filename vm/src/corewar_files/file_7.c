/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:02:26 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/19 12:08:00 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	klasika(void)
{
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("Usage: ./corewar [champ-file]\n");
	ft_printf("-----------------------------------------------------------\n");
	ft_printf("minimun number of champions 1\n");
	ft_printf("maximum number of champions 4\n\n");
	ft_printf("Additional flags:\n");
	ft_printf("    --dump [n] - prints memory dump of the game on n cycle\n\n");
	ft_printf("*---                                                   ---*\n");
	ft_printf("|   --V - turns on visualization:                         |\n");
	ft_printf("|        Visualistion controls:                           |\n");
	ft_printf("\n");
	ft_printf("         o - interactive step by step mode\n\n");
	ft_printf("         space - run / pause the game\n\n");
	ft_printf("         When the game pused it`s speed can be change:\n");
	ft_printf("            s - reduce speed for 100 cycles/second\n");
	ft_printf("            q - reduce speed for 10 cycles/second\n");
	ft_printf("            w - reduce speed for 1 cycles/second\n");
	ft_printf("            e - increase speed for 1 cycles/second\n");
	ft_printf("|           r - increase speed for 10 cycles/second       |\n");
	ft_printf("|           d - increase speed for 100 cycles/second      |\n");
	ft_printf("*---                                                   ---*\n");
	exit(1);
}

void	stav_gde(t_maye *qwer)
{
	t_list	*slid;
	size_t	qw;
	size_t	o;
	char	*c_exe;
	int		rozm;

	qwer->sk_cikl_pom = CYCLE_TO_DIE;
	qwer->chi_zives = CHECKS_MAX;
	slid = qwer->diiya;
	o = qwer->qty_igrok - 1;
	ft_memset(qwer->graf.karta_kol, 43, SIZE_MEM);
	while (slid)
	{
		qw = ((t_prroses *)slid->content)->qw;
		c_exe = qwer->igroks[o].c_exe;
		rozm = qwer->igroks[o].rozm_code_exec;
		ft_memcpy(&(qwer->scene[qw]), c_exe, rozm);
		ft_memset(&(qwer->graf.karta_kol[qw]), qwer->igroks[o].kilkist, rozm);
		slid = slid->next;
		o--;
	}
}

int		chit_tam_exe(int zw, char **tmmp)
{
	int		tor;
	int		rozm;
	char	noob[SIZE_BUFF + 1];

	rozm = 0;
	while ((tor = read(zw, noob, SIZE_BUFF)))
	{
		if (tor == -1)
			pomilka("Some errors while reading exec_code were occur", NULL);
		rozm += tor;
	}
	lseek(zw, -rozm, 2);
	*tmmp = ft_strnew(rozm);
	read(zw, *tmmp, rozm);
	return (rozm);
}

void	chit_perem(t_igrok *igrok, char *doroga_f)
{
	int			zw;

	zw = open(doroga_f, O_RDONLY);
	if (zw == -1)
		pomilka("Can't read source file %s", doroga_f);
	igrok->rozm_fayl += read(zw, igrok->charu, LEN_CHARIVNA);
	igrok->rozm_fayl += read(zw, igrok->imiya, LEN_PROG_NAME);
	lseek(zw, LEN_OF_PADD, 1);
	igrok->rozm_fayl += read(zw, igrok->rozm, LEN_OF_SIZE);
	igrok->rozm_fayl += read(zw, igrok->coment, LEN_OF_COMMENT);
	lseek(zw, LEN_OF_PADD, 1);
	igrok->rozm_fayl += LEN_OF_PADD * 2;
	igrok->rozm_code_exec = chit_tam_exe(zw, &igrok->c_exe);
	igrok->rozm_fayl += igrok->rozm_code_exec;
	close(zw);
}

void	perev_perem(t_igrok *igrok, char *doroga_f)
{
	int charu;

	if (!igrok->rozm_code_exec)
		pomilka("Champion %s has no execution code", doroga_f);
	if (igrok->rozm_code_exec > SIZE_MAX_CHAMP)
		pomilka("champion %s is too big", doroga_f);
	if (dai_sv_nom(igrok->rozm) != (int)igrok->rozm_code_exec)
		pomilka("Real fun_6 specified in header code rozm are different in %s",
					doroga_f);
	if (igrok->rozm_fayl < SIZE_OF_PROG)
		pomilka("File %s is too small to be a champion", doroga_f);
	charu = dai_sv_nom(igrok->charu);
	if (charu != MAGIC_EXEC_COREVAR)
		pomilka("File %s has an invalid header", doroga_f);
}
