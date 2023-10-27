/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:36:59 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:20:27 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_excode;

static int	child_wait_ec(t_data *data)
{
	pid_t	wpid;
	int		e_code;
	int		status;

	fd_closer(data->cmd, false);
	status = 0;
	wpid = 0;
	while (wpid != -1 || errno != ECHILD)
	{
		wpid = waitpid(-1, &e_code, 0);
		if (wpid == data->pid)
			status = e_code;
		continue ;
	}
	if (WIFSIGNALED(status))
		e_code = 128 + WTERMSIG(status);
	else if (WIFEXITED(status))
		e_code = WEXITSTATUS(status);
	else
		e_code = status;
	return (e_code);
}

static int	child_maker(t_data *data)
{
	t_command	*cmd;

	cmd = data->cmd;
	while (data->pid != 0 && cmd)
	{
		data->pid = fork();
		if (data->pid == -1)
			return (cmd_error_msg("fork", NULL,
					strerror(errno), EXIT_FAILURE));
		else if (data->pid == 0)
			exec(data, cmd);
		cmd = cmd->next;
	}
	return (child_wait_ec(data));
}

static int	pipe_maker(t_data *data)
{
	if (!data || !data->cmd)
		return (EXIT_SUCCESS);
	if (!data->cmd->command)
	{
		if (data->cmd->io_fds && !io_check(data->cmd->io_fds))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (!pipe_builder(data))
		return (EXIT_FAILURE);
	return (CMD_NOT_FOUND);
}

int	exec_prep(t_data *data)
{
	int	idk;

	idk = pipe_maker(data);
	if (idk != CMD_NOT_FOUND)
		return (idk);
	if (!data->cmd->pipe_output && !data->cmd->prev
		&& io_check(data->cmd->io_fds))
	{
		io_redirect(data->cmd->io_fds);
		idk = bltin_exec(data, data->cmd);
		io_backup(data->cmd->io_fds);
	}
	if (idk != CMD_NOT_FOUND)
		return (idk);
	return (child_maker(data));
}
