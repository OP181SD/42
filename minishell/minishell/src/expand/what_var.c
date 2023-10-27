/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:23:28 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:23:28 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	var_syntax(char c)
{
	if (ft_isalnum(c) == 0 && c != '_')
		return (-1);
	else
		return (0);
}

int	var_len(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	if (str[i] == '$')
	{
		i++;
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '?')
			return (count + 1);
		while (str[i])
		{
			if (var_syntax(str[i]) == -1)
				break ;
			count++;
			i++;
		}
		return (count);
	}
	else
		return (-1);
	return (0);
}

char	*what_var(char *str)
{
	char	*var;
	char	*tmp;
	int		start;
	int		len;
	int		i;

	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			start = i + 1;
			break ;
		}
		i++;
	}
	len = var_len(str);
	var = ft_substr(str, start, len);
	if (!var)
		return (NULL);
	tmp = ft_strjoin(var, "=");
	free_ptr(var);
	var = tmp;
	return (var);
}
