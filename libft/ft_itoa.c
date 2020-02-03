/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:15:15 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/07 15:59:51 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		intlen(int nbr)
{
	int i;

	i = 0;
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		i++;
	}
	return (++i);
}

static char		*putintab(char *tab, int nbr, int i, int len)
{
	int				j;
	unsigned int	nombre;

	j = len - 1;
	if (nbr < 0)
	{
		nombre = -nbr;
		tab[i] = '-';
		i++;
	}
	else
		nombre = nbr;
	while (i < len)
	{
		tab[j] = nombre % 10 + 48;
		nombre /= 10;
		i++;
		j--;
	}
	tab[len] = '\0';
	return (tab);
}

char			*ft_itoa(int nbr)
{
	char	*tab;
	int		len;
	int		i;

	i = 0;
	len = intlen(nbr);
	if (nbr < 0)
		len += 1;
	if (!(tab = malloc(sizeof(char) * (len) + 1)))
		return (NULL);
	tab = putintab(tab, nbr, i, len);
	return (tab);
}
