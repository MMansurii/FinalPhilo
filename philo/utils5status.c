/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:49:24 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 14:59:09 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	dead_print(t_persondb *philo, char *message)
{
	long long	time;

	time = time_now() - philo->db->start_time;
	printf("%lld ", time);
	printf("%d ", philo->philo_id);
	printf("%s", message);
	printf("\n");
}

void	eat_print(t_persondb *philo, char *message)
{
	long long	time;

	pthread_mutex_lock(&(philo->db->for_printing));
	philo->last_eaten = time_now();
	time = time_now() - philo->db->start_time;
	printf("%lld ", time);
	printf("%d ", philo->philo_id);
	printf("%s", message);
	printf("\n");
	pthread_mutex_unlock(&(philo->db->for_printing));
}

int	is_philo_dead(t_persondb *philo)
{
	int	result;

	result = 0;
	if (time_now() - philo->last_eaten > philo->db->inputs[1])
	{
		philo->whatsup = 0;
		result = 1;
	}
	return (result);
}

void	lock_main_mutex(t_main_db *db)
{
	pthread_mutex_lock(&(db->dont_run));
	pthread_mutex_lock(&(db->for_printing));
}

void	unlock_main_mutex(t_main_db *db)
{
	pthread_mutex_unlock(&(db->dont_run));
	pthread_mutex_unlock(&(db->for_printing));
}
