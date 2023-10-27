/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 07:40:22 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/06 15:59:30 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	is_sorted(t_stack **lst_a, t_stack **lst_b, int *tab)
{
	int	size;

	size = ft_lstsize(*lst_a);
	if (size == 2)
		is_sort_2(lst_a);
	else if (size == 3)
		is_sort_3(lst_a);
	else if (size >= 4 && size <= 5)
		is_sort_5(lst_a, lst_b, tab);
	else if (size > 5)
		radix_sort(lst_a, lst_b);
}

int	main(int argc, char **argv)
{
	t_stack	*lst_a;
	t_stack	*lst_b;
	int		*tab;

	lst_a = NULL;
	lst_b = NULL;
	tab = NULL;
	lst_a = pars_args(argc, argv);
	if (lst_a != NULL && !is_sortix(lst_a))
	{
		tab = ft_fill_sort_tab(lst_a);
		is_sorted(&lst_a, &lst_b, tab);
	}
	free_stack(&lst_a);
	free(tab);
	return (0);
}
