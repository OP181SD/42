/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:21:46 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:21:46 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	does_str_have_quotes(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (0);
		i++;
	}
	return (-1);
}

int	handle_quotes(t_data *data)
{
	t_token	*tmp;

	tmp = data->token;
	while (tmp)
	{
		if (does_str_have_quotes(tmp->str) == 0
			&& (!tmp->prev || (tmp->prev && tmp->prev->type != HEREDOC)))
			remove_quotes(&tmp);
		tmp = tmp->next;
	}
	return (0);
}
