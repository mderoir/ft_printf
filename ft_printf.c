/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:35:56 by bclerc            #+#    #+#             */
/*   Updated: 2020/10/26 14:37:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"


int	ft_printf(const char *input, ...)
{
	int 		p_width;
	va_list		ap;
	const char 	*s_input;

	s_input = ft_strdup((char *)input);
	va_start(ap, input);
	p_width = input_parser(s_input, ap);
	va_end(ap);
	free((char *)s_input);
	return (p_width);
}
