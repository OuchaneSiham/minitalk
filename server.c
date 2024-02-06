/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:42:01 by souchane          #+#    #+#             */
/*   Updated: 2024/02/05 16:18:55 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	convert(int signal, siginfo_t *info, void *context)
{
	static int	pid;
	static char	c = 0xFF;
	static int	x = 0;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		c = 0xFF;
		x = 0;
	}
	if (signal == SIGUSR1)
		c = c | (128 >> x);
	else if (signal == SIGUSR2)
		c = c ^ (128 >> x);
	x++;
	if (x == 8)
	{
		ft_putchar(c);
		c = 0xFF;
		x = 0;
	}
}

int	main(void)
{
	struct sigaction	action;
	int					pid;

	action.sa_sigaction = &convert;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr("pid:");
	ft_putnbr(pid);
	ft_putstr("\n");
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
}
