/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:50:57 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/03 23:49:20 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->content);
	}
	free(lst);
}
