#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int fd;
	char *str;
	int ret;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	if (argc != 1)
	{
			while ((ret = get_next_line(fd, &str)))
			{
				ft_putstr(str);
				ft_putchar('\n');
				i++;
			}
	}
	else
	{
		get_next_line(0, &str);
				ft_putstr(str);
				ft_putchar('\n');
	}
	return (0);
}
