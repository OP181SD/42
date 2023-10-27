/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:58:46 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/13 18:24:31 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*philo_routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	gettimeofday(&philo->acutal_time, NULL);
	begin_cycle(philo);
	return (NULL);
}

int	create_philosopher(t_params *params)
{
	t_you	you;
	int		i;

	i = 0;
	while (i < params->number_of_philosophers)
	{
		you.create_thread = pthread_create(&(params->philo[i].thread_id), NULL,
				philo_routine, &(params->philo[i]));
		if (you.create_thread != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < params->number_of_philosophers)
	{
		you.wait_the_end = pthread_join(params->philo[i].thread_id, NULL);
		if (you.create_thread != 0)
			return (1);
		i++;
	}
	return (0);
}
