/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:14:33 by dcaldas-          #+#    #+#             */
/*   Updated: 2023/11/26 00:24:34 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

int		pid_atoi(const char *nptr);
void	ft_putstr(char *str);
int		ft_isdigit(char *str);
void	ft_putnbr(int n);

#endif
