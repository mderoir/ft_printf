/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:50:42 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/28 17:55:04 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_hex(int nb, char c) //either x or X for ft_printf
{
	unsigned int nombre;
	const char base_up[] = "0123456789ABCDEF";
	const char base_low[] = "0123456789abcdef";
	const int nbase = 16;

	if (nb < 0)
	{
		nombre = -nb;
		ft_putchar('-');
	}
	else
		nombre = nb;
	if (nombre >= nbase)
		ft_putnbr_hex(nombre / nbase, c);
    ft_isupper(c) ? ft_putchar(base_up[nombre % nbase]) : ft_putchar(base_low[nombre % nbase]);
}