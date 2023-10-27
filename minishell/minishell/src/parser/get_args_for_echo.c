/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_for_echo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:57:49 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 11:57:49 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	alloc_args_echo(t_token **tok_lst, t_command *last_cmd)
{
	int		nb_args;
	t_token	*tmp;
	int		i;

	del_nonex_var(tok_lst);
	tmp = *tok_lst;
	nb_args = arg_count_echo(tmp);
	last_cmd->args = malloc(sizeof(char *) * (nb_args + 2));
	if (!last_cmd->args)
		return (-1);
	i = 0;
	last_cmd->args[i] = ft_strdup(last_cmd->command);
	i++;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		if (tmp->join == true)
			last_cmd->args[i] = var_join(&tmp);
		else
			last_cmd->args[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	last_cmd->args[i] = NULL;
	*tok_lst = tmp;
	return (0);
}

int	set_args_echo(t_token **tok_lst, t_command *last_cmd)
{
	int		len;
	int		nb_args;
	char	**tab;
	t_token	*tmp;

	del_nonex_var(tok_lst);
	tmp = *tok_lst;
	nb_args = arg_count_echo(tmp);
	len = 0;
	while (last_cmd->args[len])
		len++;
	tab = malloc(sizeof(char *) * (nb_args + len + 1));
	if (!tab)
		return (-1);
	tab = cpy_args_echo(len, tab, last_cmd, tmp);
	free(last_cmd->args);
	last_cmd->args = tab;
	while (tmp->type == WORD || tmp->type == VAR)
		tmp = tmp->next;
	*tok_lst = tmp;
	return (0);
}
