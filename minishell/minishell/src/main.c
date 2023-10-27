/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:44:46 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:44:46 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	miniloop(t_data *data)
{
	while (1)
	{
		base_minishell_sig();
		data->input = readline(MINISHELL);
		cmd_in_shell_sig();
		if (input_parsing(data) == 0)
			g_excode = exec_prep(data);
		else
			g_excode = 1;
		free_datastruct(data, false);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	data;

	(void) av;
	if (!isatty(STDIN_FILENO))
		return (printf("minishell stdin is not correct\n"), exit(0), 1);
	ft_memset(&data, 0, sizeof(t_data));
	if (ac != 1 || datastruct_init(&data, env) != 0)
		exit_shell(NULL, EXIT_FAILURE);
	miniloop(&data);
	exit_shell(&data, g_excode);
	return (0);
}
