/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:31:51 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 11:31:53 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	int	unset_builtin(t_data *data, char **args)
*/
int	unset_builtin(t_data *data, char **args)
{
	int	i;
	int	idx;
	int	ret;

	ret = EXIT_SUCCESS;
	i = 1;
	while (args[i])
	{
		if (is_envvar_flag(args[i]) == -1 || ft_strchr(args[i], '=') != NULL)
		{
			cmd_error_msg("unset", args[i], "not a valid identifier", 0);
			ret = EXIT_FAILURE;
		}
		else
		{
			idx = envvar_index(data->env, args[i]);
			if (idx != -1)
				delete_var(data, idx);
		}
		i++;
	}
	return (ret);
}
