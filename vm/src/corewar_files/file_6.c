/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:02:18 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/17 12:02:22 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	poka_igrok(int ti_ubit)
{
	char	*lin;
	char	noob[32];

	ft_bzero(noob, sizeof(noob));
	lin = ft_itoa(ti_ubit);
	ft_strcat(noob, "say ");
	ft_strcat(noob, lin);
	if (ti_ubit == 1)
		ft_strcat(noob, " process was killed &");
	else
		ft_strcat(noob, " processes were killed &");
	system(noob);
	ft_strdel(&lin);
}

void	pomilka(char *log, char *nit)
{
	if (nit == NULL)
		ft_printf("Error: %s\n", log);
	else
	{
		ft_printf("Error: ");
		ft_printf(log, nit);
		ft_printf("\n");
	}
	exit(1);
}

int		ti_tse_mozesh(void)
{
	static int rock = 0;

	rock = (17 * rock + 31) % 997;
	return (rock);
}

void	tochno_mozesh(void)
{
	int			a;
	int			b;
	static int	c = 0;

	a = ti_tse_mozesh();
	b = ti_tse_mozesh();
	c += (a > b) ? 1 : -1;
}

void	chto_ar(t_maye *qwer)
{
	size_t	o;

	ft_printf("\n\t\t\t\t\t\t~~~ MEMORY DUMP ~~~\t\t\tcycle: %u\n\n",
				qwer->cikle);
	o = 0;
	ft_printf("\t");
	while (o < SIZE_DUMP)
		ft_printf("%2i ", o++);
	ft_printf("\n\t-----------------------------------------------");
	ft_printf("------------------------------------------------\n");
	o = 0;
	while (o < SIZE_MEM)
	{
		if (o % SIZE_DUMP == 0)
			ft_printf("%o\t", o / SIZE_DUMP);
		ft_printf("%02hhx", qwer->scene[o]);
		o++;
		ft_printf(" ");
		if (o % SIZE_DUMP == 0)
			ft_printf("\n");
	}
	exit(1);
}
