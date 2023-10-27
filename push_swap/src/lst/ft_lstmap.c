/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:04:27 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/03 23:51:01 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "ft_printf.h"
#include "libft.h"

t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *))
{
	t_stack	*new_lst;
	t_stack	*first;

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
