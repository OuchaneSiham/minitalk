/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 23:31:20 by souchane          #+#    #+#             */
/*   Updated: 2024/02/05 16:10:23 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	isndigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int			j;
	long long	nb;
	long long	tmp;
	int			sg;

	j = 0;
	sg = 1;
	while (str[j] == '\n' || str[j] == '\t' || str[j] == '\f'
		|| str[j] == ' ' || str[j] == '\r' || str[j] == '\v')
		j++;
	if (str[j] == '+' || str[j] == '-')
		if (str[j++] == '-')
			sg *= -1;
	nb = 0;
	while (ft_isdigit(str[j]))
	{
		tmp = nb;
		nb = nb * 10 + str[j] - '0';
		if (tmp != nb / 10 && sg == 1)
			return (-1);
		else if (tmp != nb / 10 && sg == -1)
			return (0);
		j++;
	}
	return (nb * sg);
}
