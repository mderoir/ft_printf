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

static int p_string(char *str, t_ftpf s_arg)
{
    int i;

    i = 0;
    if (s_arg.dot >= 0)
    {
        i += p_width(s_arg.dot, ft_strlen(str), 0);
        i += p_precision(str, s_arg.dot);
    }
    else
        i+= p_precision(str, ft_strlen(str));
    return (i);
}

int string_handler(t_ftpf s_arg, char *str)
{
    int i;

    i = 0;
    if (!str && s_arg.dot != 1 && s_arg.dot != 3)
        str = "(null)";
    else if (!str)
        str = ft_strdup("");
    if (s_arg.dot >= 0 && (size_t)s_arg.dot > ft_strlen(str))
        s_arg.dot = ft_strlen(str);
    if (s_arg.min == 1)
        i += p_string(str, s_arg);
    if (s_arg.dot >= 0)
        i += p_width(s_arg.width, s_arg.dot, 0);
    else
        i += p_width(s_arg.width, ft_strlen(str), 0);
    if (s_arg.min == 0)
        i += p_string(str, s_arg);
    return (i);
}