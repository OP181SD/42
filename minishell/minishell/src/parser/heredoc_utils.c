/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:02:10 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 12:02:10 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*tabs_to_str(char **tab)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	while (tab[++i])
	{
		tmp = str;
		if (i == 0)
			str = ft_strdup(tab[0]);
		else
		{
			str = ft_strjoin(tmp, tab[i]);
			free_ptr(tmp);
		}
		if (tab[i + 1])
		{
			tmp = str;
			str = ft_strjoin(tmp, " ");
			free_ptr(tmp);
		}
	}
	free_tabs(tab);
	return (str);
}

static char	*multivar_expand(t_data *data, char *line)
{
	char	**words;
	int		i;

	words = ft_split(line, ' ');
	if (!words)
		return (NULL);
	i = 0;
	while (words[i])
	{
		if (ft_strchr(words[i], '$'))
		{
			words[i] = expand_var_heredoc(data, words[i]);
			if (!words[i])
				return (NULL);
		}
		i++;
	}
	return (tabs_to_str(words));
}

static bool	write_line_or_not(t_data *data, char **line, t_io_fds *io,
		bool *ret)
{
	if (*line == NULL)
	{
		cmd_error_msg("warning", ERROR_HEREDOC_DELIM, io->heredoc_delim, true);
		*ret = true;
		return (false);
	}
	if (ft_strcmp(*line, io->heredoc_delim) == 0)
	{
		*ret = true;
		return (false);
	}
	if (io->herequotes == false && ft_strchr(*line, '$'))
	{
		*line = multivar_expand(data, *line);
		if (!(*line))
		{
			free_ptr(*line);
			*ret = false;
			return (false);
		}
	}
	return (true);
}

bool	fill_heredoc(t_data *data, t_io_fds *io, int fd)
{
	char	*line;
	bool	ret;

	ret = false;
	line = NULL;
	while (1)
	{
		base_minishell_sig();
		line = readline(">");
		cmd_in_shell_sig();
		if (!write_line_or_not(data, &line, io, &ret))
			break ;
		ft_putendl_fd(line, fd);
		free_ptr(line);
	}
	free_ptr(line);
	return (ret);
}
