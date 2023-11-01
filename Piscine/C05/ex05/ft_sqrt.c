/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:46:53 by yasaidi           #+#    #+#             */
/*   Updated: 2022/09/25 15:46:55 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	square;

	square = 1;
	while (square * square < nb && square < 47000)
	{
		square++;
	}
	if (square * square == nb)
		return (square);
	return (0);
}
