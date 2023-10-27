/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:24:14 by yasaidi           #+#    #+#             */
/*   Updated: 2023/06/12 22:24:17 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_infile(t_pipex *pipex)
{
	close(pipex->fd_pipe[0]);
	pipex->fd_infile = open(pipex->in_file, O_RDONLY);
	if (pipex->fd_infile == -1)
		return (close(pipex->fd_pipe[1]), \
				ft_putendl_fd("Error open", STDERR), exit(1));
	if (dup2(pipex->fd_infile, STDIN) == -1)
		return (close(pipex->fd_infile), close(pipex->fd_pipe[1]), \
				ft_putendl_fd("Error dup2", STDERR), exit(1));
	close(pipex->fd_infile);
	if (dup2(pipex->fd_pipe[1], STDOUT) == -1)
		return (close(pipex->fd_pipe[1]), \
				ft_putendl_fd("Error dup2", STDERR), exit(1));
	close(pipex->fd_pipe[1]);
	exec(pipex->cmd1, pipex->envp);
	exit(1);
}

void	child_outfile(t_pipex *pipex)
{
	close(pipex->fd_pipe[1]);
	if (dup2(pipex->fd_pipe[0], STDIN) == -1)
		return (close(pipex->fd_pipe[0]), ft_putendl_fd("Error dup2", STDERR), \
				exit(1));
	close(pipex->fd_pipe[0]);
	pipex->fd_outfile = \
			open(pipex->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_outfile == -1)
		return (ft_putendl_fd("Error open", STDERR), exit(1));
	if (dup2(pipex->fd_outfile, STDOUT) == -1)
		return (close(pipex->fd_outfile), \
				ft_putendl_fd("Error dup2", STDERR), exit(1));
	close(pipex->fd_outfile);
	exec(pipex->cmd2, pipex->envp);
	exit(1);
}
