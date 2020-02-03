/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:37:06 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/07 16:46:46 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isdiff(char c, char const *set)
{
	int y;

	y = 0;
	while (set[y])
	{
		if (c == set[y])
			return (1);
		y++;
	}
	return (0);
}

static int	check_if_char_after(char *str, char const *set)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(isdiff(str[i], set)))
			return (1);
		i++;
	}
	return (0);
}

static int	countchar(char const *s1, char const *set, int i)
{
	int count;

	count = 0;
	while (isdiff(s1[i], set))
		i++;
	while (s1[i])
	{
		if (isdiff(s1[i], set))
			if (!(check_if_char_after((char*)&s1[i], set)))
				break ;
		i++;
		count++;
	}
	return (count + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!(str = malloc(countchar(s1, set, i) * sizeof(char))))
		return (NULL);
	while (isdiff(s1[i], set))
		i++;
	while (s1[i])
	{
		if (isdiff(s1[i], set))
			if (!(check_if_char_after((char*)&s1[i], set)))
				break ;
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
