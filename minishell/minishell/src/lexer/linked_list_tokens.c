/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_tokens.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:43:18 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:43:18 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_node_list(char *str, char *cpy, int type, int status)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token) * 1);
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->var_exists = false;
	new_node->join = false;
	new_node->str = str;
	new_node->str_backup = cpy;
	new_node->status = status;
	new_node->type = type;
	return (new_node);
}

void	addback_node(t_token **node, t_token *new_node)
{
	t_token	*start;

	start = *node;
	if (start == NULL)
	{
		*node = new_node;
		return ;
	}
	if (node && *node && new_node)
	{
		while (start->next != NULL)
			start = start->next;
		start->next = new_node;
		new_node->prev = start;
	}
}

void	del_one_node(t_token *tok_lst, void (*del)(void *))
{
	if (del && tok_lst && tok_lst->str)
	{
		(*del)(tok_lst->str);
		tok_lst->str = NULL;
	}
	if (del && tok_lst && tok_lst->str_backup)
	{
		(*del)(tok_lst->str_backup);
		tok_lst->str_backup = NULL;
	}
	if (tok_lst->prev)
		tok_lst->prev->next = tok_lst->next;
	if (tok_lst->next)
		tok_lst->next->prev = tok_lst->prev;
	free_ptr(tok_lst);
}

void	list_wipe(t_token **tok_lst, void (*del)(void *))
{
	t_token	*tmp;

	tmp = NULL;
	while (*tok_lst != NULL)
	{
		tmp = (*tok_lst)->next;
		del_one_node(*tok_lst, del);
		*tok_lst = tmp;
	}
}
