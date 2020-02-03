/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:26:04 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/11 17:37:33 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *list;

	if (!*lst)
		return ;
	list = *lst;
	if (list->next)
		ft_lstclear(&list->next, del);
	ft_lstdelone(list, del);
	free(*lst);
}
