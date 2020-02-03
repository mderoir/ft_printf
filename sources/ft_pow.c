/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 19:08:48 by mderoir           #+#    #+#             */
/*   Updated: 2020/01/21 16:50:53 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

ft_pow(int nb, int exponent)
{
    if (exponent == 0)
        return (1);
    if (exponent > 0)
        ft_power(nb = nb * nb, exponent--));
    return (nb);   
}