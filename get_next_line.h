/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:03:15 by pcrosnie          #+#    #+#             */
/*   Updated: 2016/01/26 13:29:02 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1000
# include <fcntl.h>
# include "libft.h"

int					get_next_line(int const fd, char **line);

typedef struct		s_line
{
	int				lasti;
	int				lastj;
	int				line;
	int				fd;
	char			**read;
	struct s_line	*next;
}					t_line;

#endif
