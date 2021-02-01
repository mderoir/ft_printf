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

int p_int(char *str_nb, int nb, t_ftpf s_arg)
{
    int i;

    i = 0;
    if (nb < 0 && s_arg.dot >= 0)
        ft_putchar('-');
    if (s_arg.dot >= 0)
        i += p_width(s_arg.dot - 1, ft_strlen(str_nb) - 1, 1);
    i += p_precision(str_nb, ft_strlen(str_nb));
    return (i);
}

int int_flag_handler(char *str_nb, int nb, t_ftpf s_arg)
{
    int i;

    i = 0;
    if (s_arg.min == 1)
        i += p_int(str_nb, nb, s_arg);
    if (s_arg.dot >= 0 && (size_t)s_arg.dot < ft_strlen(str_nb))
        s_arg.dot = ft_strlen(str_nb);
    if (s_arg.dot >= 0)
    {
        s_arg.width -= s_arg.dot;
        i += p_width(s_arg.width, 0, 0);
    }
    else
        i += p_width(s_arg.width, ft_strlen(str_nb), s_arg.zero);
    if (s_arg.min == 0)
        i += p_int(str_nb, nb, s_arg);
    return (i);
}

int int_handler(t_ftpf s_arg, int nb)
{
    char    *str_nb;
    int     nb_tmp;
    int     i;

    nb_tmp = nb;
    i = 0;
    if (s_arg.dot == 0 && nb == 0)
    {
        i += p_width(s_arg.width, 0, 0);
        return (i);
    }
    if (nb < 0 && (s_arg.dot >= 0 || s_arg.zero == 1))
    {
        if (s_arg.zero == 1 && s_arg.dot == -1)
            p_precision("-", 1);
        nb *= -1;
        s_arg.zero = 1;
        s_arg.width--;
        i++;
    }
    str_nb = ft_itoa(nb);
    i += int_flag_handler(str_nb, nb_tmp, s_arg);
    free(str_nb);
    return (i);
}