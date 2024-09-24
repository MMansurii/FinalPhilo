/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:49:24 by mmansuri          #+#    #+#             */
/*   Updated: 2024/09/24 14:49:19 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	int	i1;
	int	sign;
	int	result1;

	i1 = 0;
	sign = 1;
	result1 = 0;
	while (str[i1] == 9 || str[i1] == 10 || str[i1] == 11 || str[i1] == 12
		|| str[i1] == 13 || str[i1] == 32)
		i1++;
	if (str[i1] == '-' || str[i1] == '+')
	{
		if (str[i1] == '-')
			sign = -1;
		i1++;
	}
	while (str[i1] >= '0' && str[i1] <= '9')
		result1 = result1 * 10 + str[i1++] - '0';
	return (result1 * sign);
}

int	check_args_num(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (0);
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("Error: Number of philosophers should be greater than 0\n");
		return (0);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 1)
	{
		printf("Error: Number of times each philosopher ");
		printf("must eat should be greater than 0\n");
		return (0);
	}
	return (1);
}

int	check_times(char **argv)
{
	if (ft_atoi(argv[2]) < 60)
	{
		printf("Error: Time to die should be greater than 60\n");
		return (0);
	}
	if (ft_atoi(argv[3]) < 60)
	{
		printf("Error: Time to eat should be greater than 60\n");
		return (0);
	}
	if (ft_atoi(argv[4]) < 60)
	{
		printf("Error: Time to sleep should be greater than 60\n");
		return (0);
	}
	return (1);
}

int	check_is_digit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][j] == '+') && (argv[i][j + 1] >= '0' && argv[i][j
				+ 1] <= '9'))
			j++;
		while (argv[i][j])
		{
			while (argv[i][j] == 9 || argv[i][j] == 10 || argv[i][j] == 11
				|| argv[i][j] == 12 || argv[i][j] == 13 || argv[i][j] == 32)
				j++;
			if ((argv[i][j] == '+') && !(argv[i][j - 1]))
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (!check_args_num(argc, argv))
		return (0);
	if (!check_is_digit(argv))
	{
		printf("Error: Arguments should be numbers\n");
		return (0);
	}
	if (!check_times(argv))
		return (0);
	return (1);
}
