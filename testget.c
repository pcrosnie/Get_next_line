/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 11:02:54 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/13 14:28:11 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     ft_check_for_endline(char *buf)
{
	int i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_fill_tab(char *buf, t_line *ptr)
{
	int i;
	int j;
	int k;

	i = ptr->lasti;
	j = ptr->lastj;
	k = 0;
	while (k < BUFF_SIZE + 1)
	{
		if (buf[k] == '\n')
		{
			i++;
			j = 0;
			ptr->read[i] = (char *)malloc(sizeof(char) * 1000000);
		}
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
	ptr->line = 0;
	ptr->lasti = 0;
	ptr->lastj = 0;
	ft_fill_tab(buf, ptr);
	return (ptr);
}

t_line	*ft_fill_fd(int fd, char *buf, t_line *adr)
{
	t_line *ptr;
	t_line *ptr2;
	int n;

	ptr2 = adr;
	n = 0;
	ft_putchar('A');
	while (ptr != NULL && n == 0)
	{
		if (fd == ptr->fd)
		{
			n = 1;
			ft_fill_tab(buf, ptr);
		}
		if (n == 0)
			ptr = ptr->next;
	}
	ft_putchar('W');
	if (n == 0)
	{
		ptr2 = adr;
		while (ptr2->next != NULL)
			ptr2 = ptr2->next;
		ptr = ft_create_elem(fd, buf);
		ptr2->next = ptr;
	}
	return (ptr);
}

int		get_next_line(int const fd, char **line)
{
	static t_line *begin = NULL;
	t_line *ptr;
	char buf[BUFF_SIZE + 1];
	int ret;

	ft_putchar('B');
	*line = (char *)malloc(sizeof(char) * 100000);
	while ((ret = read(fd, buf, BUFF_SIZE + 1)))
	{
//		if (!begin)
			ft_putstr(ft_create_elem(fd, buf)->read[0]);
			ft_putchar('X');
//		else
//			ptr = ft_fill_fd(fd, buf, begin);
	}
	ft_putchar('Q');
	*line = ptr->read[ptr->line];
	ptr->line++;
	return (ret);
}

