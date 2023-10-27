/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:21:02 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:21:02 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cpy_value(char *new, char *value, int *j)
{
	int	k;

	k = 0;
	while (value[k])
	{
		new[*j] = value[k];
		k++;
		(*j)++;
	}
}

char	*name_to_value(char *old, char *value, int size_new, int idx)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * size_new);
	if (!new)
		return (NULL);
	while (old[i])
	{
		if (old[i] == '$' && i == idx)
		{
			cpy_value(new, value, &j);
			i = i + var_len(old + idx) + 1;
			if (old[i] == '\0')
				break ;
		}
		new[j++] = old[i++];
	}
	new[j] = '\0';
	return (new);
}
