/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:57:46 by yassine           #+#    #+#             */
/*   Updated: 2023/03/06 15:29:11 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

void	check_overlow(long result, t_stack **lst)
{
	if (result < INT_MIN || result > INT_MAX)
	{
		write(2, "Error\n", 7);
		free_stack(lst);
		exit(0);
	}
}

void	check_char(const char *str, int i, t_stack **lst)
{
	if (str[i])
	{
		write(2, "Error\n", 6);
		free_stack(lst);
		exit(0);
	}
}

int	ft_atoiplus(const char *str, t_stack **lst)
{
	int		i;
	int		neg;
	long	result;

	i = 0;
	neg = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		check_overlow(result * neg, lst);
		i++;
	}
	check_char(str, i, lst);
	return (result * neg);
}

t_stack	*pars_args(int argc, char **argv)
{
	t_stack	*lst;
	int		i;
	int		n;

	i = 1;
	lst = NULL;
	while (i < argc)
	{
		n = ft_atoiplus(argv[i], &lst);
		if (!lst_double(lst, n))
			lst = stack_a(lst, n);
		else
		{
			write(2, "Error\n", 7);
			free_stack(&lst);
			exit(0);
		}
		i++;
	}
	return (lst);
}
