/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inital_vals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 11:15:27 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/15 19:13:24 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	inital_vals(t_philo *philo, int argc, char **argv, int num_ph)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * num_ph);
	i = -1;
	while (++i < num_ph)
		pthread_mutex_init(&forks[i], NULL);
	i = -1;
	while (++i < num_ph)
	{
		philo[i].id_p = i + 1;
		philo[i].num = toint(argv[1]);
		philo[i].time_die = toint(argv[2]);
		philo[i].time_eat = toint(argv[3]);
		philo[i].time_sleep = toint(argv[4]);
		if (argc == 6)
		{
			philo[i].arg6 = 1;
			philo[i].num_eat = toint(argv[5]);
		}
		philo[i].forks = forks;
	}
}

void	inital_vals2(t_philo *philo, int num_ph, pthread_mutex_t print)
{
	int				i;
	size_t			*last_meal;

	last_meal = malloc(sizeof(size_t) * num_ph);
	i = -1;
	while (++i < num_ph)
	{
		philo->sum_eat = 0;
		philo[i].print = &print;
		philo[i].last_meal = last_meal;
	}
}
