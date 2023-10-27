/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:21:12 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:21:12 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	does_var_exist(t_data *data, char *var)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], var, len) == 0)
			return (0);
		i++;
	}
	return (1);
}

static char	*search_var_in_env(t_data *data, char *var)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(var);
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], var, len) == 0)
			break ;
		i++;
	}
	str = ft_strdup(data->env[i] + len);
	return (str);
}

char	*get_val(t_token *tok, char *str, t_data *data)
{
	char	*value;
	char	*var;

	var = what_var(str);
	if (var && does_var_exist(data, var) == 0)
	{
		if (tok != NULL)
			tok->var_exists = true;
		value = search_var_in_env(data, var);
	}
	else if (var && var[0] == '?' && var[1] == '=')
		value = ft_itoa(g_excode);
	else
		value = NULL;
	free_ptr(var);
	return (value);
}
