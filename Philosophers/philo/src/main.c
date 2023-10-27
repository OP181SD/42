/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:35:39 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/13 21:40:45 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_params	each_args;

	if (argc != 5 && argc != 6)
	{
		exit_argc();
		return (0);
	}
	memset(&each_args, 0, sizeof(t_params));
	if (parsing(argc, argv) == -1)
		return (-1);
	if (init_all(&each_args, argc, argv))
		return (1);
	if (create_philosopher(&each_args))
		return (1);
	clear_philo(&each_args);
	return (0);
}
