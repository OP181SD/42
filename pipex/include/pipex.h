/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:31:00 by yasaidi           #+#    #+#             */
/*   Updated: 2023/06/12 22:31:16 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define STDIN 0  // entree standard
# define STDOUT 1 // sortie standard
# define STDERR 2 // erreur standard

//ERROR MESSAGE
# define ERROR_ARGV "You need for 4 arguments"
# define INFILE	0
# define OUTFILE 1

# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"
# include <ctype.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	pid[2];
	int		id;
	char	*in_file;
	char	*out_file;
	int		fd_pipe[2];
	int		fd_infile;
	int		fd_outfile;
	char	**envp;
	char	*cmd1;
	char	*cmd2;
}	t_pipex;

// exec
void	exec(char *cmd, char **envp);
char	*get_path(char **envp);
char	**get_path_array(char **envp);
//child
void	child_infile(t_pipex *pipex);
void	child_outfile(t_pipex *pipex);
//utils
int		ft_putendl_fd(char *str, int fd);
void	ft_free(void **ptr);
void	ft_free_strs(char **strs);
#endif
