/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schornon <schornon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 12:11:04 by sbudilko          #+#    #+#             */
/*   Updated: 2019/06/18 16:10:25 by schornon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	ft_newlst(t_line **lst, int fd)
{
	t_line	*new_lst;
	int		i;
	char	buff[BUFF_SIZE + 1];

	if (*lst == NULL)
		return ;
	new_lst = *lst;
	if (new_lst->next == NULL && new_lst->fd == fd)
		return ;
	while (new_lst->next != NULL)
	{
		if (new_lst->fd == fd)
			return ;
		new_lst = new_lst->next;
	}
	if (new_lst->fd == fd)
		return ;
	new_lst->next = (t_line*)malloc(sizeof(t_line));
	ft_bzero(buff, BUFF_SIZE + 1);
	i = read(fd, buff, BUFF_SIZE);
	new_lst->next->buff = (char*)malloc(sizeof(char) * (i + 1));
	ft_memcpy(new_lst->next->buff, buff, i);
	new_lst->next->buff[i] = '\0';
	new_lst->next->fd = fd;
	new_lst->next->next = NULL;
}

int		ft_pre_make_line(int fd, t_line *lst)
{
	int		i;
	char	*tmp;
	char	buff[BUFF_SIZE + 1];

	i = -1;
	ft_bzero(buff, BUFF_SIZE + 1);
	if (lst->buff[0] == '\0')
	{
		if (read(fd, buff, BUFF_SIZE) == 0)
			return (-1);
		ft_strdel(&(lst->buff));
		lst->buff = ft_strdup(buff);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	while (lst->buff[++i] != '\0')
		if (lst->buff[i] == '\n')
			return (i + 1);
	if (read(fd, buff, BUFF_SIZE) == 0)
		return (ft_strlen(lst->buff) + 1);
	tmp = ft_strdup(lst->buff);
	ft_strdel(&(lst->buff));
	lst->buff = ft_strjoin(tmp, buff);
	ft_strdel(&tmp);
	return (0);
}

void	ft_remake_line(int i, t_line *lst)
{
	char	*tmp;

	if (lst->buff[i - 1] == 0)
	{
		ft_strdel(&(lst->buff));
		lst->buff = NULL;
		lst->buff = ft_strdup("\0");
		return ;
	}
	lst->buff = lst->buff + i;
	tmp = ft_strdup(lst->buff);
	lst->buff = lst->buff - i;
	ft_strdel(&(lst->buff));
	lst->buff = ft_strdup(tmp);
	ft_strdel(&tmp);
}

char	*ft_make_line(int fd, t_line *lst)
{
	int		pos;
	char	*str;

	pos = 0;
	while (lst->next != NULL)
	{
		if (lst->fd == fd)
			break ;
		lst = lst->next;
	}
	while (pos == 0)
		pos = ft_pre_make_line(fd, lst);
	if (pos == -1)
		return (NULL);
	str = ft_strnew(pos - 1);
	ft_memcpy(str, lst->buff, pos - 1);
	ft_remake_line(pos, lst);
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static t_line	*lst;
	int				i;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buff, 0) != 0)
		return (-1);
	ft_newlst(&lst, fd);
	if (lst == NULL)
	{
		lst = (t_line*)malloc(sizeof(t_line));
		ft_bzero(buff, BUFF_SIZE + 1);
		i = read(fd, buff, BUFF_SIZE);
		lst->buff = (char*)malloc(sizeof(char) * (i + 1));
		ft_memcpy(lst->buff, buff, i);
		lst->buff[i] = '\0';
		lst->fd = fd;
		lst->next = NULL;
	}
	*line = ft_make_line(fd, lst);
	if (*line == NULL)
		return (0);
	return (1);
}
