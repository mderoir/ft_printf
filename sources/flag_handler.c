/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:35:56 by bclerc            #+#    #+#             */
/*   Updated: 2020/10/20 19:07:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_ftpf min_handler(t_ftpf s_arg)
{
    s_arg.min = 1;
    s_arg.zero = 0;
    return (s_arg);
}


t_ftpf digit_handler(t_ftpf s_arg, char c_input)
{
    if (s_arg.ast == 1)
        s_arg.width = 0;
    s_arg.width = (s_arg.width * 10) + (c_input - '0');
    return (s_arg);
}

t_ftpf width_handler(t_ftpf s_arg, va_list ap)
{
    s_arg.ast = 1;
    s_arg.width = va_arg(ap, int);
    if (s_arg.width < 0)
    {
        s_arg.min = 1;
        s_arg.zero = 0;
        s_arg.width *= -1;
    }
    return (s_arg);
}

int dot_handler(const char *s_input, int pos, t_ftpf *s_arg, va_list ap)
{
    int i;

    i = pos;
    i++;
    if (s_input[i] == '*')
    {
        s_arg->dot = va_arg(ap, int);
        i++;
    }
    else
    {
        s_arg->dot = 0;
        while (ft_isdigit(s_input[i]))
            s_arg->dot = (s_arg->dot * 10) + (s_input[i++] - '0');
    }
    return (i);
}

