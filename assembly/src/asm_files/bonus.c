/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:33:36 by schornon          #+#    #+#             */
/*   Updated: 2019/06/18 16:21:01 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

char	*conv_asm(unsigned int num, int base)
{
	static char	rep[] = "0123456789abcdef";
	char		*temp;
	static char	buffer[50];
	char		*ptr;

	temp = rep;
	ptr = &buffer[49];
	*ptr = '\0';
	if (num == 0 && (*--ptr = '0'))
		return (ptr);
	if (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	while (num != 0)
	{
		*--ptr = temp[num % base];
		num /= base;
	}
	return (ptr);
}

void	show_instr_and_arg(t_tok *tmp, int i, char **p, int num)
{
	ft_printf("%sasm_%-3d%s ->| ", p[5], num, p[0]);
	while (tmp)
	{
		if ((tmp->code != -1 || tmp->size != 0) && ++i)
			ft_printf("%s%s%s ", p[i], tmp->con, p[0]);
		tmp = tmp->next;
		if (tmp && ft_strcmp(tmp->type, "INSTRUCTION") == 0)
		{
			ft_printf("|->");
			return ;
		}
		i == 5 ? i = 0 : 0;
	}
	ft_printf("|->");
}

void	shower(t_tok *tmp, int i, char **p)
{
	char *str;

	if (tmp->code >= 0)
		ft_printf("%s%0*x%s ", p[i], tmp->size * 2, tmp->code, p[0]);
	else
	{
		str = conv_asm(tmp->code, 16);
		if (tmp->size == 4)
			ft_printf("%s%0*x%s ", p[i], tmp->size * 2, tmp->code, p[0]);
		else
			ft_printf("%s%s%s ", p[i], &str[4], p[0]);
	}
}

t_tok	*show_tokens_code(t_tok *tmp, int i, char **p)
{
	ft_printf("\n        ->| ", "");
	while (tmp)
	{
		if ((tmp->code != -1 || tmp->size != 0) && ++i)
		{
			shower(tmp, i, p);
			if (tmp->arg_code != -1)
				ft_printf("%s%x%s ", p[i], tmp->arg_code, p[0]);
		}
		tmp = tmp->next;
		if (tmp && ft_strcmp(tmp->type, "INSTRUCTION") == 0)
			return (tmp->prev);
		i == 5 ? i = 0 : 0;
	}
	return (tmp);
}

void	tokens_hex_bonus(t_s *s)
{
	t_tok	*tmp;
	char	*p[6];
	int		num;

	p[0] = "\033[0m";
	p[1] = "\033[91;m";
	p[2] = "\033[94;m";
	p[3] = "\033[93;m";
	p[4] = "\033[92;m";
	p[5] = "\033[36;m";
	tmp = s->t;
	num = 0;
	while (tmp)
	{
		if (ft_strcmp(tmp->type, "INSTRUCTION") == 0)
		{
			show_instr_and_arg(tmp, 0, p, ++num);
			tmp = show_tokens_code(tmp, 0, p);
			ft_printf("|\n");
		}
		tmp != NULL ? tmp = tmp->next : 0;
	}
}
