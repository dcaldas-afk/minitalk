/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:13:34 by dcaldas-          #+#    #+#             */
/*   Updated: 2023/11/16 18:20:17 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_power(int x, int e)
{
    int n;

    n = 1;
    while (e > 0)
    {
        if (e % 2 == 1)
            n *= x;
        x *= x;
        e /= 2;
    }
    return (n);
}

static void  handler(int sig)
{
    static int  n;
    static int  n_bit;

    if (sig == SIGUSR1)
        n += ft_power(2, n_bit);
    if (++n_bit == 8)
    {
        printf("%c", n);
        n_bit = 0;
        n = 0;
    }

}

int main()
{
    printf("PID: %d\n", getpid());
    while (1)
    {
        signal(SIGUSR1, handler);
        signal(SIGUSR2, handler);
        pause();
    }
    return (0);
}