/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6phroutin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:49:24 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 14:54:25 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	now_eating_time(t_persondb *philo1)
{
	if (philo1->second_fork)
	{
		pick_put_forks(philo1, 2);
		pthread_mutex_lock(&(philo1->db->dont_run));
		if (philo1->db->statusv[0] == 1)
		{
			pthread_mutex_unlock(&(philo1->db->dont_run));
			pick_put_forks(philo1, 5);
			return (0);
		}
		eat_print(philo1, " is eating");
		philo1->num_eaten++;
		pthread_mutex_unlock(&(philo1->db->dont_run));
		sleep_time(philo1->db->inputs[2]);
	}
	pick_put_forks(philo1, 3);
	if (philo1->second_fork)
		pick_put_forks(philo1, 4);
	return (1);
}

void	initial_delay(t_persondb *philo1)
{
	if ((philo1->philo_id + 1) % 2)
		sleep_time(philo1->db->inputs[2] / 10);
}
// modrl = 1 --> pick right fork (first fork)
// modrl = 2 --> pick left fork (second fork)
// modrl = 3 --> put right fork (first fork)
// modrl = 4 --> put left fork (second fork)
// modrl = 5 --> put both forks

void	pick_put_forks(t_persondb *philo1, int modrl)
{
	if (modrl == 1)
	{
		pthread_mutex_lock(&(philo1->first_fork->theforks));
		status_print(philo1, " has taken a fork");
	}
	if (modrl == 2)
	{
		pthread_mutex_lock(&(philo1->second_fork->theforks));
		status_print(philo1, " has taken a fork");
	}
	if (modrl == 3)
	{
		pthread_mutex_unlock(&(philo1->first_fork->theforks));
	}
	if (modrl == 4)
	{
		pthread_mutex_unlock(&(philo1->second_fork->theforks));
	}
	if (modrl == 5)
	{
		pthread_mutex_unlock(&(philo1->first_fork->theforks));
		pthread_mutex_unlock(&(philo1->second_fork->theforks));
	}
}

t_fcapacity	*take_second_forks(t_main_db *db, int j)
{
	if (db->inputs[0] - 1 == j)
	{
		if (db->inputs[0] == 1)
			return (NULL);
		else
			return (&(db->fcapacity[j]));
	}
	else
		return (&(db->fcapacity[j + 1]));
	return (NULL);
}

t_fcapacity	*take_first_forks(t_main_db *db, int j)
{
	if (db->inputs[0] - 1 == j)
		return (&(db->fcapacity[0]));
	else
		return (&(db->fcapacity[j]));
	return (NULL);
}
