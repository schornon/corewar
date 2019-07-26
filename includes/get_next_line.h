/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:07:23 by sbudilko          #+#    #+#             */
/*   Updated: 2018/02/22 13:45:28 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 30

typedef struct		s_line
{
	int				fd;
	char			*buff;
	struct s_line	*next;

}					t_line;

int					get_next_line(const int fd, char **line);

#endif
