/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:48:12 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/15 13:13:22 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_eating(t_philo *philo)
{
	if (philo->status != IM_EATING)
		return ;
	use_forks(philo);
	wait(philo->time_to_eat, "is eating", philo);
	if (check_death(philo) || philo->status == IM_DEAD)
		return ;
	philo->last_meal = get_diff_time(philo->acutal_time);
	if (philo->nb_eat > 0 && philo->nb_eat != -1)
		philo->nb_eat--;
	if (philo->nb_eat == 0)
		philo->status = IM_FULL;
	else
		philo->status = IM_SLEEPING;
	is_sleeping(philo);
}

void	is_sleeping(t_philo *philo)
{
	if (philo->status != IM_SLEEPING)
		return ;
	wait(philo->time_to_sleep, "is sleeping", philo);
	if (check_death(philo) || philo->status == IM_DEAD)
		return ;
	philo->status = IM_THINKING;
	begin_cycle(philo);
}
