/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:25:31 by yasaidi           #+#    #+#             */
/*   Updated: 2023/09/13 21:40:08 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <ctype.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct timeval	t_timeval;

enum					e_status
{
	IM_EATING,
	IM_THINKING,
	IM_SLEEPING,
	IM_DEAD,
	IM_FULL
};

enum					e_mode
{
	SLEEP,
	THINK
};

typedef struct s_you
{
	int					create_thread;
	int					wait_the_end;
}						t_you;

typedef struct s_philo
{
	int					status;
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					id;
	pthread_t			thread_id;
	int					nb_eat;
	int					*is_anyone_dead;
	pthread_mutex_t		*mutex_write;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*mutex_death;
	pthread_mutex_t		mutex_eat;
	int					cycle;
	long int			last_meal;
	t_timeval			acutal_time;

}						t_philo;

typedef struct s_params
{
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_eat;
	int					is_anyone_dead;
	pthread_mutex_t		mutex_write;
	pthread_mutex_t		mutex_death;
	pthread_mutex_t		*mutex_eat;
	pthread_mutex_t		*fork;
	t_philo				*philo;
}						t_params;

// Fonctions d'initialisation
int						create_philosopher(t_params *params);
int						init_mutexes(t_params *params);
int						init_all(t_params *init, int argc, char **argv);
int						parsing(int argc, char **argv);
int						ft_atoi(char *str);
void					exit_argc(void);

// Fonctions de gestion des philosophes
void					use_forks(t_philo *philo);
void					no_more_forks(t_philo *philo);
void					is_eating(t_philo *use);
void					display_status(t_philo *philo, const char *action);

// Fonctions de gestion de l'état des philosophes
bool					check_death(t_philo *use);
void					is_eating(t_philo *philo);
void					is_sleeping(t_philo *philo);
void					im_dead(t_philo *philo);

// Fonctions de mesure du temps
long int				get_diff_time(t_timeval pres_time);
void					begin_cycle(t_philo *philo);
void					wait(int time, char *action, t_philo *philo);

// Free
int						clear_philo(t_params *params);

#endif