/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:07:35 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 12:07:35 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_pipe(t_command **cmd, t_token **tok_lst)
{
	t_command	*last_cmd;

	last_cmd = get_last_cmd(*cmd);
	last_cmd->pipe_output = true;
	addback_cmd(&last_cmd, new_node_cmd(false));
	*tok_lst = (*tok_lst)->next;
}
