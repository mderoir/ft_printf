/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_build.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:51:31 by marvin            #+#    #+#             */
/*   Updated: 2020/03/04 14:51:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int is_valid_flag(char c_input)
{
	if (c_input == '-' || c_input == '0' || c_input == '.' ||
		 c_input == '*' || c_input == ' ')
		 return (1);
	return (0);
}

int is_valid_type(char c_input)
{
	if (c_input == 'c' || c_input == 's' || c_input == 'p' || c_input == 'd' ||
		c_input == 'i' || c_input == 'u' || c_input == 'x' || c_input == 'X')
		return (1);
	return (0);
}

int	s_build(t_ftpf s_arg, va_list ap)
{
	int i;

	i = 0;
	if (s_arg.type == 'c')
		i += p_char(s_arg, va_arg(ap, int));
	else if (s_arg.type == 's')
		i += string_handler(s_arg, va_arg(ap, char *));
	else if (s_arg.type == 'd' || s_arg.type == 'i')
		i += int_handler(s_arg, va_arg(ap, int));
	else if (s_arg.type == 'u')
		i += unsint_handler(s_arg, (unsigned int)va_arg(ap, unsigned int));
	else if (s_arg.type == 'x')
		i += hexa_handler(s_arg, va_arg(ap, unsigned int), 1);
	else if (s_arg.type == 'X')
		i += hexa_handler(s_arg, va_arg(ap, unsigned int), 0);
	else if (s_arg.type == 'p')
		i += adress_handler(s_arg, va_arg(ap, unsigned long long));
	else if (s_arg.type == '%')
		i += p_percent(s_arg);
	return (i);	
}