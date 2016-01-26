/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:25:50 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/26 14:51:13 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_fill_tab(char *buf, t_line *ptr)
{
	int i;
	int j;
	int k;

	i = ptr->lasti;
	j = ptr->lastj;
	k = 0;
	while (buf[k])
	{
		if (buf[k] == '\n' && buf[k++])
		{
			i++;
			j = 0;
			if (!(ptr->read[i]))
				ptr->read[i] = (char *)malloc(sizeof(char) * 10000000);
		}
		else if (buf[k])
		{
			if (buf[k + 1] == '\0')
				ptr->read[i + 1] = (char *)malloc(sizeof(char) * 10000000);
			ptr->read[i][j++] = buf[k++];
		}
	}
	ptr->lasti = i;
	ptr->lastj = j;
}

t_line	*ft_create_elem(int fd, char *buf)
{
	t_line *ptr;

	ptr = (t_line *)malloc(sizeof(t_line));
	ptr->read = (char **)malloc(sizeof(char *) * 10000000);
	ptr->read[0] = (char *)malloc(sizeof(char) * 10000000);
	ptr->read[0] = ft_memset(ptr->read[0], '\0', 10000000);
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

t_line	*ft_fill(t_line **begin, int fd, char *buf)
{
	if (!*begin)
	{
		*begin = ft_create_elem(fd, buf);
		return (*begin);
	}
	else
		return (ft_fill_fd(fd, buf, begin));
	return (NULL);
}

int		get_next_line(int const fd, char **line)
{
	char			*buf;
	static t_line	*begin;
	t_line			*ptr;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	buf = ft_memset(buf, '\0', BUFF_SIZE + 1);
	while (ft_strchr(buf, '\n') == NULL && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		ptr = ft_fill(&begin, fd, buf);
		buf = ft_memset(buf, '\0', BUFF_SIZE + 1);
	}
	ptr = ft_fill(&begin, fd, buf);
	if (ptr->read[0][0] != '\0')
		*line = ptr->read[ptr->line];
	else
		*line = NULL;
	ptr->line++;
	if (ret == 0 && ptr->read[ptr->line] == NULL)
		return (0);
	return (1);
}
