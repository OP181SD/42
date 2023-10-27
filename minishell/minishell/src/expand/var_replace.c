/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:23:12 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:23:12 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	var_delete(t_token **tok_lst, char *str, int idx)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	i = 0;
	j = 0;
	len = ft_strlen(str) - var_len(str + idx);
	new = (char *)malloc(sizeof(char) * len + 1);
	if (!new)
		return (-1);
	while (str[i])
	{
		if (str[i] == '$' && i == idx)
		{
			i = i + var_len(str + idx) + 1;
			if (str[i] == '\0')
				break ;
		}
		new[j++] = str[i++];
	}
	new[j] = '\0';
	free_ptr((*tok_lst)->str);
	(*tok_lst)->str = new;
	return (0);
}

static char	*full_replace(t_token **tok_lst, char *str, char *value, int idx)
{
	char	*new;
	int		size_new;

	size_new = (ft_strlen(str) - var_len(str + idx) + ft_strlen(value));
	new = name_to_value(str, value, size_new, idx);
	if (tok_lst && *tok_lst)
	{
		free_ptr((*tok_lst)->str);
		(*tok_lst)->str = new;
	}
	return (new);
}

int	var_replace(t_token **tok_lst, char *value, int i)
{
	if (value == NULL)
	{
		if (var_delete(tok_lst, (*tok_lst)->str, i) == -1)
		{
			free_ptr(value);
			return (1);
		}
	}
	else
	{
		if (full_replace(tok_lst, (*tok_lst)->str, value, i) == NULL)
		{
			free_ptr(value);
			return (1);
		}
	}
	free_ptr(value);
	return (0);
}

char	*replace_var_hdoc(char *str, char *value, int idx)
{
	char	*tmp;

	tmp = NULL;
	if (value == NULL)
		*str = '\0';
	else
	{
		tmp = str;
		str = full_replace(NULL, str, value, idx);
		free_ptr(tmp);
	}
	free_ptr(value);
	return (str);
}
