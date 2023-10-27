/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:51:59 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/13 19:52:26 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_diff_time(t_timeval pres_time)
{
	long int	time;
	t_timeval	current_time;

	time = 0;
	gettimeofday(&current_time, NULL);
	time = (current_time.tv_sec - pres_time.tv_sec) * 1000
		+ (current_time.tv_usec - pres_time.tv_usec) / 1000;
	return (time);
}

void	wait(int time, char *action, t_philo *philo)
{
	int	time_skip;

	time_skip = get_diff_time(philo->acutal_time) - philo->last_meal;
	time_skip = time_skip - (time_skip % 10);
	if (time_skip + time <= philo->time_to_die)
	{
		display_status(philo, action);
		usleep(1000 * time);
		if (philo->status == IM_EATING)
			no_more_forks(philo);
	}
	else
	{
		time = philo->time_to_die - time_skip;
		usleep(1000 * time);
		if (philo->status == IM_EATING)
			no_more_forks(philo);
		im_dead(philo);
		philo->status = IM_DEAD;
	}
}
