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

int 	is_flag(char f)
{
	if (f == '0' || f == '*' || f == '-' || f == '.')
		return (1);
	return(0);
}

int 	is_conv(char f)
{
	if (f == 'd' || f == 'i' || f == 'u' || f == 's'
		|| f == 'c' || f == 'p' || f == 'x' || f == 'X')
		return (1);
	return(0);
}

int		check_flag(char *f, va_list ap, int w_limit)
{
	int ret;
	int i;
	char len_arg[255];

	ret = 0;
	i = 0;
	if (*f == '0' || *f == '.')
		ret += flag_null(f, ap, len_arg, i, ret, w_limit);
	else if (*f == '*')
		ret += flag_star(ap, ret, w_limit);
	else
		ret += flag_width(f, len_arg, i, ret, w_limit);
	return(ret);
}

char	*convert_str(char *t, va_list ap, char *temp)
{
	int i;
 // POUR GERER LES TYPES DE FLAGS AVEC LES TYPES DE CONVERSIONS
 // POSSIBILITE D'AJOUTER UN FLAG QUI SPECIFIE DANS L'ENTREE DE
 // LA FONCTION CHECK FLAG S'IL S'AGIT DE CHIFFRES OU NON.   |
 // A IMPLEMENTER UNIQUEMENT DANS LA PREMIER CONDITION, LA	  |
 // VALEUR PAR DEFAUT ETANT 0.                                |
	i = 0;
	// PAR DEFAUT = ISCHIFFRE = 0

	while (!(is_conv(t[i])))
		i++;
	if (t[i] == 'd' || t[i] == 'i' || t[i] == 'u')
		temp = ft_itoa(va_arg(ap, int));
		// CHECK_FLAG(ISCHIFFRE = 1)
	else if (t[i] == 's')
		temp = ft_strdup(va_arg(ap, char*));
	//else if (t == 'c')
	//	temp = ft_putchar(va_arg(ap, int));
	//else if (t == 'p')
	//	temp = ft_print_adress(va_arg(ap, long long int));
	//else if (t == 'x' || t == 'X')
	//	temp = ft_putnbr_hex(va_arg(ap, long long int), t);

	// !! METTRE CHECK FLAG DANS CETTE FONCTION.
	// !! A LA FIN.
	if (temp)
		return (temp);
	else
		return (NULL);
}

int	ft_printf(const char *str, ...)
{
	int i;
	i = 0;
	char *temp;
	va_list	ap;
	va_start(ap, str);
	// CHECK ERROR EN DEBUT DE PROGRAMME OU DANS LA BOUCLE ?
	while (str[i])
	{
		if (str[i] == '%' && is_flag(str[i + 1] ))
		{
			temp = convert_str((char *)str, ap, temp);
			i += check_flag((char*)&str[i + 1], ap, ft_strlen(temp));
				if (*temp)
					ft_putstr(temp);
			i++;
		}
		else if (str[i] == '%' && ft_isdigit(str[i + 1]))
		{
			temp = convert_str((char *)str, ap, temp);
			i += check_flag((char*)&str[i + 1], ap, ft_strlen(temp));
				if (*temp)
					ft_putstr(temp);
			i++;
		}
		else if (str[i] == '%' && is_conv(str[i + 1]))
		{
			temp = convert_str((char *)str, ap, temp);
				if (*temp)
						ft_putstr(temp);
			i++;
		}
		else if (str[i] == '\n')
			ft_putchar('\n');
		else
			ft_putchar(str[i]);
		i++;
	// QUAND FREE ?
	}
	va_end(ap);
	return (0);
}

int	main()
{
	//unsigned int u = 1000;
	//int p = 1;
	char* str = "bonjour";
	ft_printf("%s\n", str);
	//printf("%.15d\n", str, u);
	return (0);
}