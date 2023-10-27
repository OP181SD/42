/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenmaker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:43:43 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:43:43 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	what_quotes(int status, char *str, int i)
{
	if (str[i] == '\'' && status == DEFAULT)
		status = SGLQUOTES;
	else if (str[i] == '\"' && status == DEFAULT)
		status = DBLQUOTES;
	else if (str[i] == '\'' && status == SGLQUOTES)
		status = DEFAULT;
	else if (str[i] == '\"' && status == DBLQUOTES)
		status = DEFAULT;
	return (status);
}

static int	store_tkn_sep(t_token **token_lst, char *str, int index, int type)
{
	int		i;
	char	*sep;

	i = 0;
	if (type == APPEND || type == HEREDOC)
	{
		sep = malloc(sizeof(char) * 3);
		if (!sep)
			return (1);
		while (i < 2)
			sep[i++] = str[index++];
		sep[i] = '\0';
		addback_node(token_lst, new_node_list(sep, NULL, type, DEFAULT));
	}
	else
	{
		sep = malloc(sizeof(char) * 2);
		if (!sep)
			return (1);
		while (i < 1)
			sep[i++] = str[index++];
		sep[i] = '\0';
		addback_node(token_lst, new_node_list(sep, NULL, type, DEFAULT));
	}
	return (0);
}

static int	store_tkn_word(t_token **token_lst, char *str, int index, int start)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (index - start + 1));
	if (!word)
		return (1);
	while (start < index)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	addback_node(token_lst, \
			new_node_list(word, ft_strdup(word), WORD, DEFAULT));
	return (0);
}

int	what_separator(char *str, int i)
{
	if (((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		return (SPACES);
	else if (str[i] == '|')
		return (PIPE);
	else if (str[i] == '<' && str[i + 1] == '<')
		return (HEREDOC);
	else if (str[i] == '>' && str[i + 1] == '>')
		return (APPEND);
	else if (str[i] == '<')
		return (INPUT);
	else if (str[i] == '>')
		return (TRUNC);
	else if (str[i] == '\0')
		return (END);
	else
		return (0);
}

int	store_token(int *i, char *str, int start, t_data *data)
{
	int	type;

	type = what_separator(str, (*i));
	if (type)
	{
		if ((*i) != 0 && what_separator(str, (*i) - 1) == 0)
			store_tkn_word(&data->token, str, (*i), start);
		if (type == APPEND || type == HEREDOC || type == PIPE
			|| type == INPUT || type == TRUNC || type == END)
		{
			store_tkn_sep(&data->token, str, (*i), type);
			if (type == APPEND || type == HEREDOC)
				(*i)++;
		}
		start = (*i) + 1;
	}
	return (start);
}
