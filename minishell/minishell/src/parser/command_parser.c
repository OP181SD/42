/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:58:33 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 11:58:33 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	cmd_no_arg(t_data *data)
{
	t_command	*cmd;

	if (!data || !data->cmd)
		return ;
	cmd = data->cmd;
	while (cmd && cmd->command)
	{
		if (!cmd->args)
		{
			cmd->args = malloc(sizeof * cmd->args * 2);
			cmd->args[0] = ft_strdup(cmd->command);
			cmd->args[1] = NULL;
		}
		cmd = cmd->next;
	}
	cmd = get_last_cmd(data->cmd);
}

void	cmd_parser(t_data *data, t_token *token)
{
	t_token	*tmp;

	tmp = token;
	if (tmp->type == END)
		return ;
	while (tmp->next != NULL)
	{
		if (tmp == token)
			addback_cmd(&data->cmd, new_node_cmd(0));
		if (tmp->type == WORD || tmp->type == VAR)
			parse_word(&data->cmd, &tmp);
		else if (tmp->type == INPUT)
			parse_input(&data->cmd, &tmp);
		else if (tmp->type == APPEND)
			parse_append(&data->cmd, &tmp);
		else if (tmp->type == TRUNC)
			parse_trunc(&data->cmd, &tmp);
		else if (tmp->type == HEREDOC)
			parse_heredoc(data, &data->cmd, &tmp);
		else if (tmp->type == PIPE)
			parse_pipe(&data->cmd, &tmp);
		else if (tmp->type == END)
			break ;
	}
	cmd_no_arg(data);
}
