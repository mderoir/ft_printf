/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:35:56 by bclerc            #+#    #+#             */
/*   Updated: 2020/02/03 13:38:06 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

t_ftpf	s_init(void)
{
	s_arg.pre = -1;
	s_arg.width = 0;
	s_arg.zero = 0;
	s_arg.minus = 0;
	s_arg.type = 0;

	return (s_arg);
}

t_ftpf	s_build(t_ftpf s_arg, const char *input, size_t pos)
{
	t_ftpf s_arg;

	s_arg = s_init();
	s_arg.flag = f_check(input, pos);
	s_arg.pre = get_pre(input, pos);
	s_arg.width = get_width(input, pos);
	s_arg.type = get_type(input, pos);

	return (s_arg);
}

int		input_width(const char *input, int pos)
{
	int	arg_w;

	arg_w = 0;
	while (!(is_conv(input[pos])))
	{
		pos++;
		arg_w++;
	}
	return (arg_w);
}
int	pf_parser(const char *input, va_list ap)
{
	size_t	pos;
	size_t	p_width;
	t_ftpf	s_arg;

	pos = 0;
	p_width = 0;
	while (input[pos])
	{
		if (input[pos] == '%')
		{
			s_arg = s_build(s_arg, input, pos);
			s_print(s_arg, ap);
			p_width = s_arg.width;
			pos += input_width(input, pos)
		}
		else
		{
			ft_putchar(input[pos]);
			pos++;
			p_width++;
		}
	}
	return (p_width);

}

int	ft_printf(const char *input, ...)
{
	int p_width;
	va_list	ap;

	va_start(ap, input);
	p_width = pf_parser(input, ap);	
	va_end(ap);
	return (p_width);
}

int	main()
{
	//unsigned int u = 1000;
	//int p = 1;
	char* str = "bonjour";
	ft_printf("yo\n", str);
	//printf("%.15d\n", str, u);
	return (0);
}
