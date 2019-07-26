/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 20:49:09 by schornon          #+#    #+#             */
/*   Updated: 2019/06/03 13:42:40 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "get_next_line.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct			s_s
{
	int					i;
	int					r;
	int					flag_c;
	int					flag_pt;
	int					fd;
	char				*fd_name;
	int					fd_out;
	char				*fd_out_name;
	char				*out;
	struct s_header		*header;
	struct s_l			*l;
	struct s_tok		*t;
	char				**op_tab;
	int					*op_tdir;
}						t_s;

typedef struct			s_l
{
	char				*line;
	struct s_l			*next;
}						t_l;

typedef struct			s_tok
{
	char				*con;
	char				*type;
	int					num;
	int					code;
	int					arg_code;
	int					size;
	struct s_tok		*next;
	struct s_tok		*prev;
	struct s_tok		*dir_lbl;
}						t_tok;

t_s						*create_struct(int ac, char **av);
int						get_fd(int ac, char **av);
char					*get_fd_name(int ac, char **av);
t_l						*file_to_lists(t_s *s);
t_l						*create_lnode(char *line);
void					my_exit(int ec);
void					tokenization(t_s *s);
int						count_rows(t_s *s);
int						valid_new_token_list(t_s *s, t_l *tmp_l);
void					create_token(t_s *s, char *line, char *tok_type);
int						skip_spaces_tabs(t_s *s, t_l *tmp_l);
int						move_sr(t_s *s, t_l *tmp_l, int k);
void					arguments_tokenizator(t_s *s, t_l *tmp_l);
t_l						*init_name_comment_tokens(t_s *s, t_l *tmp_l);
void					translator(t_s *s);

void					init_out_fd(t_s *s);
void					data_to_header(t_s *s);
void					write_data(int fd, void *data, int size);
void					write_data_rev(int fd, void *data, int size);
int						count_ex_code_size(t_s *s);

void					encode_tokens(t_s *s);
int						binstr_to_int(char *binstr);
void					encode_tokens_2(t_s *s);
void					encode_arg_in_dir_label(t_s *s, t_tok *tok, int k);

void					get_flags(int ac, char **av, t_s *new);
void					bonus(t_s *s);
void					tokens_hex_bonus(t_s *s);

void					tokens_printer(t_s *s);

void					asm_error(char *message1, char *message2);

typedef struct			s_label
{
	int					flag;
	int					status;
	char				*content;
	struct s_label		*next;
}						t_label;

typedef struct			s_pair
{
	int					i;
	int					j;
	int					fd;
	int					status;
	void				(*func_arr[16])(char *str, t_label *l, char *c);
	char				*str_todel;
	char				*str;
	char				**op_code;
	t_label				*labels;
	t_label				*labels_arg;
}						t_pair;

void					check_ins(t_pair *pair);
void					validation(t_pair *pair, t_s *s);

void					check_command_live(char *str, t_label *l, char *name);
void					check_command_ld(char *str, t_label *l, char *name);
void					check_command_st(char *str, t_label *l, char *name);
void					check_command_add(char *str, t_label *l, char *name);
void					check_command_sub(char *str, t_label *l, char *name);
void					check_command_and(char *str, t_label *l, char *name);
void					check_command_or(char *str, t_label *l, char *name);
void					check_command_xor(char *str, t_label *l, char *name);
void					check_command_zjmp(char *str, t_label *l, char *name);
void					check_command_ldi(char *str, t_label *l, char *name);
void					check_command_sti(char *str, t_label *l, char *name);
void					check_command_fork(char *str, t_label *l, char *name);
void					check_command_lld(char *str, t_label *l, char *name);
void					check_command_lldi(char *str, t_label *l, char *name);
void					check_command_lfork(char *str, t_label *l, char *name);
void					check_command_aff(char *str, t_label *l, char *name);

int						get_len(t_pair *pair);
int						get_len_name_coment(t_pair *pair);
void					check_name(t_pair *pair);
void					validate_name_comment(t_pair *pair);
void					fill_func_arr(t_pair *pair);
void					init_pair(t_pair *pair, t_s *s);
void					check_label(t_pair *pair);
void					check_last_symbol(t_s *s);

void					check_line(t_pair *pair);

void					add_label_arg(t_label *label, char **str);
void					check_t_dir(char **str, t_label *label, char *name);
void					check_reg(char *str, char *name);
void					check_t_ind(char **str, t_label *label, char *name);
void					is_comment(char *s, char *name);
int						count_args(char *s);
void					check_arg(char *str, t_label *label, char *name);
void					check_arg2(char *str, t_label *label, char *name);

void					free_arg(char **arg, int i);

#endif
