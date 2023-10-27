/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:31:27 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 11:31:32 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
*	int	pwd_builtin(t_data *data, char **args)
*/
int	pwd_builtin(t_data *data, char **args)
{
	char	buf[4096];
	char	*cwd;

	(void)args;
	if (data->working_dir)
	{
		ft_putendl_fd(data->working_dir, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	cwd = getcwd(buf, 4096);
	if (cwd)
	{
		ft_putendl_fd(cwd, STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	cmd_error_msg("pwd", NULL, strerror(errno), errno);
	return (EXIT_FAILURE);
}
