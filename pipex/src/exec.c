/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhlel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:13:35 by yassine           #+#    #+#             */
/*   Updated: 2023/06/12 22:21:22 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_access(char **path_array, char *cmd)
{
	int		i;
	char	*tmp;
	char	*cmd_with_path;

	tmp = NULL;
	cmd_with_path = NULL;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	i = 0;
	while (path_array[i])
	{
		tmp = ft_strjoin(path_array[i], "/");
		if (!tmp)
			return (NULL);
		cmd_with_path = ft_strjoin(tmp, cmd);
		if (!cmd_with_path)
			return (free(tmp), NULL);
		ft_free((void **)&tmp);
		if (access(cmd_with_path, F_OK) == 0)
			return (free(tmp), cmd_with_path);
		ft_free((void **)&cmd_with_path);
		i++;
	}
	return (NULL);
}

void	exec(char *cmd, char **envp)
{
	char	**path_array;
	char	**cmd_split;

	path_array = get_path_array(envp);
	if (!path_array)
		return (exit(1));
	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		return (ft_free_strs(path_array), exit(1));
	cmd = ft_access(path_array, cmd_split[0]);
	if (!cmd)
		return (ft_free_strs(path_array), ft_free_strs(cmd_split), exit(1));
	ft_free_strs(path_array);
	if (execve(cmd, cmd_split, envp) == -1)
		return (ft_free_strs(cmd_split), \
		ft_putendl_fd("Error execve", STDERR), exit(1));
}
