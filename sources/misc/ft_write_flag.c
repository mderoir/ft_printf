#include "../includes/ft_printf.h"
#include <stdio.h>

int flag_null(char *f, va_list ap, char *len_arg, int i, int ret, int w_limit)
{
    int len;

    ret++;
	f++;
	if (*f == '*')
	{
		len = va_arg(ap, int) - w_limit + 1;
		ret++;
	}
	else
	{
		while (ft_isdigit(*f))
		{
			len_arg[i] = *f;
			i++;
			ret++;
			f++;
		}
		len = ft_atoi(len_arg) - w_limit + 1;
	}
	while (--len > 0)
		ft_putchar('0');
    return (ret);
}

int flag_star(va_list ap, int ret, int w_limit)
{
    int len;

    len = va_arg(ap, int) - w_limit + 1;
	ret++;
    while (--len > 0)
		ft_putchar(' ');
    return (ret);
}

int flag_width(char *f, char *len_arg, int i, int ret, int w_limit)
{
    int len;

    while (ft_isdigit(*f))
		{
			len_arg[i] = *f;
			i++;
			ret++;
			f++;
		}
	len = ft_atoi(len_arg) - w_limit + 1;
    while (--len > 0)
		ft_putchar(' ');
    return (ret);
}