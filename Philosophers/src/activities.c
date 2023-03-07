/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:25:48 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/15 19:19:14 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	died(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%d %d is died\n", gmtb(philo->start_time), philo->id_p);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%d %d is thinking\n", gmtb(philo->start_time), philo->id_p);
	pthread_mutex_unlock(philo->print);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->print);
	printf("%d %d is sleeping\n", gmtb(philo->start_time), philo->id_p);
	pthread_mutex_unlock(philo->print);
	msleep(philo->time_sleep * 1000);
	thinking(philo);
}

void	eating(t_philo *philo, int i)
{
	struct timeval	t;
	size_t			stime;

	pthread_mutex_lock(philo->print);
	printf("%d %d is eating\n", gmtb(philo->start_time), philo->id_p);
	pthread_mutex_unlock(philo->print);
	gettimeofday(&t, NULL);
	stime = (size_t)t.tv_sec * 1000 + (size_t)t.tv_usec / 1000;
	philo->last_meal[philo->id_p - 1] = stime;
	msleep(philo->time_eat * 1000);
	pthread_mutex_unlock(&philo->forks[i]);
	pthread_mutex_unlock(&philo->forks[philo->id_p - 1]);
	if (philo->arg6 == 1)
		philo->sum_eat++;
	sleeping(philo);
}

void	tfork(t_philo *philo)
{
	int	i;

	i = philo->id_p % philo->num;
	pthread_mutex_lock(&philo->forks[philo->id_p - 1]);
	pthread_mutex_lock(philo->print);
	printf("%d %d has taken a fork\n", gmtb(philo->start_time), philo->id_p);
	pthread_mutex_unlock(philo->print);
	pthread_mutex_lock(&philo->forks[i]);
	pthread_mutex_lock(philo->print);
	printf("%d %d has taken a fork\n", gmtb(philo->start_time), philo->id_p);
	pthread_mutex_unlock(philo->print);
	eating(philo, i);
}
