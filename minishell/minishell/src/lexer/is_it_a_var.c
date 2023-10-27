/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_a_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:42:43 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:42:43 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	what_var_2(t_token **token_list)
{
	int	i;

	i = 0;
	while ((*token_list)->str[i])
	{
		if ((*token_list)->str[i] == '$')
		{
			if ((*token_list)->prev && (*token_list)->prev->type == HEREDOC)
				break ;
			(*token_list)->type = VAR;
			return ;
		}
		i++;
	}
}

int	is_it_var(t_token **token)
{
	t_token	*tmp;

	tmp = *token;
	if (tmp->type == PIPE)
	{
		gen_err_msg("syntax error near unexpected token", tmp->str, 1);
		return (-1);
	}
	while (tmp)
	{
		what_var_2(&tmp);
		if (check_2_tokens(&tmp) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
