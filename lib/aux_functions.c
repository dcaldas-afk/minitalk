/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 04:05:28 by dcaldas-          #+#    #+#             */
/*   Updated: 2023/11/26 00:24:43 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "minitalk_bonus.h"

int	pid_atoi(const char *nptr)
{
	int	result;

	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
		result = result * 10 + *nptr++ - '0';
	return (result);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_isdigit(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}
