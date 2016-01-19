/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 13:18:36 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/18 17:55:57 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int fd;
	char *str;
	int ret;
	int ret2;
	int fd2;
	int i;
	i = 0;

	str = NULL;
	fd = open(argv[1], O_RDONLY);
	while (i < 4 && (ret = get_next_line(fd, &str)))
	{
		ft_putnbr(ret);
		ft_putchar('\n');
		ft_putstr(str);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
	ft_putstr("File 2\n");
	fd2 = open(argv[2], O_RDONLY);
	while ((ret2 = get_next_line(fd2, &str)))
	{
		ft_putnbr(ret2);
		ft_putchar('\n');
		ft_putstr(str);
		ft_putchar('\n');
	}
	ft_putnbr(ret2);
	ft_putchar('\n');
	ft_putstr("File 1\n");
	while ((ret = get_next_line(fd, &str)))
	{
		ft_putstr(str);
		ft_putchar('\n');
	}
	return (0);
}
