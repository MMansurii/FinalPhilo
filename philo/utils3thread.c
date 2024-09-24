/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:08:01 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 14:58:50 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philo_thread(t_main_db *db)
{
	int	i;

	i = -1;
	while (++i < db->inputs[0])
	{
		if (pthread_create(&(db->person[i].threadid), NULL, &philo_routine,
				&(db->person[i])) != 0)
		{
			perror("Error: Thread creation failed\n");
			return (0);
		}
	}
	return (1);
}

int	join_philo_thread(t_main_db *db)
{
	int	i;

	i = -1;
	while (++i < db->inputs[0])
	{
		if (pthread_join(db->person[i].threadid, NULL) != 0)
		{
			perror("Error: Thread join failed\n");
			return (0);
		}
	}
	return (1);
}

void	destroy_all_mutex(t_main_db *db)
{
	int	j;

	j = -1;
	pthread_mutex_destroy(&(db->for_printing));
	pthread_mutex_destroy(&(db->dont_run));
	while (++j < db->inputs[0])
	{
		pthread_mutex_destroy(&(db->fcapacity[j].theforks));
	}
}

void	create_join_threads(t_main_db *db)
{
	if (!create_philo_thread(db))
		return ;
	status_thread(db, (t_persondb *)(db->person));
	if (!join_philo_thread(db))
		return ;
}
