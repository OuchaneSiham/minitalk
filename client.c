/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:20:38 by souchane          #+#    #+#             */
/*   Updated: 2024/02/05 16:32:33 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(800);
			x++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		if (isndigit(av[1]))
		{
			ft_putstr("wrong pid");
			return (1);
		}
		pid = ft_atoi(av[1]);
		if (pid < 0)
		{
			ft_putstr("negative pid");
			return (1);
		}
		bit_convert(av[2], pid);
	}
	else
		ft_putstr(" wrong argument");
	return (0);
}
