/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_fcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:18:30 by marvin            #+#    #+#             */
/*   Updated: 2020/03/04 15:18:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	while (str[i])
		i++;
	return (i);
}

int	ft_intlen_base(int value, int base)
{
	int		len;

	len = 0;
	if (value < 0)
		len++;
	while (value)
	{
		len++;
		value /= base;
	}
	return (len);
}

char		*ft_strrev(char *str)
{
	int		i;
	int		l;
	char	t;

	l = 0;
	while (str[l] != '\0')
		l++;
	i = -1;
	while (++i < --l)
	{
		t = str[i];
		str[i] = str[l];
		str[l] = t;
	}
	return (str);
}

void	ft_putstr(char *str)
{
	int i;

    i = -1;
    while (str[++i])
        ft_putchar(str[i]);
}

int		is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	if (!(dst = malloc(total)))
		return (NULL);
	i = 0;
	while (total--)
	{
		dst[i] = 0;
		i++;
	}
    dst[i] = 0;
	return ((void *)dst);
}


char		*ft_itoa(int n)
{
	char	*buf;
	int		j;

	buf = ft_calloc(ft_intlen_base(n, 10) + 1, 1);
	j = ft_intlen_base(n, 10) - 1;
	if (buf)
	{
		if (n < 0)
		{
			buf[0] = '-';
			n *= -1;
		}
		if (n == 0)
			*buf = '0';
		while (n > 0)
		{
			buf[j] = '0' + (n % 10);
			n /= 10;
			j--;
		}
	}
	return (buf);
}

char	*ft_itoa_hex(int n, int uppercase)
{
	char	*str;
	int		i;
	int		length;

	length = ft_intlen_base(n, 16);
	str = (char*)malloc(sizeof(*str) * (length + 1));
	i = 0;
	while (i < length)
	{
		if (uppercase && n % 16 >= 10)
			str[i++] = (n % 16) - 10 + 'A';
		else if (n % 16 >= 10)
			str[i++] = (n % 16) - 10 + 'a';
        else
			str[i++] = (n % 16) + '0';
		n /= 16;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

char	*ft_ptr_adress(intptr_t adress)
{
    char *str;
    int i;
    int length;

    length = 12;
    str = (char*)malloc(sizeof(*str) * (length + 3));
    i = 0;
    while (i < length)
	{
		if (adress % 16 >= 10)
			str[i++] = (adress % 16) - 10 + 'a';
        else
			str[i++] = (adress % 16) + '0';
		adress /= 16;
	}
    str[i++] = 'x';
    str[i++] = '0';
    return (ft_strrev(str));
}