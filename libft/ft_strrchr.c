/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:23:56 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/07 12:35:57 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;

	i = ft_strlen(s);
	while (i > -1)
	{
		if (s[i] == c)
			return ((char*)&s[i]);
		i--;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}
