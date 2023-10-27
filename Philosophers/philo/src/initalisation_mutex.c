/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalisation_mutex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:48:48 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/13 18:23:10 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutexes(t_params *params)
{
	int	i;

	i = 0;
	params->fork = malloc(sizeof(pthread_mutex_t)
			* params->number_of_philosophers);
	if (!params->fork)
		return (1);
	i = 0;
	while (i < params->number_of_philosophers)
		pthread_mutex_init(&params->fork[i++], NULL);
	if (pthread_mutex_init(&(params->mutex_death), NULL) != 0)
		return (1);
	if (pthread_mutex_init(&(params->mutex_write), NULL) != 0)
		return (1);
	return (0);
}
