/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:25:50 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/18 17:28:52 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void    ft_fill_tab(char *buf, t_line *ptr)
{
	int i;
	int j;
	int k;
	int a;

	i = ptr->lasti;
	j = ptr->lastj;
	k = 0;
	a = 0;
	while (buf[k] && k < BUFF_SIZE + 1)
	{
		if (buf[k] == '\n')
		{
			k++;
			i++;
			j = 0;
			ptr->read[i] = (char *)malloc(sizeof(char) * 1000000);
		}
		if (buf[k] && k < BUFF_SIZE + 1)
			ptr->read[i][j++] = buf[k++];
	}
	ptr->lasti = i;
	ptr->lastj = j;
}

t_line  *ft_create_elem(int fd, char *buf)
{
	t_line *ptr;

	ptr = (t_line *)malloc(sizeof(t_line));
	ptr->read = (char **)malloc(sizeof(char *) * 1000000);
	ptr->read[0] = (char *)malloc(sizeof(char) * 1000000);
	ptr->fd = fd;
	ptr->next = NULL;
	ptr->line = 0;
	ptr->lasti = 0;
	ptr->lastj = 0;
	ft_fill_tab(buf, ptr);
	return (ptr);
}

t_line	*ft_fill_fd(int fd, char *buf, t_line **begin)
{
	t_line *ptr;

	ptr = *begin;
	while (ptr != NULL)
	{
		if (ptr->fd == fd)
		{
			ft_fill_tab(buf, ptr);
			return (ptr);
		}
		else if (fd != ptr->fd && ptr->next == NULL)
		{
			ptr->next = ft_create_elem(fd, buf);
			return (ptr->next);
		}
		ptr = ptr->next;
	}
	return (ptr);
}

int		get_next_line(int const fd, char **line)
{
	char *buf;;
	static t_line *begin;
	t_line *ptr;
	int ret;

	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((ret = read(fd, buf, BUFF_SIZE + 1)) && ft_strchr(buf, '\n') == NULL)
	{
		if (!begin)
		{
			begin = ft_create_elem(fd, buf);
			ptr = begin;
		}
		else
		{
			ptr = ft_fill_fd(fd, buf, &begin);
		}
		buf = ft_memset(buf, '\0', BUFF_SIZE + 1);
	}
	if (!begin)
	{
		begin = ft_create_elem(fd, buf);
		ptr = begin;
	}
	else
	{
		ptr = ft_fill_fd(fd, buf, &begin);
	}
	*line = ptr->read[ptr->line];
	ptr->line++;
	if (ret == -1)
		return (-1);
	if (ret == 0 && ptr->read[ptr->line] == NULL)
		return(0);
	return (1);
}
