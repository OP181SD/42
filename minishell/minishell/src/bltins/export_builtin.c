/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:31:08 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:05:34 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_key_value_pair(char *arg)
{
	char	**tmp;
	char	*equal;

	equal = ft_strchr(arg, '=');
	tmp = malloc(sizeof * tmp * (2 + 1));
	tmp[0] = ft_substr(arg, 0, equal - arg);
	tmp[1] = ft_substr(equal, 1, ft_strlen(equal));
	tmp[2] = NULL;
	return (tmp);
}

/*
*	int	export_builtin(t_data *data, char **args)
*/
int	export_builtin(t_data *data, char **args)
{
	int		i;
	char	**tmp;
	int		ret;

	ret = EXIT_SUCCESS;
	i = 1;
	if (!args[i])
		return (env_builtin(data, NULL));
	while (args[i])
	{
		if (is_envvar_flag(args[i]) == -1)
		{
			cmd_error_msg("export", args[i], "not a valid identifier", 0);
			ret = EXIT_FAILURE;
		}
		else if (ft_strchr(args[i], '=') != NULL)
		{
			tmp = get_key_value_pair(args[i]);
			set_var(data, tmp[0], tmp[1]);
			free_tabs(tmp);
		}
		i++;
	}
	return (ret);
}
