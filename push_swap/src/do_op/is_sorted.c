/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:02:22 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/06 12:18:26 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	is_sort_2(t_stack **lst)
{
	if ((*lst)->data > (*lst)->next->data)
		do_sa(lst, "sa\n");
}

void	is_sort_3(t_stack **lst)
{
	if ((*lst)->data > (*lst)->next->data)
		do_sa(lst, "sa\n");
	if ((*lst)->next->data > (*lst)->next->next->data)
		do_rra(lst);
	if ((*lst)->data > (*lst)->next->data)
		do_sa(lst, "sa\n");
}

void	is_sort_5(t_stack **lst_a, t_stack **lst_b, int *tab)
{
	int	size;

	size = ft_lstsize(*lst_a);
	while (size > 3)
	{
		if ((*lst_a)->data == tab[0] || (*lst_a)->data == tab[1])
		{
			do_pb(lst_a, lst_b);
				size--;
		}
		else
			do_ra(lst_a);
	}
	is_sort_3(lst_a);
	if (ft_lstsize(*lst_b) > 1)
	{
		if ((*lst_b)->data < (*lst_b)->next->data)
			do_sb(lst_b, "sb\n");
	}
	while (ft_lstsize(*lst_b) != 0)
		do_pa(lst_b, lst_a);
	is_sort_2(lst_a);
}
