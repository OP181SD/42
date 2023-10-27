/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:58:20 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 11:58:20 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (true);
		i++;
	}
	return (false);
}

static void	get_cmd_token(t_command *last_cmd, char *cmd_str)
{
	t_token		*new_node;
	t_token		*tmp;
	char		**tab;
	int			i;

	new_node = NULL;
	tab = ft_split(cmd_str, ' ');
	if (!tab)
		return ;
	last_cmd->command = ft_strdup(tab[0]);
	if (tab[1])
		new_node = new_node_list(ft_strdup(tab[1]), NULL, WORD, DEFAULT);
	tmp = new_node;
	i = 1;
	while (tab[++i])
		addback_node(&new_node,
			new_node_list(ft_strdup(tab[i]), NULL, WORD, DEFAULT));
	addback_node(&new_node,
		new_node_list(NULL, NULL, END, DEFAULT));
	get_args(&new_node, last_cmd);
	list_wipe(&tmp, &free_ptr);
	free_tabs(tab);
}

void	parse_word(t_command **cmd, t_token **tok_lst)
{
	t_token		*tmp;
	t_command	*last_cmd;

	tmp = *tok_lst;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		last_cmd = get_last_cmd(*cmd);
		if (tmp->prev == NULL || (tmp->prev && tmp->prev->type == PIPE)
			|| last_cmd->command == NULL)
		{
			if (tmp->type == VAR && has_space(tmp->str))
				get_cmd_token(last_cmd, tmp->str);
			else
				last_cmd->command = ft_strdup(tmp->str);
			tmp = tmp->next;
		}
		else
			get_args(&tmp, last_cmd);
	}
	*tok_lst = tmp;
}
