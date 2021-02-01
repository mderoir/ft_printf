/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:35:56 by bclerc            #+#    #+#             */
/*   Updated: 2020/10/20 18:10:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	p_adress(char *adress, t_ftpf s_arg)
{
	int i;

	i = 0;
	i += p_precision("0x", 2);
	if (s_arg.dot >= 0)
	{
		i += p_width(s_arg.dot, ft_strlen(adress), 1);
		i += p_precision(adress, s_arg.dot);
	}
	else
		i += p_precision(adress, ft_strlen(adress));
	return (i);
}

int			adress_handler(t_ftpf s_arg, unsigned long long ullnb)
{
	char	*adress;
	int		i;

	i = 0;
	if (ullnb == 0 && s_arg.dot == 0)
    {
	    i += p_precision("0x", 2);
	    return (i += p_width(s_arg.width, 0, 1));
    }
    else if (ullnb == 0)
            return (p_precision("(nil)", 5));
	adress = ft_ull_base(ullnb, 16);
	adress = ft_str_tolower(adress);
	if ((size_t)s_arg.dot < ft_strlen(adress))
		s_arg.dot = ft_strlen(adress);
	if (s_arg.min == 1)
		i += p_adress(adress, s_arg);
	i += p_width(s_arg.width, ft_strlen(adress) + 2, 0);
	if (s_arg.min == 0)
		i += p_adress(adress, s_arg);
	free(adress);
	return (i);
}