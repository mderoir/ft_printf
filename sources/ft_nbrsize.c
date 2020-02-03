/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:51:27 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/28 17:32:27 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_nbrsize(unsigned int nb, int size) //resizing nbr in function of width for printf
{
    ft_putnbr(nb / ft_pow(10, size));
}