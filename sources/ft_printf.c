/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:35:56 by bclerc            #+#    #+#             */
/*   Updated: 2020/03/04 15:53:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int		input_width(const char *input, int pos)
{
	int	arg_w;

	arg_w = 0;
	while (!(is_valid_type(input[pos])) && input[pos])
	{
		pos++;
		arg_w++;
	}
	return (++arg_w);
}

void	s_print(t_ftpf s_arg, va_list ap)
{
	 printf("TYPE : %c\n", s_arg.type);
	 printf("FLAG : %c\n", s_arg.flag);
	 printf("WIDTH : %d\n", s_arg.width);
	 printf("PRE : %d\n", s_arg.pre);
	if (s_arg.type == 'c')
		ft_printchar(s_arg);
	if (s_arg.type == 's')
		ft_printstring(s_arg);
	// if (s_arg.type == 'd')
	// 	ft_printstring(s_arg, ap);
	// if (s_arg.type == 'i')
	// 	ft_printstring(s_arg, ap);
	// if (s_arg.type == 'u')
	// 	ft_printstring(s_arg, ap);
	// if (s_arg.type == 'x')
	// 	ft_printstring(s_arg, ap);
	// if (s_arg.type == 'X')
	// 	ft_printstring(s_arg, ap);
	// if (s_arg.type == 'p')
	// 	ft_printstring(s_arg, ap);
}

int	input_parser(const char *input, va_list ap)
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
			s_arg = s_build(s_arg, input, pos, ap);
			s_print(s_arg, ap);
			p_width += s_arg.width + s_arg.len;
			pos += input_width(input, pos);
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
	p_width = input_parser(input, ap);	
	va_end(ap);
	printf("RET VALUE : %d\n\n", p_width);
	return (p_width);
}

int	main()
{
	int ret;
	char *str = "Chaton des booooois";
	ft_printf("PRINTF : %c\n%s\n%s\n", 'o', str, "Woooooooh");
	ret = printf("PRINTF : %c\n%s\n%s\n", 'o', str, "Woooooooh");
	printf("RET VALUE : %d\n\n", ret);
	

	return (0);
}
 