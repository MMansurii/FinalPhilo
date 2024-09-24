/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:01:18 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 12:00:41 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	time_in_mili(struct timeval *time)
{
	return (time->tv_sec * 1000 + time->tv_usec / 1000);
}

long long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time_in_mili(&time));
}

void	helper_sleep_time(int time_in_milliseconds)
{
	usleep(time_in_milliseconds / 10);
}

void	sleep_time(int time_in_milliseconds)
{
	long int	initial_time;

	initial_time = time_now();
	while (time_now() - initial_time < time_in_milliseconds)
		helper_sleep_time(time_in_milliseconds);
}
