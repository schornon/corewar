/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 12:37:12 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/18 16:20:02 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/op.h"
#include "../../../includes/asm.h"

#include <stdio.h>

int		get_len(t_pair *pair)
{
	int		i;

	i = 0;
	free((pair->str_todel));
	while (get_next_line(pair->fd, &(pair->str_todel)))
	{
		pair->str = pair->str_todel;
		if (ft_strlen(pair->str) == 0)
		{
			i++;
			free((pair->str_todel));
			continue;
		}
		while (pair->str[0] != '\0' && (pair->str)[0] != 34)
		{
			(pair->str)++;
			i++;
		}
		if (pair->str[0] == 34)
			return (i + 1);
		free((pair->str_todel));
		i++;
	}
	asm_error("Lexical error. No \"", "");
	return (0);
}

int		get_len_name_coment(t_pair *pair)
{
	int		len;

	len = 0;
	while (*(pair->str) == ' ' || *(pair->str) == '\t')
		(pair->str)++;
	if (pair->str[0] != 34)
		asm_error("Lexical error. No \"", "");
	(pair->str)++;
	if (*(pair->str) == 34)
		return (-1);
	while (pair->str[0] != '\0' && (pair->str)[0] != 34)
	{
		(pair->str)++;
		len++;
	}
	if (pair->str[0] != 34)
		len += get_len(pair);
	(pair->str)++;
	while (*(pair->str) == ' ' || *(pair->str) == '\t')
		(pair->str)++;
	if (pair->str[0] != COMMENT_CHAR && pair->str[0] != ALT_COMMENT_CHAR
		&& pair->str[0] != '\0')
		asm_error("Syntax error - too many command per line. Name or comment",
				"");
	return (len);
}

void	check_name(t_pair *pair)
{
	if (ft_strncmp((pair->str), NAME_CMD_STRING,
		ft_strlen(NAME_CMD_STRING)) == 0)
	{
		if (pair->i != 0)
			asm_error("Too many names", "");
		pair->str += ft_strlen(NAME_CMD_STRING);
		pair->i = get_len_name_coment(pair);
		if (pair->i > PROG_NAME_LENGTH)
			asm_error("Champion name too long", "");
	}
	else if (ft_strncmp((pair->str), COMMENT_CMD_STRING,
			ft_strlen(COMMENT_CMD_STRING)) == 0)
	{
		if (pair->j != 0)
			asm_error("Too many comments", "");
		pair->str += ft_strlen(COMMENT_CMD_STRING);
		pair->j = get_len_name_coment(pair);
		if (pair->j > COMMENT_LENGTH)
			asm_error("Champion comment too long", "");
	}
	else
		asm_error("No name or comment", "");
}

void	validate_name_comment(t_pair *pair)
{
	while (get_next_line(pair->fd, &(pair->str_todel)))
	{
		pair->str = pair->str_todel;
		while (*(pair->str) == ' ' || *(pair->str) == '\t')
			(pair->str)++;
		if (*(pair->str) == COMMENT_CHAR || *(pair->str) == ALT_COMMENT_CHAR
			|| !(*(pair->str)))
		{
			free((pair->str_todel));
			continue;
		}
		check_name(pair);
		free(pair->str_todel);
		if (pair->j != 0 && pair->i != 0)
			break ;
	}
}

void	free_arg(char **arg, int i)
{
	char	**tmp;

	tmp = arg;
	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(arg);
}
