/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:49:35 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 14:57:57 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_persondb
{
	pthread_t			threadid;
	struct s_fcapacity	*first_fork;
	struct s_fcapacity	*second_fork;
	int					philo_id;
	int					num_eaten;
	long long			last_eaten;
	struct s_main_db	*db;
	int					whatsup;
}						t_persondb;

typedef struct s_fcapacity
{
	pthread_mutex_t		theforks;
}						t_fcapacity;

typedef struct s_main_db
{
	int					inputs[5];
	int					statusv[3];
	long long			start_time;
	pthread_mutex_t		for_printing;
	pthread_mutex_t		dont_run;
	struct s_persondb	*person;
	struct s_fcapacity	*fcapacity;
}						t_main_db;

// utils1valid
int						ft_atoi(const char *str);
int						check_args_num(int argc, char **argv);
int						check_times(char **argv);
int						check_is_digit(char **argv);
int						check_args(int argc, char **argv);
// <<
// utils2start
void					set_initial_val_db(t_main_db *db, char **argv);
void					set_person_val_i1(t_main_db *db, int j);
void					set_person_val_i2(t_main_db *db, int j);
void					fork_run(t_main_db *db);
void					run_philo(char **argv);

// <<
// utils3thread
int						create_philo_thread(t_main_db *db);
int						join_philo_thread(t_main_db *db);
void					destroy_all_mutex(t_main_db *db);
void					create_join_threads(t_main_db *db);
// <<
// utils4time
long long				time_in_mili(struct timeval *time);
long long				time_now(void);
void					helper_sleep_time(int time_in_milliseconds);
void					sleep_time(int time_in_milliseconds);
// <<
// utils5status
void					dead_print(t_persondb *philo, char *message);
void					eat_print(t_persondb *philo, char *message);
int						is_philo_dead(t_persondb *philo);
void					lock_main_mutex(t_main_db *db);
void					unlock_main_mutex(t_main_db *db);
// <<
// utils5status2
void					status_print(t_persondb *philo, char *message);
int						monitor_philo(t_main_db *db, t_persondb *philo);
void					status_thread(t_main_db *db, t_persondb *philo);
int						runnig_continue(t_main_db *db, t_persondb *philo,
							int mod);
// <<
// utils6phroutin
int						now_eating_time(t_persondb *philo1);
void					initial_delay(t_persondb *philo1);
void					pick_put_forks(t_persondb *philo1, int modrl);
t_fcapacity				*take_first_forks(t_main_db *db, int j);
t_fcapacity				*take_second_forks(t_main_db *db, int j);
// <<
// utils6phroutin2
int						continue_run1(t_persondb *philo1);
void					now_thinking(t_persondb *philo1);
void					now_sleeping(t_persondb *philo1);
void					*philo_routine(void *arg);

// <<

#endif
