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

static int		p_hexa(char *hex, t_ftpf s_arg)
{
	int i;

	i = 0;
	if (s_arg.dot >= 0)
		i += p_width(s_arg.dot - 1, ft_strlen(hex) - 1, 1);
	i += p_precision(hex, ft_strlen(hex));
	return (i);
}

static int		hexa_flag_handler(char *hex, t_ftpf s_arg)
{
	int i;

	i = 0;
	if (s_arg.min == 1)
		i += p_hexa(hex, s_arg);
	if (s_arg.dot >= 0 && (size_t)s_arg.dot < ft_strlen(hex))
		s_arg.dot = ft_strlen(hex);
	if (s_arg.dot >= 0)
	{
		s_arg.width -= s_arg.dot;
		i += p_width(s_arg.width, 0, 0);
	}
	else
		i += p_width(s_arg.width,
		ft_strlen(hex), s_arg.zero);
	if (s_arg.min == 0)
		i += p_hexa(hex, s_arg);
	return (i);
}

int				hexa_handler(t_ftpf s_arg, unsigned int ui, int lower)
{
	char	*hex;
	int		i;

	i = 0;
	ui = (unsigned int)(4294967295 + 1 + ui);
	if (s_arg.dot == 0 && ui == 0)
	{
		i += p_width(s_arg.width, 0, 0);
		return (i);
	}
	hex= ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		hex= ft_str_tolower(hex);
	i += hexa_flag_handler(hex, s_arg);
	free(hex);
	return (i);
}