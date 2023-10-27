/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:28:01 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/28 14:01:47 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*first;

	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	first = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (!new_lst)
			return (ft_lstclear(&first, del), NULL);
		lst = lst->next;
		new_lst = new_lst->next;
	}
	return (first);
}
