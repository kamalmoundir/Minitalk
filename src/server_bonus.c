/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:59:23 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/22 17:46:40 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

void	read_bits(int sig, siginfo_t *info, void *context)
{
	static char	bit;
	static int	i;

	(void)context;
	if (sig == SIGUSR1)
		i |= 0x01 << bit;
	bit++;
	if (bit == 8)
	{
		if (i == 0)
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf(BOLDWHITE "\nfrom pid =%d\n" RESET, info->si_pid);
		}
		ft_printf("%c", i);
		i = 0;
		bit = 0;
	}
}

void	header_server_b(void)
{
	ft_printf("\033[H\033[J");
	ft_printf(GREEN "/* ************************************************ */\n");
	ft_printf(GREEN "/*                                                  */\n");
	ft_printf(GREEN "/*                                                  */\n");
	ft_printf(GREEN "/*                 SERVER BONUS                     */\n");
	ft_printf(GREEN "/*                                                  */\n");
	ft_printf(GREEN "/*                                                  */\n");
	ft_printf(GREEN "/* ************************************************ */\n");
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argv;
	if (argc != 1)
		return (ft_printf(RED "ARGUMENTS INPUT ERROR\n" RESET), 1);
	header_server_b();
	ft_printf(BOLDBLUE "\nSERVER BONUS PID: %d\n" RESET, getpid());
	act.sa_sigaction = read_bits;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	while (1)
	{
		if (sigaction(SIGUSR1, &act, NULL) == -1)
			return (ft_printf(RED "SIGUSR1 CONFIGURATION ERROR" RESET), 1);
		if (sigaction(SIGUSR2, &act, NULL) == -1)
			return (ft_printf(RED "SIGUSR2 CONFIGURATION ERROR" RESET), 1);
		pause();
	}
	return (0);
}
