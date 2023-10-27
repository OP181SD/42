/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:21:57 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:21:57 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	status_change(t_token **tok_lst, int *i)
{
	if ((*tok_lst)->str[*i] == '\'')
		(*tok_lst)->status = SGLQUOTES;
	if ((*tok_lst)->str[*i] == '\"')
		(*tok_lst)->status = DBLQUOTES;
	(*i)++;
}

static int	change_status_flag(t_token **tok_lst, int i)
{
	if (((*tok_lst)->str[i] == '\'' || (*tok_lst)->str[i] == '\"')
		&& (*tok_lst)->status == DEFAULT)
		return (0);
	else
		return (-1);
}

static int	reset_status(t_token **tok_lst, int *i)
{
	if (((*tok_lst)->str[*i] == '\'' && (*tok_lst)->status == SGLQUOTES)
		|| ((*tok_lst)->str[*i] == '\"' && (*tok_lst)->status == DBLQUOTES))
	{
		(*tok_lst)->status = DEFAULT;
		(*i)++;
		return (0);
	}
	else
		return (-1);
}

int	count_len(char *str, int count, int i)
{
	int	status;

	status = 0;
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '\"') && status == DEFAULT)
		{
			if (str[i] == '\'')
				status = SGLQUOTES;
			if (str[i] == '\"')
				status = DBLQUOTES;
			i++;
			continue ;
		}
		else if ((str[i] == '\'' && status == SGLQUOTES)
			|| (str[i] == '\"' && status == DBLQUOTES))
		{
			status = DEFAULT;
			i++;
			continue ;
		}
		count++;
		i++;
	}
	return (count + 1);
}

int	remove_quotes(t_token **tok_lst)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_line = malloc(sizeof(char) * count_len((*tok_lst)->str, i, i));
	if (!new_line)
		return (1);
	while ((*tok_lst)->str[i])
	{
		if (change_status_flag(tok_lst, i) == 0)
		{
			status_change(tok_lst, &i);
			continue ;
		}
		else if (reset_status(tok_lst, &i) == 0)
			continue ;
		new_line[j++] = (*tok_lst)->str[i++];
	}
	new_line[j] = '\0';
	free_ptr((*tok_lst)->str);
	(*tok_lst)->str = new_line;
	(*tok_lst)->join = true;
	return (0);
}
