/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:57:52 by rdieulan          #+#    #+#             */
/*   Updated: 2015/12/09 16:38:29 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;

	i = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result && s)
	{
		while (i < len)
		{
			result[i] = s[start + i];
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}
