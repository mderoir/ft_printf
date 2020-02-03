/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:46:54 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/28 16:01:38 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
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
		ft_putnbr(nombre / 10);
	ft_putchar(nombre % 10 + 48);
}
