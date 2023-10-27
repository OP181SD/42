/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:16:14 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/14 17:27:27 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	im_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_death);
	*philo->is_anyone_dead += 1;
	pthread_mutex_unlock(philo->mutex_death);
	if (*philo->is_anyone_dead == 1)
		display_status(philo, "died");
}

bool	check_death(t_philo *use)
{
	pthread_mutex_lock(use->mutex_death);
	if (*(use->is_anyone_dead))
	{
		pthread_mutex_unlock(use->mutex_death);
		return (true);
	}
	pthread_mutex_unlock(use->mutex_death);
	return (false);
}
