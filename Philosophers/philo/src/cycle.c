/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:15:04 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/15 13:18:01 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	calculate_thinking_time(t_philo *philo)
{
	int	thinking_time;

	thinking_time = 0;
	if (philo->time_to_eat == philo->time_to_sleep)
		thinking_time = philo->time_to_sleep - 10;
	else if (philo->time_to_eat < philo->time_to_sleep)
		thinking_time = philo->time_to_sleep - philo->time_to_eat;
	else
		thinking_time = philo->time_to_eat - philo->time_to_sleep;
	return (thinking_time);
}

void	perform_thinking_action(t_philo *philo)
{
	int	thinking_time;

	thinking_time = calculate_thinking_time(philo);
	if ((philo->id % 2 && philo->cycle == 1) || (philo->cycle == 1
			&& philo->number_of_philosophers % 2
			&& philo->id == philo->number_of_philosophers))
	{
		wait(thinking_time, "is thinking", philo);
		if (check_death(philo) || philo->status == IM_DEAD)
			return ;
	}
	else
		display_status(philo, "is thinking");
}

void	begin_cycle(t_philo *philo)
{
	if (philo->status != IM_THINKING)
		return ;
	philo->cycle++;
	perform_thinking_action(philo);
	philo->status = IM_EATING;
	is_eating(philo);
}
