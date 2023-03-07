/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abougrin <abougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:21:33 by abougrin          #+#    #+#             */
/*   Updated: 2021/07/16 09:15:42 by abougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*actions(void *struc)
{
	t_philo	*philo;

	philo = (t_philo *)struc;
	if (philo->id_p % 2)
		usleep(200);
	while (1)
		tfork(philo);
	return (0);
}

int	supervisor(t_philo *philo)
{
	int	i;
	int	all_eat;

	while (1)
	{
		i = -1;
		all_eat = 0;
		while (++i < philo->num)
		{
			if (philo->arg6 == 1 && philo[i].sum_eat >= philo->num_eat)
				all_eat++;
			if (gmtb(philo->last_meal[i]) >= philo[i].time_die)
			{
				died(&philo[i]);
				return (0);
			}
		}
		if (all_eat == philo->num)
			break ;
		usleep(100);
	}
	return (0);
}

int	create_thread(t_philo *philo)
{
	pthread_t		*ph_id;
	struct timeval	t;
	int				start;
	int				i;

	i = 0;
	ph_id = malloc(sizeof(pthread_t) * philo->num);
	gettimeofday(&t, NULL);
	start = t.tv_sec * 1000 + (t.tv_usec / 1000);
	while (i < philo->num)
	{
		philo[i].start_time = start;
		philo[i].last_meal[i] = start;
		pthread_create(&ph_id[i], NULL, &actions, &philo[i]);
		i++;
	}
	supervisor(philo);
	free(ph_id);
	return (0);
}

int	errors(int argc, char **argv, int c, int sing)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		c = 0;
		sing = 0;
		while (argv[i][++j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				sing++;
			else if (argv[i][j] >= '0' && argv[i][j] <= '9')
				c++;
			else
				c = 1998;
		}
		if (sing > 1 || c > 10 || erint(argv[i]) == -1)
		{
			printf("Error\n");
			return (-1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo			*philo;
	size_t			num_ph;
	pthread_mutex_t	print;

	pthread_mutex_init(&print, NULL);
	if (argc != 5 && argc != 6)
	{	
		printf("Error : ARGS must be between 4-5\n");
		return (0);
	}
	if (errors(argc, argv, 0, 0) == -1)
		return (0);
	num_ph = toint(argv[1]);
	philo = malloc(sizeof(t_philo) * (num_ph));
	inital_vals(philo, argc, argv, num_ph);
	inital_vals2(philo, num_ph, print);
	create_thread(philo);
	free(philo->forks);
	free(philo->last_meal);
	free(philo);
	return (0);
}
