/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:05:44 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/13 11:26:25 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char		*ft_strdup(const char *s1)
{
	char	*str;

	if (!(str = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char))))
		return (NULL);
	str = ft_strcpy(str, s1);
	return (str);
}
