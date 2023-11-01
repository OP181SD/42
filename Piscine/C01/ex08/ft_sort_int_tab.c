/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:06:55 by yasaidi           #+#    #+#             */
/*   Updated: 2023/02/02 20:46:10 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *tab, int i)
{
	int	tmp;

	tmp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	size--;
	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(tab, i);
			i = 0;
		}
		else
			i++;
	}
}
