/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:21:53 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/15 19:12:53 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H

# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				num;
	int				id_p;

	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;

	int				arg6;
	int				sum_eat;
	int				start_time;
	size_t			*last_meal;

	pthread_mutex_t	*print;
	pthread_mutex_t	*forks;
}t_philo;

long	toint(char *str);
int		erint(char *argv);
int		gmtb(size_t start);
void	msleep(size_t end);

void	died(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo, int i);
void	tfork(t_philo *philo);

void	inital_vals(t_philo *philo, int argc, char **argv, int num_ph);
void	inital_vals2(t_philo *philo, int num_ph, pthread_mutex_t print);

#endif