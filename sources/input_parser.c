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

static t_ftpf	struct_init(void)
{
	t_ftpf s_arg;

	s_arg.width = 0;
	s_arg.type = 0;
    s_arg.dot = -1;
    s_arg.zero = 0;
    s_arg.min = 0;
    s_arg.ast = 0;
	return (s_arg);
}

static int	f_check(const char *s_input, int pos, t_ftpf *s_arg, va_list ap)
{

	while (s_input[pos])
	{
		if (!ft_isdigit(s_input[pos]) && !is_valid_type(s_input[pos]) && !is_valid_flag(s_input[pos]))
			break;
		if (s_input[pos] == '0' && s_arg->width == 0 && s_arg->min == 0)
			s_arg->zero = 1;
		if (s_input[pos] == '.')
			pos = dot_handler(s_input, pos, s_arg, ap);
		if (s_input[pos] == '-')
			*s_arg = min_handler(*s_arg);
		if (s_input[pos] == '*')
			*s_arg = width_handler(*s_arg, ap);
		if (ft_isdigit(s_input[pos]))
			*s_arg = digit_handler(*s_arg, s_input[pos]);
		if (is_valid_type(s_input[pos]))
		{
			s_arg->type = s_input[pos];
			break;
		}
		pos++;
	}
	return (pos);
}

int	input_parser(const char *s_input, va_list ap)
{
	size_t	pos;
	size_t	r_width;
	t_ftpf	s_arg;

	pos = 0;
	r_width = 0;

	while (1)
	{
		s_arg = struct_init();

		if (!s_input[pos])
			break;
		else if (s_input[pos] == '%' && s_input[pos + 1])
		{
			pos = f_check(s_input, ++pos, &s_arg, ap);
			if (is_valid_type(s_input[pos]))
				r_width += s_build(s_arg, ap);
			else if (s_input[pos])
				r_width += ft_putchar(s_input[pos]);
		}
		else if (s_input[pos] != '%')
			r_width += ft_putchar(s_input[pos]);
		pos++;
	}
    return (r_width);
}