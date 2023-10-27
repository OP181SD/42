/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:12:12 by yasaidi           #+#    #+#             */
/*   Updated: 2023/03/04 19:55:50 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	if (tab == 0 || size <= 0)
		return ;
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void	min_max_tab(int *tab, int size, int *min, int *max)
{
	int	i;

	i = 0;
	*min = tab[i];
	*max = tab[i];
	while (i < size)
	{
		if (tab[i] < *min)
			*min = tab[i];
		else if (tab[i] > *max)
			*max = tab[i];
		i++;
	}
}

int	*ft_fill_sort_tab(t_stack *lst)
{
	int	i;
	int	size;
	int	*tab;

	size = ft_lstsize(lst);
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = lst->data;
		lst = lst->next;
		i++;
	}
	ft_sort_int_tab(tab, size);
	return (tab);
}
