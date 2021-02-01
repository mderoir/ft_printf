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

int p_percent(t_ftpf s_arg)
{
    int i;

    i = 0;
    if (s_arg.min == 1)
        i += p_precision("%", 1);
    i += p_width(s_arg.width, 1, s_arg.zero);
    if (s_arg.min == 0)
        i += p_precision("%", 1);
    return (i);
}