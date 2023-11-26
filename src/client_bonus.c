/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:29:21 by dcaldas-          #+#    #+#             */
/*   Updated: 2023/11/26 00:38:07 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk_bonus.h"

void	ft_signals(int pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((c & (0x01 << bits)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		++bits;
	}
}

void	ft_feedback(int signal)
{
	(void)signal;
	ft_putstr("Ok.");
	ft_putstr("\n");
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	signal(SIGUSR2, ft_feedback);
	if (argc == 3 && ft_isdigit(argv[1]))
	{
		pid = pid_atoi(argv[1]);
		str = argv[2];
		while (*str)
			ft_signals(pid,*str++);
		ft_signals(pid, '\n');
	}
	else
		ft_putstr("Invalid input\n");
	return (0);
}
