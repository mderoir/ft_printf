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

int		is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

t_ftpf	s_init(void)
{
	t_ftpf s_arg;

	s_arg.pre = -1;
	s_arg.width = 0;
	s_arg.flag = 0;
	s_arg.type = 0;

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
	else if (input[pos] == ' ')	
		return (F_SPACE);
	else if (is_valid_type(input[pos]))	
		return (F_TYPE);
	return (0);
}

int get_pre(const char *input, int pos, va_list ap)
{
	int pre;
	
	pre = 0;
	while (!(is_digit(input[pos]) || input[pos] == '*'))
		pos++;
	input[pos] == '*' ? pre = va_arg(ap, int) : 0;
	while (is_digit(input[pos]))
		pre = pre * 10 + input[pos++] - '0';
	return (pre);
}

int	get_width(const char *input, int pos, va_list ap)
{
	int width;

	width = 0;
	while (!(is_digit(input[pos]) || input[pos] == '*'))
		pos++;
	input[pos] == '*' ? width = va_arg(ap, int) : 0;
	while (is_digit(input[pos]))
		width = width * 10 + input[pos++] - '0';
	return (width);
}

char get_type(const char *input, int pos)
{
	while (!(is_valid_type(input[pos])))
		pos++;
	return (input[pos]);
}

t_ftpf	s_build(t_ftpf s_arg, const char *input, size_t pos, va_list ap)
{

	s_arg = s_init();
	s_arg.flag = f_check(input, pos);
	s_arg.width = get_width(input, pos, ap);
	if (s_arg.flag == F_PREC)
		s_arg.pre = get_pre(input, pos, ap);
	s_arg.type = get_type(input, pos);
	return (s_arg);
}

int		input_width(const char *input, int pos)
{
	int	arg_w;

	arg_w = 0;
	while (!(is_valid_type(input[pos])))
	{
		pos++;
		arg_w++;
	}
	return (++arg_w);
}

void	s_print(t_ftpf s_arg, va_list ap)
{
	printf("%s\n", "coucou mon chaton");
	printf("TYPE : %c\n", s_arg.type);
	printf("FLAG : %c\n", s_arg.flag);
	printf("WIDTH : %d\n", s_arg.width);
	printf("PRE : %d\n", s_arg.pre);
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
			p_width += s_arg.width;
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
	return (p_width);
}

int	main()
{
	ft_printf("%.12d%012d\n");
	//printf("%.15d\n");
	return (0);
}
 