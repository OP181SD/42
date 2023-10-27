/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:39:13 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:39:13 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	arg_count(t_token *tmp)
{
	int	i;

	i = 0;
	while (tmp && (tmp->type == WORD || tmp->type == VAR))
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

static int	alloc_args(t_token **tok_lst, t_command *last_cmd)
{
	int		i;
	int		nb_args;
	t_token	*tmp;

	i = 0;
	tmp = *tok_lst;
	nb_args = arg_count(tmp);
	last_cmd->args = malloc(sizeof(char *) * (nb_args + 2));
	if (!last_cmd->args)
		return (-1);
	tmp = *tok_lst;
	i = 0;
	last_cmd->args[i] = ft_strdup(last_cmd->command);
	i++;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		last_cmd->args[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	last_cmd->args[i] = NULL;
	*tok_lst = tmp;
	return (0);
}

static char	**cpy_args(int len, char **new_tab,
		t_command *last_cmd, t_token **tk_node)
{
	int		i;
	t_token	*tmp;

	i = 0;
	tmp = *tk_node;
	while (i < len)
	{
		new_tab[i] = last_cmd->args[i];
		i++;
	}
	while (tmp->type == WORD || tmp->type == VAR)
	{
		new_tab[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

static int	set_args(t_token **tok_lst, t_command *last_cmd)
{
	int		i;
	int		len;
	char	**new_tab;
	t_token	*tmp;

	i = 0;
	tmp = *tok_lst;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		i++;
		tmp = tmp->next;
	}
	len = 0;
	while (last_cmd->args[len])
		len++;
	new_tab = malloc(sizeof(char *) * (i + len + 1));
	if (!new_tab)
		return (-1);
	new_tab = cpy_args(len, new_tab, last_cmd, tok_lst);
	free(last_cmd->args);
	last_cmd->args = new_tab;
	*tok_lst = tmp;
	return (0);
}

int	get_args(t_token **tok_lst, t_command *last_cmd)
{
	if (!ft_strcmp(last_cmd->command, "echo"))
	{
		if (!(last_cmd->args))
			return (alloc_args_echo(tok_lst, last_cmd));
		else
			return (set_args_echo(tok_lst, last_cmd));
	}
	else
	{
		if (last_cmd && !(last_cmd->args))
			return (alloc_args(tok_lst, last_cmd));
		else
			return (set_args(tok_lst, last_cmd));
	}
	return (0);
}
