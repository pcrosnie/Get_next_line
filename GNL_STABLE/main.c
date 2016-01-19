#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int fd;
	char *str;
	int ret;

	fd = open(argv[1], O_RDONLY);
	ft_putnbr(get_next_line(fd, &str));
	ft_putchar('\n');
	ft_putnbr(ft_strlen(str));
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');
	ft_putnbr(get_next_line(fd, &str));
	ft_putchar('\n');
	if (str == NULL)
		ft_putstr("NULL\n");
	ft_putstr(str);
	ft_putchar('\n');
	ret = get_next_line(fd, &str);
	ft_putnbr(ret);
	ft_putchar('\n');
	return (0);
}


