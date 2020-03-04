/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_converter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:25:58 by marvin            #+#    #+#             */
/*   Updated: 2020/03/04 15:25:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

t_ftpf nbr_to_str(t_ftpf s_arg, va_list ap)
{
    return (s_arg);
}

t_ftpf nbr_to_str_hex(t_ftpf s_arg, va_list ap)
{
    return (s_arg);
}

t_ftpf str_to_hex(t_ftpf s_arg, va_list ap)
{
    return (s_arg);
}

t_ftpf s_converter(t_ftpf s_arg, va_list ap)
{
    char *tmp;

    
    if (s_arg.type == 'c')
    {
        s_arg.len = 1;
		s_arg.chr = va_arg(ap, int);
    }
	else if (s_arg.type == 's')
    {
        tmp = va_arg(ap, char *);
        s_arg.len = ft_strlen(tmp);
		s_arg.str = ft_strdup(tmp);
    }
	else if (s_arg.type == 'd')
		s_arg = nbr_to_str(s_arg, ap);
	else if (s_arg.type == 'i')
		s_arg = nbr_to_str(s_arg, ap);
	else if (s_arg.type == 'u')
		s_arg = nbr_to_str(s_arg, ap);
	else if (s_arg.type == 'x')
		s_arg = nbr_to_str_hex(s_arg, ap);
	else if (s_arg.type == 'X')
		s_arg = nbr_to_str_hex(s_arg, ap);
	else if (s_arg.type == 'p')
		s_arg = str_to_hex(s_arg, ap);
    return (s_arg);
}