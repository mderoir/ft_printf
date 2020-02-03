/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:22:57 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/13 11:28:35 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_checkset(char c, char set)
{
	if (set == c)
		return (1);
	return (0);
}

static int		count_char(char const *s, char set)
{
	if (*s && ft_checkset(*s, set) == 0)
		return (count_char(++s, set) + 1);
	return (1);
}

static int		wnb(char const *s, char set)
{
	int count;

	count = 0;
	while (*s)
	{
		if (ft_checkset(*s, set))
		{
			while (*s && ft_checkset(*s, set))
				++s;
			++count;
		}
		else
			++s;
	}
	return (++count);
}

static void		*free_tab(char **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char set)
{
	char	**word_tab;
	char	*temp_s;
	int		i;
	int		y;

	if (!(s) || !(word_tab = (char**)malloc(sizeof(char*) * (wnb(s, set) + 1))))
		return (NULL);
	y = 0;
	while (*s)
	{
		if (ft_checkset(*s, set))
			++s;
		else
		{
			i = 0;
			if (!(temp_s = (char*)malloc(sizeof(char) * count_char(s, set))))
				return (free_tab(word_tab, y));
			while (*s && ft_checkset(*s, set) == 0)
				temp_s[i++] = *(s++);
			temp_s[i] = 0;
			word_tab[y++] = temp_s;
		}
	}
	word_tab[y] = 0;
	return (word_tab);
}
