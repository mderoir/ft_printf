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

int p_unsint(char *str_unb, t_ftpf s_arg)
{
    int i;

    i = 0;
    if (s_arg.dot >= 0)
        i += p_width(s_arg.dot - 1, ft_strlen(str_unb) - 1, 1);
    i += p_precision(str_unb, ft_strlen(str_unb));
    return (i);
}

int unsint_flag_handler(char *str_unb, t_ftpf s_arg)
{
    int i;

    i = 0;
    if (s_arg.min == 1)
        i += p_unsint(str_unb, s_arg);
    if (s_arg.dot >= 0 && (size_t)s_arg.dot < ft_strlen(str_unb))
        s_arg.dot = ft_strlen(str_unb);
    if (s_arg.dot >= 0)
    {
        s_arg.width -= s_arg.dot;
        i += p_width(s_arg.width, 0, 0);
    }
    else
        i += p_width(s_arg.width, ft_strlen(str_unb), s_arg.zero);
    if (s_arg.min == 0)
        i += p_unsint(str_unb, s_arg);
    return (i);
}

int unsint_handler(t_ftpf s_arg, unsigned int unb)
{
    char    *str_unb;
    int     i;

    i = 0;
    unb = (unsigned int)(4294967295 + 1 + unb);
    if (s_arg.dot == 0 && unb == 0)
    {
        i += p_width(s_arg.width, 0, 0);
        return(i);
    }
    str_unb = ft_unsitoa(unb);
    i += unsint_flag_handler(str_unb, s_arg);
    free(str_unb);
    return (i);
}