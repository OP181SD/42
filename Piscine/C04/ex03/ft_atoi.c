/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:17:26 by yasaidi           #+#    #+#             */
/*   Updated: 2022/09/21 16:17:31 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_ispace(char c)
{
	if ((c >= '\t' && c <= '\r') || (c == ' '))
		return (1);
	return (0);
}

int	is_pos_or_neg(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	while (ft_ispace(str[i]))
			i++;
	neg = 1;
	while (is_pos_or_neg(str[i]))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	result = 0;
	while (is_numeric(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * neg);
}
