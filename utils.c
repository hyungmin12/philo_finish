/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyoo <hyyoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:36:23 by hyyoo             #+#    #+#             */
/*   Updated: 2023/03/02 16:48:06 by hyyoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/philo.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	ft_print(int philo_id, char *msg, t_info *info)
{
	pthread_mutex_lock(&(info->print));
	if (!(ft_check_die_flag(info, READ)))
	{
		printf("%lld %d %s\n", ft_get_time() - info->t_start, philo_id + 1, msg);
	}
	pthread_mutex_unlock(&(info->print));
}

int	ft_error_msg(char *str)
{
	printf("%s\n", str);
	return (0);
}

long long	ft_get_time(void)
{
	struct timeval	now;

	if (gettimeofday(&now, NULL) == -1)
		return (ft_error_msg("get_time_error"));
	return ((now.tv_sec * 1000) + (now.tv_usec / 1000));
}

void	ft_pass_time(long long time, int num_philo)
{
	long long	get_time;

	get_time = ft_get_time();
	if (!get_time)
		return ;
	while ((ft_get_time() - get_time) < time)
	{
		if (num_philo < 50)
			usleep(time / 10);
		else
			usleep(1000);
	}
}
