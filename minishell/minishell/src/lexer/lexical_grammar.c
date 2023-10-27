/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_grammar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:41:42 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:41:42 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	weird_shit_handler(t_token *tok_node)
{
	if (tok_node->prev)
	{
		if (tok_node->type == END && tok_node->prev->type >= PIPE)
			return (-1);
		if (tok_node->type == PIPE && tok_node->prev->type >= PIPE)
			return (-1);
		if (tok_node->type == PIPE && tok_node->prev->type == PIPE)
			return (-1);
	}
	return (0);
}

int	check_2_tokens(t_token **tok_list)
{
	t_token	*tmp;

	tmp = *tok_list;
	while (tmp)
	{
		if (weird_shit_handler(tmp) == -1)
		{
			if (tmp->type == END && tmp->prev && tmp->prev->type > PIPE)
				gen_err_msg("syntax error near unexpected token", "newline", 1);
			else if (tmp->type == END && tmp->prev)
				gen_err_msg("syntax error near unexpected token",
					tmp->prev->str, 1);
			else
				gen_err_msg("syntax error near unexpected token", tmp->str, 1);
			return (-1);
		}
		tmp = tmp->next;
	}
	return (1);
}
