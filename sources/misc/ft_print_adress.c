/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:51:59 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/28 17:55:06 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_adress(intptr_t adress) //to use cast pointer into int>Exemple = "ft_print_adress((intptr_t)ptr);"
{
	const char base[] = "0123456789abcdef";
	const int nbase = 16;
	if (adress < nbase)
		ft_putstr("0x");
	if (adress >= nbase)
		ft_print_adress(adress / nbase);
    ft_putchar(base[adress % nbase]);
}