/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:01:38 by yasaidi           #+#    #+#             */
/*   Updated: 2022/11/21 14:56:58 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	itoa_len(long nb_div)
{
	int		len;

	if (nb_div == 0)
		return (1);
	len = 0;
	if (nb_div < 0)
	{
		nb_div *= -1;
		len++;
	}
	while (nb_div > 0)
	{
		nb_div = nb_div / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	n_long;

	n_long = n;
	i = itoa_len(n_long);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (0);
	str[i--] = '\0';
	if (n_long < 0)
	{
		str[0] = '-';
		n_long *= -1;
	}
	if (n_long == 0)
		str[0] = '0';
	while (i >= 0 && n_long > 0)
	{
		str[i--] = (n_long % 10) + 48;
		n_long = n_long / 10;
	}
	return (str);
}
