/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:10:33 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/13 11:39:58 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	y;
	char	*substr;

	if (!s)
		return (NULL);
	if (start > (size_t)ft_strlen(s) || (size_t)ft_strlen(s) - start < len)
		return (ft_strdup(""));
	y = 0;
	i = start;
	if (!(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (y < len)
	{
		substr[y] = s[i];
		i++;
		y++;
	}
	substr[y] = '\0';
	return (substr);
}
