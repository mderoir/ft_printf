/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:11:36 by marvin            #+#    #+#             */
/*   Updated: 2020/03/04 15:11:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_printchar(t_ftpf s_arg)
{

	if (s_arg.flag == F_LIFT)
	{
		ft_putchar(s_arg.chr);
		while (--s_arg.width)
			ft_putchar(' ');
	}
	else if (s_arg.flag == F_SPACE)
	{
		while (--s_arg.width - 1)
			ft_putchar(' ');
		ft_putchar(s_arg.chr);
	}
	else
		ft_putchar(s_arg.chr);
}

void	ft_printstring(t_ftpf s_arg)
{
	if (s_arg.flag == F_LIFT)
	{
		ft_putstr(s_arg.str);
		while (--s_arg.width)
			ft_putchar(' ');
	}
	else if (s_arg.flag == F_SPACE)
	{
		while (--s_arg.width - ft_strlen(s_arg.str))
			ft_putchar(' ');
		ft_putstr(s_arg.str);
	}
	else
		ft_putstr(s_arg.str);
    free(s_arg.str);
}