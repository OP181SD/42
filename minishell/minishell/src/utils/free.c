/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:06:46 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 19:06:48 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tabs(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free_ptr(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_datastruct(t_data *data, int flag_histclear)
{
	if (data && data->input)
	{
		free_ptr(data->input);
		data->input = NULL;
	}
	if (data && data->token)
		list_wipe(&data->token, &free_ptr);
	if (data && data->cmd)
		wipe_cmd(&data->cmd, &free_ptr);
	if (flag_histclear == 1)
	{
		if (data && data->working_dir)
			free_ptr(data->working_dir);
		if (data && data->old_working_dir)
			free_ptr(data->old_working_dir);
		if (data && data->env)
			free_tabs(data->env);
		rl_clear_history();
	}
}

void	free_io(t_io_fds *io)
{
	if (!io)
		return ;
	io_backup(io);
	if (io->heredoc_delim)
	{
		unlink(io->infile);
		free_ptr(io->heredoc_delim);
	}
	if (io->infile)
		free_ptr(io->infile);
	if (io->outfile)
		free_ptr(io->outfile);
	if (io)
		free_ptr(io);
}
