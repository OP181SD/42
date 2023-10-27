/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:41:31 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:41:31 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	input_parsing(t_data *data)
{
	if (data->input == NULL)
		exit_builtin(data, NULL);
	else if (ft_strcmp(data->input, "\0") == 0)
		return (-1);
	else if (is_space(data->input))
		return (0);
	add_history(data->input);
	if (tokenmaker(data, data->input) == -1)
		return (-1);
	if (data->token->type == END)
		return (-1);
	if (is_it_var(&data->token) == -1)
		return (-1);
	expand_var(data, &data->token);
	handle_quotes(data);
	cmd_parser(data, data->token);
	return (0);
}
