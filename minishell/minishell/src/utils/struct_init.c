/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:05:51 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 19:05:51 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	dir_workaround(t_data *data)
{
	char	buffer[4096];
	char	*dir;

	dir = getcwd(buffer, 4096);
	data->working_dir = ft_strdup(dir);
	if (!data->working_dir)
		return (-1);
	if (envvar_index(data->env, "OLDPWD") != -1)
	{
		data->old_working_dir = ft_strdup(envvar_value(data->env, "OLDPWD"));
		if (!data->old_working_dir)
			return (-1);
	}
	else
	{
		data->old_working_dir = ft_strdup(dir);
		if (!data->old_working_dir)
			return (-1);
	}
	return (0);
}

static int	env_init(t_data *data, char **env)
{
	int	i;

	data->env = ft_calloc(count_env(env) + 1, sizeof * data->env);
	if (!data->env)
		return (-1);
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		if (!data->env[i])
			return (-1);
		i++;
	}
	return (0);
}

int	datastruct_init(t_data *data, char **env)
{
	if (env_init(data, env) != 0)
	{
		cmd_error_msg("Error", NULL, "Env wasn't initialized", 1);
		return (-1);
	}
	if (dir_workaround(data) != 0)
	{
		cmd_error_msg("Error", NULL, "No Directory data", 1);
		return (-1);
	}
	data->token = NULL;
	data->cmd = NULL;
	data->input = NULL;
	data->pid = -1;
	g_excode = 0;
	return (0);
}

void	io_init(t_command *cmd)
{
	if (!cmd->io_fds)
	{
		cmd->io_fds = malloc(sizeof * cmd->io_fds);
		if (!cmd->io_fds)
			return ;
		cmd->io_fds->infile = NULL;
		cmd->io_fds->outfile = NULL;
		cmd->io_fds->heredoc_delim = NULL;
		cmd->io_fds->herequotes = false;
		cmd->io_fds->fd_in = -1;
		cmd->io_fds->fd_out = -1;
		cmd->io_fds->stdin_backup = -1;
		cmd->io_fds->stdout_backup = -1;
	}
}
