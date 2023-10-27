/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:19:38 by yassine           #+#    #+#             */
/*   Updated: 2023/03/06 14:31:21 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	is_sortix(t_stack *lst)
{
	while (lst && lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	get_max_data(t_stack *lst)
{
	int		max;
	t_stack	*tmp;

	max = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min_data(t_stack *lst)
{
	int	min;

	min = lst->data;
	while (lst != NULL)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

void	translate_values(t_stack **lst, int value)
{
	t_stack	*curr;

	curr = *lst;
	while (curr != NULL)
	{
		curr->data += value;
		curr = curr->next;
	}
}
