/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 21:48:20 by dcaldas-          #+#    #+#             */
/*   Updated: 2023/11/26 00:40:42 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minitalk_bonus.h"

void	handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static int	i;

	(void)s;
	(void)info;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	sig.sa_sigaction = handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
	while (1)
	{
		sigaction(SIGUSR1, &sig, NULL);
		sigaction(SIGUSR2, &sig, NULL);
		pause();
	}
	return (0);
}
