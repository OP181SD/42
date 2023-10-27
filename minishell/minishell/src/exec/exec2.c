/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:43:55 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 11:43:55 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bltin_exec(t_data *data, t_command *cmd)
{
	int	bltin;

	bltin = CMD_NOT_FOUND;
	if (ft_strncmp(cmd->command, "cd", 3) == 0)
		bltin = cd_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->command, "echo", 5) == 0)
		bltin = echo_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->command, "env", 4) == 0)
		bltin = env_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->command, "export", 7) == 0)
		bltin = export_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->command, "pwd", 4) == 0)
		bltin = pwd_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->command, "unset", 6) == 0)
		bltin = unset_builtin(data, cmd->args);
	else if (ft_strncmp(cmd->command, "exit", 5) == 0)
		bltin = exit_builtin(data, cmd->args);
	return (bltin);
}

static int	execute_sys_bin(t_data *data, t_command *cmd)
{
	if (!cmd->command || cmd->command[0] == '\0')
		return (CMD_NOT_FOUND);
	if (cmd_is_dir(cmd->command))
		return (CMD_NOT_FOUND);
	cmd->path = get_cmd_path(data, cmd->command);
	if (!cmd->path)
		return (CMD_NOT_FOUND);
	if (execve(cmd->path, cmd->args, data->env) == -1)
	{
		ft_putendl_fd("error execve have failed in exec2", STDERR_FILENO);
		return (-1);
	}
	return (EXIT_FAILURE);
}

static int	execute_local_bin(t_data *data, t_command *cmd)
{
	int	ret;

	ret = why_cmd_not_found(data, cmd);
	if (ret != 0)
		return (ret);
	if (execve(cmd->command, cmd->args, data->env) == -1)
		return (cmd_error_msg("execve", NULL, strerror(errno), errno));
	return (EXIT_FAILURE);
}

int	exec(t_data *data, t_command *cmd)
{
	int	ret;

	if (!cmd || !cmd->command)
		exit_shell(data, cmd_error_msg("child", NULL,
				ERR_PARS_EXEC, EXIT_FAILURE));
	if (!io_check(cmd->io_fds))
		exit_shell(data, EXIT_FAILURE);
	fd_for_pipes(data->cmd, cmd);
	io_redirect(cmd->io_fds);
	fd_closer(data->cmd, false);
	if (ft_strchr(cmd->command, '/') == NULL)
	{
		ret = bltin_exec(data, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_shell(data, ret);
		ret = execute_sys_bin(data, cmd);
		if (ret != CMD_NOT_FOUND)
			exit_shell(data, ret);
	}
	ret = execute_local_bin(data, cmd);
	exit_shell(data, ret);
	return (ret);
}
