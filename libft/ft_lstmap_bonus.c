/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderoir <mderoir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:39:13 by mderoir           #+#    #+#             */
/*   Updated: 2019/11/06 17:19:36 by mderoir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *lst_tmp;

	if (!(lst || f))
		return (NULL);
	lst_tmp = ft_lstnew(f(lst->content));
	lst_tmp->next = ft_lstmap(lst->next, f, del);
	if (lst->content)
		del(lst->content);
	return (lst_tmp);
}
