/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:03:57 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/22 17:28:44 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	send_signal(int pid, char s)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (s & (1 << j))
		{
			if (kill(pid, SIGUSR1) == -1)
				return (ft_printf(RED "SERVER CONNECTION ERROR\n" RESET),
					-1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				return (ft_printf(RED "SERVER CONNECTION ERROR\n" RESET),
					-1);
		}
		usleep(500);
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	serv_pid;

	if (argc != 3)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	serv_pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		if (send_signal(serv_pid, *argv[2]) == -1)
			return (1);
		argv[2]++;
	}
	return (0);
}
