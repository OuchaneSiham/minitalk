/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:19:04 by souchane          #+#    #+#             */
/*   Updated: 2024/02/05 16:30:28 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_eof(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (kill(pid, SIGUSR2) < 0)
			exit(1);
		usleep(800);
		i++;
	}
}

void	bit_convert(char *str, int pid)
{
	int	i;
	int	x;

	i = 0;
	while (str[i])
	{
		x = 0;
		while (x < 8)
		{
			if (str[i] & (128 >> x))
			{
				if (kill(pid, SIGUSR1) < 0)
					exit(1);
			}
			else
			{
				if (kill(pid, SIGUSR2) < 0)
					exit(1);
			}
			usleep(800);
			x++;
		}
		i++;
	}
	send_eof(pid);
}

void	seen(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("message has sent\n");
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		if (isndigit(av[1]))
		{
			printf("wrong pid");
			return (1);
		}
		pid = ft_atoi(av[1]);
		if (pid < 0)
		{
			printf("wrong pid");
			return (1);
		}
		signal(SIGUSR1, &seen);
		bit_convert(av[2], pid);
	}
	else
		printf(" wrong argument");
	return (0);
}
