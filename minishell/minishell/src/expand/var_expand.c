/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:25:38 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:25:38 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	what_quotes_2(t_token **tok_lst, char c)
{
	if (c == '\'' && (*tok_lst)->status == DEFAULT)
		(*tok_lst)->status = SGLQUOTES;
	else if (c == '\"' && (*tok_lst)->status == DEFAULT)
		(*tok_lst)->status = DBLQUOTES;
	else if (c == '\'' && (*tok_lst)->status == SGLQUOTES)
		(*tok_lst)->status = DEFAULT;
	else if (c == '\"' && (*tok_lst)->status == DBLQUOTES)
		(*tok_lst)->status = DEFAULT;
}

static int	what_is_next(char c)
{
	if (c == '$' || c == ' ' || c == '=' || c == '\0')
		return (0);
	else
		return (-1);
}

static int	in_quotes(char *str, int i)
{
	if (i > 0)
	{
		if (str[i - 1] == '\"' && str[i + 1] == '\"')
			return (0);
		else
			return (-1);
	}
	return (-1);
}

int	expand_var(t_data *data, t_token **tok_list)
{
	t_token	*tmp;
	int		i;

	tmp = *tok_list;
	while (tmp)
	{
		if (tmp->type == VAR)
		{
			i = 0;
			while (tmp->str[i])
			{
				what_quotes_2(&tmp, tmp->str[i]);
				if (tmp->str[i] == '$' && what_is_next(tmp->str[i + 1]) == -1
					&& in_quotes(tmp->str, i) == -1 && (tmp->status == DEFAULT
						|| tmp->status == DBLQUOTES))
					var_replace(&tmp, get_val(tmp, tmp->str + 1, data), i);
				else
					i++;
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*expand_var_heredoc(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && what_is_next(str[i + 1]) == -1 && in_quotes(str,
				i) == -1)
			str = replace_var_hdoc(str, get_val(NULL, str + i, data), i);
		else
			i++;
	}
	return (str);
}
