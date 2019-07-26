/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:47:10 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/19 12:03:16 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <inttypes.h>
# include <ncurses.h>

# include "libft.h"
# include "ft_printf.h"

# define SIZE_BUFF 16
# define SIZE_DUMP 32

# define YE_C_OP(l) (l > 0 && l <= QTY_OPERR - 2) ? 1 : 0

# define SIZE_IND				2
# define SIZE_REG				4
# define SIZE_DIR				SIZE_REG

# define C_REG					1
# define C_DIR					2
# define C_IND					3

# define MAX_PLAYERS			4
# define SIZE_MEM				(4 * 1024)
# define MOD_IDX				(SIZE_MEM / 8)
# define SIZE_MAX_CHAMP			(SIZE_MEM / 6)

# define NUMBER_REG				16

# define CYCLE_TO_DIE			1536
# define DELTA_CYCLE			50
# define LIVE_NUM				21
# define CHECKS_MAX				10

# define IND_T					4

# define QTY_OPERR				18

# define LEN_CHARIVNA			4
# define LEN_PROG_NAME 			(128)
# define LEN_OF_SIZE			4
# define LEN_OF_COMMENT 		(2048)
# define MAGIC_EXEC_COREVAR 	0xea83f3
# define LEN_OF_PADD			4

# define SIZE_OF_PROG			2192

# define GET_PROC(l)		((t_prroses *)l->content)
# define P_C(l)				GET_PROC(l)->qw
# define VAL_PC(l)			qwer->scene[P_C(l)]
# define CARY(l)			GET_PROC(l)->cary
# define CARRY_SET(l, V)	l->cary = !VAL_OF_REGG(tiagn, nom_o_r)
# define G_PADD(l)			GET_PROC(l)->dah
# define G_LIVE(l)			GET_PROC(l)->zive

# define G_OPER(l)			GET_PROC(l)->opsia
# define DO_DEL(l)			G_OPER(l).doloi
# define C_OF_OP(l)			G_OPER(l).c_of_op

# define ARG_GET(l, V)			l->opsia.argum[V]
# define G_VAL(l, V)			ARG_GET(l, V).chi
# define G_IDX_VAL(l, V)		ARG_GET(l, V).chi_idx
# define NUM_REG(l, V)			ARG_GET(l, V).nom_o_r
# define G_OFF(l, V)			ARG_GET(l, V).ofsad
# define ROZM(l, V)				ARG_GET(l, V).rozm
# define TIP(l, V)				ARG_GET(l, V).tip
# define USAV(l, V)				ARG_GET(l, V).vikor

# define VAL_OF_REGG(l, V)		dai_sv_nom(l->mn_reg[V])
# define BAD_NUM_REG(l)			l < 1 || l > NUMBER_REG ? 1 : 0

# define DOROGA_DO_FILE(l)	qwer->vhidni_dani.inf_igrok[l].doroga_f
# define SIGN_GETTER(l)		qwer->vhidni_dani.inf_igrok[l].p_signat

# define DAPNUT				qwer->vhidni_dani.demp
# define VAL_DAMPNUT 		qwer->vhidni_dani.val_demp
# define IHOHO_GETTT		qwer->vhidni_dani.o
# define FLAG_V				qwer->vhidni_dani.v

# define PECHAL "memory allocation failed"

typedef struct	s_igrok
{
	char		charu[LEN_CHARIVNA];
	char		imiya[LEN_PROG_NAME + 1];
	char		rozm[LEN_OF_SIZE];
	char		coment[LEN_OF_COMMENT + 1];
	char		*c_exe;
	size_t		rozm_code_exec;
	size_t		rozm_fayl;
	int			p_signat;
	int			kilkist;
	size_t		zive;
	size_t		zive_ostan;
}				t_igrok;

typedef struct	s_ars
{
	char		chi[SIZE_REG];
	char		chi_idx[SIZE_REG];
	char		tip;
	short		nom_o_r;
	int			ofsad;
	int			rozm;
	char		vikor;
}				t_ars;

typedef	struct	s_opera
{
	int			c_of_op;
	size_t		doloi;
	t_ars		argum[3];
}				t_oper;

typedef struct	s_prroses
{
	size_t		qw;
	size_t		dah;
	size_t		zive;
	char		mert;
	char		cary;
	t_oper		opsia;
	char		boets;
	char		mn_reg[NUMBER_REG + 1][SIZE_REG];
}				t_prroses;

typedef	struct	s_inf
{
	char		*doroga_f;
	int			p_signat;
	char		vikor;
}				t_inf;

typedef	struct	s_perms
{
	char		o;
	char		v;
	char		demp;
	int			val_demp;
	t_inf		inf_igrok[MAX_PLAYERS];
}				t_perms;

typedef struct	s_graf
{
	char		zupinka;
	int			shvidkist;
	char		karta_kol[SIZE_MEM];
	int			karta_pk[SIZE_MEM];
	int			kart_yark[SIZE_MEM];
	char		mihno_pomer[SIZE_MEM];
	WINDOW		*gol_vik;
	WINDOW		*vik_arena;
	WINDOW		*vik_zbok;
	WINDOW		*vik_shv;
	WINDOW		*vik_cycl;
	WINDOW		*vik_grav;
	WINDOW		*vik_parr;
}				t_graf;

typedef struct	s_maye
{
	char		scene[SIZE_MEM];
	size_t		qty_igrok;
	t_igrok		igroks[MAX_PLAYERS];
	size_t		qty_proc;
	t_list		*diiya;
	int			cikle;
	int			rahunok;
	size_t		chi_zives;
	size_t		vsogo_ziv;
	int			sk_cikl_pom;
	t_perms		vhidni_dani;
	t_graf		graf;
}				t_maye;

void			read_vhidni_d(t_maye *qwer, char **argv);
void			stav_grav(t_maye *qwer);
void			stav_prok(t_maye *qwer);
void			stav_gde(t_maye *qwer);

int				igrai_ty(t_maye *qwer);
void			zber_cikl(t_maye *qwer);
void			rahui_shto_del(t_maye *qwer);
void			read_vh_ar(t_maye *qwer, t_prroses *tiagn);
void			rah_pk(t_maye *qwer, t_prroses *tiagn, int krok);
void			ubei_to(t_maye *qwer);
void			chit_perem(t_igrok *igrok, char *doroga_f);
void			perev_perem(t_igrok *igrok, char *doroga_f);
size_t			porah_zivi(t_maye *qwer);
void			vidaliti_z_poch(t_list **head, t_list **slid);
void			vidal_prok(t_list **slid, t_list **overtake);
void			vidal_mert_proc(t_maye *qwer);
int				ti_tse_mozesh();
int				vismem_nast_norm(t_prroses *tiagn);
void			chitai_reg(t_maye *qwer, int *dah, t_prroses *tiagn);
void			chit_priam_znach(t_maye *qwer, int *dah,
									t_prroses *tiagn);
void			chit_vse(t_maye *qwer, char *lll, size_t *num_a);
void			perev_sho_ti_o(t_maye *qwer, int kilkist);
void			zberi_infu(t_maye *qwer, char **p_args, size_t *num_a);
void			tochno_mozesh();
void			porah_infu(t_maye *qwer, char *doroga_f);
void			graf_koord(WINDOW *a_win);
int				postav_atr(t_maye *qwer, size_t o);
void			chit_krivi_dani(t_maye *qwer, int *dah,
										t_prroses *tiagn);
void			yakis_instr(t_maye *qwer, t_list *slid);
void			poch_vikno(t_maye *qwer);

char			*chit_chtoto(t_maye *qwer, char *tmmp, int poch,
									size_t n);
void			pishi_chtoto(t_maye *qwer, char *src, int poch,
									size_t n);
void			nul_for_ziv(t_maye *qwer);

size_t			hto_batia(t_maye *qwer);
void			hello_igrok(t_maye *qwer);
void			poka_igrok(int ti_ubit);

void			pomilka(char *log, char *nit);
void			*fuh_batia(void *mas, size_t arr_size);
void			chto_ar(t_maye *qwer);
void			klasika(void);

int				dai_nomer(void *mas, int rozm);
int				dai_sv_nom(void *mas);
short			dai_mal_nom(void *mas);
int				zrobi_tse(int jjjj);

typedef struct	s_ur
{
	int			c_of_op;
	char		*imiya;
	char		*opisanie;
	int			hzsho;
	int			num_o_a;
	int			doloi;
	int			cary;
	int			rozm_lab;
	void		(*diy)(t_maye *, t_prroses *);
}				t_ur;

extern			const t_ur	g_op_tab[18];

void			zive(t_maye *qwer, t_prroses *tiagn);
void			fun_2(t_maye *qwer, t_prroses *tiagn);
void			fun_3(t_maye *qwer, t_prroses *tiagn);
void			fun_4(t_maye *qwer, t_prroses *tiagn);
void			fun_5(t_maye *qwer, t_prroses *tiagn);
void			fun_6(t_maye *qwer, t_prroses *tiagn);
void			fun_7(t_maye *qwer, t_prroses *tiagn);
void			fun_8(t_maye *qwer, t_prroses *tiagn);
void			fun_9(t_maye *qwer, t_prroses *tiagn);
void			fun_10(t_maye *qwer, t_prroses *tiagn);
void			fun_11(t_maye *qwer, t_prroses *tiagn);
void			fun_12(t_maye *qwer, t_prroses *tiagn);
void			fun_13(t_maye *qwer, t_prroses *tiagn);
void			fun_14(t_maye *qwer, t_prroses *tiagn);
void			fun_15(t_maye *qwer, t_prroses *tiagn);
void			fun_16(t_maye *qwer, t_prroses *tiagn);

void			da_bude_gra(t_maye *qwer, t_prroses *tiagn);

# define MEZA_V				42
# define MEZA_H				42

# define ROZM_RIDK			64
# define VISOTA				70
# define SHIRINA			205
# define Y_WASSAD			0
# define X_WAS_SAD			0
# define Y_PADDAW			4
# define X_PADDAW			10

# define Q_PER_VIS			VISOTA
# define Q_PER_SHIR			60
# define Q_Y_WAS_SAD		Y_WASSAD
# define Q_X_WAS_SAD		SHIRINA - 1
# define Q_Y_PADDAW			2
# define Q_X_PADDAW			5

# define SHW_PEREM			qwer->graf.vik_shv
# define SHW_PEREM_VIS		4
# define SHW_PEREM_DOW		Q_PER_SHIR - Q_X_PADDAW * 2
# define SHW_Y_WAS_SAD		Q_Y_WAS_SAD + Q_Y_PADDAW
# define SHW_X_WAS_SAD		Q_X_WAS_SAD + Q_X_PADDAW

# define KUK_DO_PEREM		qwer->graf.vik_cycl
# define KUK_PEREM_VIS		6
# define KYKY_PERE_SHIR		Q_PER_SHIR - Q_X_PADDAW
# define KYK_Y_WAS_SAD		SHW_Y_WAS_SAD + SHW_PEREM_VIS
# define KYK_X_WAS_SAD		Q_X_WAS_SAD + Q_X_PADDAW

# define GRAV_PEREMIG		qwer->graf.vik_grav
# define GRAV_PER_VIS		4 * MAX_PLAYERS
# define GRAV_PER_SHIR		Q_PER_SHIR	 - Q_X_PADDAW * 2
# define GRAV_Y_WAS_SAD		KYK_Y_WAS_SAD + KUK_PEREM_VIS
# define GRAV_X_WAS_SAD		Q_X_WAS_SAD + Q_X_PADDAW

# define P_PEREM 			qwer->graf.vik_parr
# define P_PEREM_VIS		8
# define P_PEREM_SHIR		Q_PER_SHIR	 - Q_X_PADDAW * 2
# define P_Y_WAS_SAD		GRAV_Y_WAS_SAD + GRAV_PER_VIS + 4
# define P_X_WAS_SAD		Q_X_WAS_SAD + Q_X_PADDAW

# define PEREM_WAS_SAD		P_Y_WAS_SAD + P_PEREM_VIS
# define PEREM_X_WAS_SAD	Q_X_PADDAW

int				graf_igra(t_maye *qwer);
WINDOW			*do_nove_vikn(int visot, int shir,
								int poch_y, int poch_x);
void			graf_perem(t_maye *qwer);
void			graff_scene(t_maye *qwer);
void			graf_tam_to(t_maye *qwer);
void			colir_now(t_maye *qwer);
void			hz_sho_rob(t_maye *qwer, int bu);

void			graf_cafe(t_maye *qwer);
void			graf_shw_dan(t_maye *qwer);
void			gfaf_kuk_dan(t_maye *qwer);
void			graf_shoto_to(t_maye *qwer);
void			graf_ti_shtuki(t_maye *qwer);

void			go_kolori(void);
void			onovi_kol(t_maye *qwer, char src, int poch, size_t n);

void			hz_shto_to(t_maye *qwer);
void			dai_shvidk(t_maye *qwer);
int				chit_tam_exe(int zw, char **tmmp);

int				ft_is_number(char *str);
int				ft_lstlen(t_list *beg);

#endif
