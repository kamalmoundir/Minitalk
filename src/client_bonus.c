/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:40:12 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/22 17:26:03 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	confirmation_handler(int signal)
{
	if (signal == SIGUSR2)
		ft_printf(BOLDYELLOW "\nmessage received\n" RESET);
}

int	send_signal(int pid, char s)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (s & (1 << j))
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf(RED "SERVER CONNECTION ERROR(SIGUSR1). \n");
				return (-1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf(RED "SERVER CONNECTION ERROR(SIGUSR2). \n");
				return (-1);
			}
		}
		usleep(300);
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pidserv;

	if (argc != 3)
	{
		ft_printf(RED "ARGUMENTS ERROR \n" RESET);
		return (1);
	}
	pidserv = ft_atoi(argv[1]);
	while (*argv[2])
	{
		if (send_signal(pidserv, *argv[2]) == -1)
			return (1);
		argv[2]++;
	}
	signal(SIGUSR2, confirmation_handler);
	send_signal(pidserv, '\0');
	return (0);
}
