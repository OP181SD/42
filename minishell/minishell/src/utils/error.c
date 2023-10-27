/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:04:42 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 19:08:50 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*err_join(char *str, char *add)
{
	char	*tmp;

	if (!add)
		return (str);
	if (!str)
		return (ft_strdup(add));
	tmp = str;
	str = ft_strjoin(tmp, add);
	free_ptr(tmp);
	return (str);
}

static bool	err_quotes_check(char *cmd)
{
	if (ft_strncmp(cmd, "export", 7) == 0
		|| ft_strncmp(cmd, "unset", 6) == 0)
		return (true);
	return (false);
}

int	cmd_error_msg(char *cmd, char *detail, char *error_msg, int excode)
{
	char	*msg;
	bool	quotes;

	quotes = err_quotes_check(cmd);
	msg = ft_strdup("minishell: ");
	if (cmd != NULL)
	{
		msg = err_join(msg, cmd);
		msg = err_join(msg, ": ");
	}
	if (detail != NULL)
	{
		if (quotes)
			msg = err_join(msg, "`");
		msg = err_join(msg, detail);
		if (quotes)
			msg = err_join(msg, "'");
		msg = err_join(msg, ": ");
	}
	msg = err_join(msg, error_msg);
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
	return (excode);
}

void	gen_err_msg(char *errmsg, char *detail, int quotes)
{
	char	*msg;

	msg = ft_strdup("minishell: ");
	msg = err_join(msg, errmsg);
	if (quotes)
		msg = err_join(msg, " `");
	else
		msg = err_join(msg, ": ");
	msg = err_join(msg, detail);
	if (quotes)
		msg = err_join(msg, "'");
	ft_putendl_fd(msg, STDERR_FILENO);
	free_ptr(msg);
}
