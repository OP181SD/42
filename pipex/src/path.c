/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 22:24:27 by yasaidi           #+#    #+#             */
/*   Updated: 2023/06/12 22:25:18 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char	**get_path_array(char **envp)
{
	char	*paths;
	char	**path_array;

	if (envp == NULL)
		return (NULL);
	paths = get_path(envp);
	if (!paths)
		return (perror("No path found"), NULL);
	while (*paths != '=')
		paths++;
	paths++;
	path_array = ft_split(paths, ':');
	if (!path_array)
		return (perror("No path found"), NULL);
	return (path_array);
}
