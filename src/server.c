/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:34 by dcaldas-          #+#    #+#             */
/*   Updated: 2023/11/23 16:18:44 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk.h"

void	handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_putstr("PID: ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);
}
