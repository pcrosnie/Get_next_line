/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carraydup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:22:56 by rdieulan          #+#    #+#             */
/*   Updated: 2015/12/10 16:50:59 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_carraydup(char **array)
{
	int		i;
	char	**cp;

	i = 0;
	if (!array)
		return (NULL);
	while (array[i])
		i++;
	cp = (char **)malloc(sizeof(char *) * (i));
	if (!cp)
		return (NULL);
	i = 0;
	while (array[i])
	{
		cp[i] = ft_strdup(array[i]);
		i++;
	}
	return (cp);
}
