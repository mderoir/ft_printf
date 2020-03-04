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

t_ftpf	s_init(void)
{
	t_ftpf s_arg;

	s_arg.pre = 0;
	s_arg.width = 0;
	s_arg.flag = 0;
	s_arg.type = 0;
	s_arg.len = 0;
    s_arg.chr = 0;
    s_arg.str = ft_strdup("");

	return (s_arg);
}

int is_valid_type(char c_input)
{
	if (c_input == 'c' || c_input == 's' || c_input == 'p' || c_input == 'd' ||
		c_input == 'i' || c_input == 'u' || c_input == 'x' || c_input == 'X')
		return (1);
	return (0);
}

int	f_check(const char *input, int pos)
{
	pos++;
	if (input[pos] == '-')
		return (F_LIFT);
	else if (input[pos] == '.')
		return (F_PREC);
	else if (input[pos] == '0' && !(is_digit(input[pos - 1])))	
		return (F_ZERO);
	else if (is_digit(input[pos]) || input[pos] == ' ')	
		return (F_SPACE);
	else if (is_valid_type(input[pos]))	
		return (F_TYPE);
	return (0);
}

int get_pre(const char *input, int pos, va_list ap)
{
	int pre;

	pre = 0;
	while (input[pos] && input[pos] != '*' && !(is_digit(input[pos])))
		pos++;
	input[pos] == '*' && input[pos - 1] == '.' ? pre = va_arg(ap, int) : 0;
	while (is_digit(input[pos]))
		pre = pre * 10 + input[pos++] - '0';
	return (pre);
}

int	get_width(const char *input, int pos, va_list ap)
{
	int width;

	width = 0;
	while (input[pos] && input[pos] != '*' && !(is_digit(input[pos])))
		pos++;
	if (!(is_digit(input[pos - 1])) && input[pos] == '0' && input[pos])
		pos++;
	input[pos] == '*' && input[pos - 1] != '.' ? width = va_arg(ap, int) : 0;
	while (is_digit(input[pos]) && input[pos])
		width = width * 10 + input[pos++] - '0';
	return (width);
}

char get_type(const char *input, int pos)
{
	char type;

	while (!(is_valid_type(input[pos])) && input[pos])
		pos++;
	is_valid_type(input[pos]) ? type = input[pos] : 0 ;
	return (type);
}

t_ftpf	s_build(t_ftpf s_arg, const char *input, size_t pos, va_list ap)
{

	s_arg = s_init();
	s_arg.flag = f_check(input, pos);
	s_arg.width = get_width(input, pos, ap);
	if (s_arg.flag == F_PREC)
		s_arg.pre = get_pre(input, pos, ap);
	s_arg.type = get_type(input, pos);
    s_arg = s_converter(s_arg, ap);

	return (s_arg);
}