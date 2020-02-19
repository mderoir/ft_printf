/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:47:53 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/28 17:32:24 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_putlnbr(int n)
{
	unsigned int nombre;

	if (n < 0)
	{
		nombre = -n;
		ft_putchar('-');
	}
	else
		nombre = n;
	if (nombre >= 10)
		ft_putlnbr(nombre / 10);
	ft_putchar(nombre % 10 + 48);
}
