/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenmaker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:42:26 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:42:26 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokenmaker(t_data *data, char *str)

{
	int	i;
	int	start;
	int	end;
	int	quotes;

	i = -1;
	start = 0;
	end = ft_strlen(str);
	quotes = DEFAULT;
	while (++i <= end)
	{
		quotes = what_quotes(quotes, str, i);
		if (quotes == DEFAULT)
			start = store_token(&i, str, start, data);
	}
	if (quotes != DEFAULT)
	{
		if (quotes == SGLQUOTES)
			gen_err_msg("unexpected EOF while looking for matching", "\"", 1);
		else if (quotes == DBLQUOTES)
			gen_err_msg("unexpected EOF while looking for matching", "\'", 1);
		gen_err_msg("syntax error", "unexpected end of file", 0);
		return (-1);
	}
	return (0);
}
