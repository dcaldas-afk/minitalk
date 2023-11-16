/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:02:23 by dcaldas-          #+#    #+#             */
/*   Updated: 2023/11/16 19:10:06 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	sendToServer(__pid_t pid, char *str)
{
	while (*str)
	{
		int	bits;

	    bits = 0;
        while (bits < 8)
        {
            if ((*str & (0x01 << bits)) != 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(100);
            ++bits;
        }
        str++;
	}
}

int main(int argc, char **argv)
{
    __pid_t pid;
    char    *str;

    if (argc == 3)
    {
        pid = atoi(argv[1]);
        str = argv[2];
        sendToServer(pid, str);
    }
    else
        printf("Invalid input\n");
    return (0);
}