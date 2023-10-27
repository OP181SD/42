/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:37:00 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/16 11:45:28 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_status(t_philo *philo, const char *action)
{
	long long int	diff_time;
	bool			write;

	write = true;
	pthread_mutex_lock(philo->mutex_write);
	if (check_death(philo) == true)
		write = false;
	if (write)
	{
		diff_time = get_diff_time(philo->acutal_time);
		diff_time = diff_time - (diff_time % 10);
		printf("%lld %d %s\n", diff_time, philo->id, action);
		pthread_mutex_unlock(philo->mutex_write);
	}
	else
	{
		diff_time = get_diff_time(philo->acutal_time);
		diff_time = diff_time - (diff_time % 10);
		if (!strcmp(action, "died"))
			printf("%lld %d %s\n", diff_time, philo->id, action);
		pthread_mutex_unlock(philo->mutex_write);
	}
}

void	exit_argc(void)
{
	write(2, "Erreur : Nombre invalide d'arguments\n", 37);
	write(2, "Utilisation : ./philo", 22);
}
