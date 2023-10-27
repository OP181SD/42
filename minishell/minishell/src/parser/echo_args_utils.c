/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_args_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 12:00:30 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/14 12:00:30 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_join(t_token **token_node)
{
	t_token		*tmp;
	char		*str;

	tmp = *token_node;
	str = ft_strdup(tmp->str);
	while (tmp->type == VAR && tmp->next->type == VAR
		&& tmp->next->join == true)
	{
		str = ft_strjoin(str, tmp->next->str);
		tmp = tmp->next;
	}
	*token_node = tmp;
	return (str);
}

int	arg_count_echo(t_token *tmp)
{
	int		i;

	i = 0;
	while (tmp && (tmp->type == WORD || tmp->type == VAR))
	{
		if (tmp->type == VAR && tmp->join == true)
		{
			while (tmp->type == VAR && tmp->join == true)
				tmp = tmp->next;
			i++;
		}
		else
		{
			i++;
			tmp = tmp->next;
		}
	}
	return (i);
}

char	**cpy_args_echo(int len, char **new_tab, t_command *last_cmd,
		t_token *tmp)
{
	int		i;

	i = 0;
	while (i < len)
	{
		new_tab[i] = last_cmd->args[i];
		i++;
	}
	while (tmp->type == WORD || tmp->type == VAR)
	{
		if (tmp->join == true)
			new_tab[i] = var_join(&tmp);
		else
			new_tab[i] = ft_strdup(tmp->str);
		i++;
		tmp = tmp->next;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

void	del_nonex_var(t_token **tokens)
{
	t_token		*tmp;

	tmp = *tokens;
	while (tmp->type == WORD || tmp->type == VAR)
	{
		if (tmp->type == VAR && tmp->str[0] == '\0'
			&& tmp->var_exists == false)
		{
			tmp = tmp->next;
			if (tmp == (*tokens)->next)
				(*tokens) = (*tokens)->next;
			del_one_node(tmp->prev, free_ptr);
		}
		else
			tmp = tmp->next;
	}
}
