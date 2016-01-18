/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcrosnie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 14:22:32 by pcrosnie          #+#    #+#             */
/*   Updated: 2015/12/04 14:45:35 by pcrosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		if (s[i] == '\0')
			return (n + 1);
		n++;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (n);
		i++;
	}
	return (n);
}

static size_t	ft_count_i(const char *s, char c, size_t nb)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i] == c)
		i++;
	if (nb == 0)
		return (i + 1);
	while (s[i] && n < nb)
	{
		while (s[i] != c && s[i])
			i++;
		if (s[i] == '\0')
			return (i);
		n++;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_linelen(const char *s, char c, size_t nb)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (i < ft_count_i(s, c, nb) - 1)
		i++;
	while (s[i] != c)
	{
		i++;
		n++;
	}
	return (n);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	n;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(tab) * (ft_count_words(s, c) + 1));
	while (i < ft_count_words(s, c) && tab)
	{
		tab[i] = (char *)malloc(sizeof(tab[i]) * ft_linelen(s, c, i));
		if (!tab[i])
			return (NULL);
		j = 0;
		n = ft_count_i(s, c, i) - 1;
		while (j < ft_linelen(s, c, i))
			tab[i][j++] = s[n++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
