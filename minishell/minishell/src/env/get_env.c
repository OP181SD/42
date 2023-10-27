/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:56:23 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 11:56:29 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
* 	char	*envvar_value(char **env, char *var)
*/
char	*envvar_value(char **env, char *var)
{
	int		i;
	char	*tmpstr;

	tmpstr = ft_strjoin(var, "=");
	if (!tmpstr)
		return (NULL);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(tmpstr, env[i], ft_strlen(tmpstr)) == 0)
		{
			free_ptr(tmpstr);
			return (ft_strchr(env[i], '=') + 1);
		}
		i++;
	}
	free_ptr(tmpstr);
	return (NULL);
}

/*
*	int	envvar_index(char **env, char *var)
*/
int	envvar_index(char **env, char *var)
{
	int		i;
	char	*tmpstr;

	tmpstr = ft_strjoin(var, "=");
	if (!tmpstr)
		return (-1);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(tmpstr, env[i], ft_strlen(tmpstr)) == 0)
		{
			free_ptr(tmpstr);
			return (i);
		}
		i++;
	}
	free_ptr(tmpstr);
	return (-1);
}

/*
*	int	count_env(char **env)
*/
int	count_env(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
		i++;
	return (i);
}

/*
*	int	is_envvar_flag(char *var)
*/
int	is_envvar_flag(char *var)
{
	int	i;

	i = 0;
	if (ft_isalpha(var[i]) == 0 && var[i] != '_')
		return (-1);
	i++;
	while (var[i] && var[i] != '=')
	{
		if (ft_isalnum(var[i]) == 0 && var[i] != '_')
			return (-1);
		i++;
	}
	return (0);
}
