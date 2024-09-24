/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6phroutin2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:49:24 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 14:55:20 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	continue_run1(t_persondb *philo1)
{
	int	condition1;
	int	condition2;
	int	condition3;
	int	condition3_1;
	int	condition3_2;

	condition1 = (!is_philo_dead(philo1));
	condition2 = philo1->whatsup;
	condition3_1 = (philo1->db->inputs[4] < 1);
	condition3_2 = (philo1->num_eaten < philo1->db->inputs[4]);
	condition3 = (condition3_1 || condition3_2);
	return ((condition1 && condition2 && condition3));
}

void	now_thinking(t_persondb *philo1)
{
	status_print(philo1, " is thinking");
}

void	now_sleeping(t_persondb *philo1)
{
	status_print(philo1, " is sleeping");
	sleep_time(philo1->db->inputs[3]);
}

void	*philo_routine(void *arg)
{
	t_persondb	*philo1;

	philo1 = (t_persondb *)arg;
	initial_delay(philo1);
	while (continue_run1(philo1))
	{
		pick_put_forks(philo1, 1);
		if (!now_eating_time(philo1))
			break ;
		if (philo1->db->inputs[4] != 0
			&& philo1->num_eaten == philo1->db->inputs[4])
			break ;
		now_sleeping(philo1);
		now_thinking(philo1);
	}
	return (NULL);
}
