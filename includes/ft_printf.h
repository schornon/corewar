/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:04:44 by sbudilko          #+#    #+#             */
/*   Updated: 2018/03/12 15:04:46 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include "libft.h"

# define TYPE		"sSpdDioOuUxXcC"
# define NSTR		"(null)"
# define NSTR_L		L"(null)"
# define FD			"{fd*}"
# define NB_CS		14

typedef struct
{
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
}				t_flags;

typedef struct
{
	int			hh;
	int			h;
	int			l;
	int			ll;
	int			j;
	int			z;
}				t_length;

typedef struct
{
	int			width;
	int			precision;
	t_flags		falgs;
	t_length	length;
	int			type;
}				t_syntax;

int				ft_quantity_digit(int n);
int				ft_quantity_digit_l(long int n);
int				ft_quantity_digit_ll(long long int n);
int				ft_quantity_digit_ull(unsigned long long int n);
void			ft_putnbr_long_fd(long int n, int fd);
void			ft_putnbr_long_long(long long int n, int fd);
char			*ft_dec_to_hex(uintmax_t arg, int len, t_syntax *syntax);
char			*ft_dec_to_hex_2(uintmax_t arg, int len, t_syntax *syntax);
int				ft_printf(const char *s, ...);
int				ft_fprintf(int fd, const char *s, va_list *ap);
int				ft_print_param(int fd, char **str, va_list *ap, t_syntax *syn);
int				ft_print_s_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_ss_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_lstrlen(wchar_t *str);
void			ft_print_2_ss_conv(int fd, t_syntax *s, wchar_t *arg, int len);
void			ft_print_3_ss_conv(int fd, wchar_t *str);
int				ft_print_p_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_d_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_d_conv_2(int fd, t_syntax *syntax, va_list *ap);
void			ft_print_d_conv_3(int fd, t_syntax *syntax, int arg, int *len);
void			ft_print_d_conv_4(int fd, t_syntax *sy, int arg, int len_prec);
int				ft_d_hh(int fd, t_syntax *syntax, va_list *ap);
int				ft_d_h(int fd, t_syntax *syntax, va_list *ap);
int				ft_d_l(int fd, t_syntax *syntax, va_list *ap);
int				ft_d_ll(int fd, t_syntax *syntax, va_list *ap);
int				ft_d_j(int fd, t_syntax *syntax, va_list *ap);
int				ft_d_j_2(int fd, t_syntax *syntax, intmax_t arg);
int				ft_d_z(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_dd_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_o_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_o_conv_2(int fd, t_syntax *syntax, va_list *ap);
void			ft_print_o_conv_3(int fd, t_syntax *syn, char *str2, int *len);
void			ft_print_o_conv_4(int fd, t_syntax *syn, char *str, int len_p);
int				ft_o_hh(int fd, t_syntax *syntax, va_list *ap);
int				ft_o_h(int fd, t_syntax *syntax, va_list *ap);
int				ft_o_h_2(int fd, t_syntax *syntax, int arg);
int				ft_o_j(int fd, t_syntax *syntax, va_list *ap);
int				ft_o_j_2(int fd, t_syntax *syntax, uintmax_t arg);
int				ft_o_l(int fd, t_syntax *syntax, va_list *ap);
int				ft_o_ll(int fd, t_syntax *syntax, va_list *ap);
int				ft_o_z(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_oo_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_u_conv(int fd, t_syntax *syntax, va_list *ap);
void			ft_print_u_conv_3(int fd, t_syntax *s, unsigned int a, int *l);
void			ft_print_u_conv_4(int fd, t_syntax *sy, unsigned int a, int l);
int				ft_u_hh(int fd, t_syntax *syntax, va_list *ap);
int				ft_u_h(int fd, t_syntax *syntax, va_list *ap);
int				ft_u_l(int fd, t_syntax *syntax, va_list *ap);
int				ft_u_ll(int fd, t_syntax *syntax, va_list *ap);
int				ft_u_j(int fd, t_syntax *syntax, va_list *ap);
int				ft_u_z(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_uu_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_x_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_x_j(int fd, t_syntax *syntax, va_list *ap);
int				ft_x_j_2(int fd, t_syntax *syntax, uintmax_t arg);
int				ft_x_h(int fd, t_syntax *syntax, va_list *ap);
int				ft_x_hh(int fd, t_syntax *syntax, va_list *ap);
int				ft_x_l(int fd, t_syntax *syntax, va_list *ap);
int				ft_x_ll(int fd, t_syntax *syntax, va_list *ap);
int				ft_x_z(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_xx_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_xx_j(int fd, t_syntax *syntax, va_list *ap);
int				ft_xx_j_2(int fd, t_syntax *syntax, uintmax_t arg);
int				ft_xx_h(int fd, t_syntax *syntax, va_list *ap);
int				ft_xx_hh(int fd, t_syntax *syntax, va_list *ap);
int				ft_xx_l(int fd, t_syntax *syntax, va_list *ap);
int				ft_xx_ll(int fd, t_syntax *syntax, va_list *ap);
int				ft_xx_z(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_c_conv(int fd, t_syntax *syntax, va_list *ap);
int				ft_print_cc_conv(int fd, t_syntax *syntax, va_list *ap);
void			ft_print_cc_conv_2(int fd, wchar_t cc);
void			ft_print_cc_conv_3(int fd, wchar_t cc, int len, t_syntax *syn);
int				ft_print_without_conv(int fd, t_syntax *syntax, char c);
void			ft_create_struct(t_syntax **syntax);
void			ft_cleaning_struct(t_syntax *syntax);
void			ft_parse_flags(char **str, t_syntax *syntax);
void			ft_parse_width(char **str, va_list *ap, t_syntax *syntax);
void			ft_parse_precision(char **str, va_list *ap, t_syntax *syntax);
void			ft_parse_length(char **str, t_syntax *syntax);
void			ft_parse_syntax(char **str, va_list *ap, t_syntax *syntax);
void			ft_parse_type(t_syntax *syntax, char c);
void			ft_fill_func_arr(int (*func[])(int fd, t_syntax *, va_list *));

#endif
