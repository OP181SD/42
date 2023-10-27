/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:15:31 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/13 18:23:26 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	clear_philo(t_params *params)
{
	int	i;

	if (params)
	{
		pthread_mutex_destroy(&(params->mutex_write));
		pthread_mutex_destroy(&(params->mutex_death));
		if (params->fork)
		{
			i = 0;
			while (i < params->number_of_philosophers)
			{
				pthread_mutex_destroy(&(params->fork[i]));
				i++;
			}
			free(params->fork);
		}
		if (params->philo)
			free(params->philo);
	}
	return (0);
}
