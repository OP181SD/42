/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:48:46 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/03 23:49:47 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "ft_printf.h"
#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (lst != NULL)
	{
		ft_lstlast(*lst)->next = new;
		new->next = NULL;
	}
	else
		(*lst) = new;
}
