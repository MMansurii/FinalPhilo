/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:49:24 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 14:50:03 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	if (!check_args(argc, argv))
		return (1);
	run_philo(argv);
	return (0);
}

// db->inputs[number_of_philo, t_die, t_eat, t_sleep, [number_must_eat]]
// db->statusv[isdead, isfull, isdead or isfull]
// first_fork --> right fork
// second_fork --> left fork
// db->dont_run --> mutex for not running the threads
// db->for_printing --> mutex for printing
// db->person --> array of philosphers
// db->fcapacity --> array of forks
// db->person->num_eaten --> number of times eaten
// db->person->last_eaten --> time of last eaten
// db->person->whatsup --> status of the philospher
// db->person->threadid --> thread id of the philospher
// db->person->first_fork --> right fork
// db->person->second_fork --> left fork
// db->person->db --> pointer to the main db
// db->person->philo_id --> philospher id

// testing the philasophers project
// valgrind --leak-check=full --show-leak-kinds=all >>
// >>    --track-origins=yes ./philo 5 800 200 200 7
// helgrind ./philo 5 800 200 200 7
// helgrind --history-level=full ./philo 5 800 200 200 7
// run
//       cc -Wall -Wextra -Werror -g *.c -o philo -lpthread
//      ./philo 1 800 200 200
//  -->  the philospher should not eat and should die
//      ./philo 5 800 200 200
//  -->  No one should die
//      ./philo 5 800 200 200 7
//  -->  No one should die
//      ./philo 4 410 200 200
//  -->  No one should die
//      ./philo 4 310 200 100
//  -->  One should die

// valgrind --tool=helgrind ./philo 1 800 200 200
// valgrind --tool=helgrind ./philo 4 410 200 200 10
// valgrind --tool=helgrind ./philo 4 401 200 200 10
