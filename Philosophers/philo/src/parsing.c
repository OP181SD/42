/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:34:25 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/13 21:41:04 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_overflow(long result)
{
	if ((result < INT_MIN) || (result > INT_MAX))
	{
		write(1, "overflow\n", 10);
		return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return (result);
}

static int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

static int	only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_digit(str[i]) || str[0] == '0')
		{
			write(2, "arguments invalides", 20);
			return (1);
		}
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (only_digit(argv[i]))
			return (-1);
		i++;
	}
	return (0);
}
