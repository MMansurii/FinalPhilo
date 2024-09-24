/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:49:24 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 14:52:13 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_initial_val_db(t_main_db *db, char **argv)
{
	int	i;

	i = -1;
	while (++i < 4)
		db->inputs[i] = ft_atoi(argv[i + 1]);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) < 1)
			return ;
		db->inputs[4] = ft_atoi(argv[5]);
	}
	else
		db->inputs[4] = 0;
	i = -1;
	while (++i < 3)
		db->statusv[i] = 0;
	pthread_mutex_init(&(db->for_printing), NULL);
	pthread_mutex_init(&(db->dont_run), NULL);
}

void	set_person_val_i1(t_main_db *db, int j)
{
	db->person[j].philo_id = j + 1;
	db->person[j].num_eaten = 0;
	db->person[j].whatsup = 1;
	db->person[j].last_eaten = time_now();
}

void	set_person_val_i2(t_main_db *db, int j)
{
	db->person[j].first_fork = take_first_forks(db, j);
	db->person[j].second_fork = take_second_forks(db, j);
	db->person[j].db = db;
}

void	fork_run(t_main_db *db)
{
	int	j;

	j = -1;
	while (++j < db->inputs[0])
		set_person_val_i1(db, j);
	j = -1;
	while (++j < db->inputs[0])
		pthread_mutex_init(&(db->fcapacity[j].theforks), NULL);
	j = -1;
	while (++j < db->inputs[0])
		set_person_val_i2(db, j);
	create_join_threads(db);
	destroy_all_mutex(db);
	free(db->fcapacity);
	free(db->person);
	free(db);
}

void	run_philo(char **argv)
{
	t_main_db	*db;

	db = malloc(sizeof(t_main_db));
	if (!db)
		perror("Error: Malloc failed\n");
	set_initial_val_db(db, argv);
	db->start_time = time_now();
	db->person = malloc(sizeof(t_persondb) * db->inputs[0]);
	if (!db->person)
		perror("Error: Malloc failed\n");
	db->fcapacity = malloc(sizeof(t_fcapacity) * db->inputs[0]);
	if (!db->fcapacity)
		perror("Error: Malloc failed\n");
	fork_run(db);
}
