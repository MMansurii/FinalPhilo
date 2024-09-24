/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5status2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:49:24 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 14:53:40 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	status_print(t_persondb *philo, char *message)
{
	long long	time;

	pthread_mutex_lock(&(philo->db->for_printing));
	if (philo->db->statusv[0] == 0)
	{
		time = time_now() - philo->db->start_time;
		printf("%lld ", time);
		printf("%d ", philo->philo_id);
		printf("%s", message);
		printf("\n");
	}
	pthread_mutex_unlock(&(philo->db->for_printing));
}

int	monitor_philo(t_main_db *db, t_persondb *philo)
{
	int	j;
	int	result;

	j = 0;
	result = 0;
	while (j < db->inputs[0])
	{
		lock_main_mutex(db);
		if (runnig_continue(db, &philo[j], 2))
		{
			db->statusv[0] = 1;
			if (runnig_continue(db, &philo[j], 3))
			{
				dead_print(db->person, "  died");
			}
			unlock_main_mutex(db);
			result = 1;
			break ;
		}
		unlock_main_mutex(db);
		sleep_time(1);
		j++;
	}
	return (result);
}

void	status_thread(t_main_db *db, t_persondb *philo)
{
	while (runnig_continue(db, &philo[0], 1))
	{
		if (monitor_philo(db, philo))
			break ;
	}
}

int	runnig_continue(t_main_db *db, t_persondb *philo, int mod)
{
	if (mod == 1)
	{
		return (db->statusv[0] == 0);
	}
	if (mod == 2)
	{
		return (time_now() - philo->last_eaten > db->inputs[1]);
	}
	if (mod == 3)
	{
		return ((db->inputs[4] < 1) || (philo->num_eaten < db->inputs[4]));
	}
	return (0);
}
