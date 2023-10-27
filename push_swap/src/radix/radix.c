/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:57:32 by yassine           #+#    #+#             */
/*   Updated: 2023/03/06 14:11:07 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

int	get_max_bits(t_stack *lst)
{
	int	max_data;
	int	max_bits;

	max_data = get_max_data(lst);
	max_bits = 0;
	while (max_data > 0)
	{
		max_data >>= 1;
		max_bits++;
	}
	return (max_bits);
}

void	radix_sort_iteration(t_stack **lst_a, t_stack **lst_b, int i)
{
	int	j;
	int	size_a;

	j = 0;
	size_a = ft_lstsize(*lst_a);
	while (j < size_a)
	{
		if (!is_sortix(*lst_a))
		{
			if (((*lst_a)->data >> i) & 1)
				do_ra(lst_a);
			else
				do_pb(lst_a, lst_b);
		}
		j++;
	}
}

void	radix_sort(t_stack **lst_a, t_stack **lst_b)
{
	int	max_bits;
	int	i;
	int	min_val;

	min_val = get_min_data(*lst_a);
	if (min_val < 0)
		translate_values(lst_a, -min_val);
	max_bits = get_max_bits(*lst_a);
	i = 0;
	while (i < max_bits)
	{
		radix_sort_iteration(lst_a, lst_b, i);
		while (*lst_b)
			do_pa(lst_b, lst_a);
		i++;
	}
	if (min_val < 0)
		translate_values(lst_a, min_val);
}
