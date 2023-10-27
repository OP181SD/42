/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:24:22 by yasaidi           #+#    #+#             */
/*   Updated: 2023/06/12 22:24:24 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_pipex	pipex;

	ft_bzero(&pipex, sizeof(t_pipex));
	if (argc < 4)
		return (ft_putendl_fd(ERROR_ARGV, STDERR), EXIT_FAILURE);
	pipex.in_file = argv[1];
	pipex.cmd1 = argv[2];
	pipex.cmd2 = argv[3];
	pipex.out_file = argv[4];
	pipex.envp = envp;
	if (pipe(pipex.fd_pipe) == -1)
		return (EXIT_FAILURE);
	pipex.id = -1;
	while (++pipex.id < 2)
	{
		pipex.pid[pipex.id] = fork();
		if (pipex.id == 0 && pipex.pid[pipex.id] == 0)
			child_infile(&pipex);
		else if (pipex.id == 1 && pipex.pid[pipex.id] == 0)
			child_outfile(&pipex);
	}
	close(pipex.fd_pipe[0]);
	close(pipex.fd_pipe[1]);
	return (waitpid(pipex.pid[0], NULL, 0), \
			waitpid(pipex.pid[1], NULL, 0), EXIT_SUCCESS);
}
