/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:32:56 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/15 17:48:24 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_args(t_params *init, int argc, char **argv)
{
	init->number_of_philosophers = ft_atoi(argv[1]);
	init->time_to_die = ft_atoi(argv[2]);
	init->time_to_eat = ft_atoi(argv[3]);
	init->time_to_sleep = ft_atoi(argv[4]);
	init->is_anyone_dead = 0;
	if (argc == 6)
		init->nb_eat = ft_atoi(argv[5]);
	else
		init->nb_eat = -1;
	return (0);
}

int	assing_philo(t_params *params, int i)
{
	params->philo[i].status = IM_THINKING;
	params->philo[i].id = i + 1;
	params->philo[i].time_to_die = params->time_to_die;
	params->philo[i].time_to_eat = params->time_to_eat;
	params->philo[i].time_to_sleep = params->time_to_sleep;
	params->philo[i].nb_eat = params->nb_eat;
	params->philo[i].mutex_death = &(params->mutex_death);
	params->philo[i].mutex_write = &(params->mutex_write);
	params->philo[i].is_anyone_dead = &(params->is_anyone_dead);
	params->philo[i].left_fork = &(params->fork[i]);
	params->philo[i].right_fork = &(params->fork[(i + 1)
			% params->number_of_philosophers]);
	return (0);
}

int	initialize_philosophers(t_params *params)
{
	int	i;

	i = 0;
	params->philo = (t_philo *)malloc(sizeof(t_philo)
			* params->number_of_philosophers);
	if (!params->philo)
		return (1);
	memset(params->philo, 0, sizeof(t_philo) * params->number_of_philosophers);
	while (i < params->number_of_philosophers)
	{
		assing_philo(params, i);
		i++;
	}
	if (params->number_of_philosophers == 1)
	{
		printf("1 has taken a fork\n");
		printf("%d is died", params->philo->time_to_die);
		free(params->philo);
		pthread_mutex_destroy(&(params->fork[0]));
		free(params->fork);
		return (1);
	}
	return (0);
}

int	init_all(t_params *init, int argc, char **argv)
{
	if (init_args(init, argc, argv))
		return (1);
	if (init_mutexes(init))
		return (1);
	if (initialize_philosophers(init))
		return (1);
	return (0);
}
