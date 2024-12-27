/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:03:52 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/22 17:49:04 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	read_bits(int client_sig)
{
	static char	bit;
	static int	i;

	if (client_sig == SIGUSR1)
		i |= 0x01 << bit;
	bit++;
	if (bit == 8)
	{
		ft_printf(BOLDCYAN "%c", i);
		i = 0;
		bit = 0;
	}
}

void	header_server(void)
{
	ft_printf("\033[H\033[J");
	ft_printf(GREEN "/* ************************************************ */\n");
	ft_printf(GREEN "/*                                                  */\n");
	ft_printf(GREEN "/*                                                  */\n");
	ft_printf(GREEN "/*                 SERVER                           */\n");
	ft_printf(GREEN "/*                                                  */\n");
	ft_printf(GREEN "/*                                                  */\n");
	ft_printf(GREEN "/* ************************************************ */\n");
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_printf(RED "ERROR\n" RESET);
		return (1);
	}
	header_server();
	ft_printf(BOLDBLUE "\nSERVER PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, read_bits);
		signal(SIGUSR2, read_bits);
		pause();
	}
	return (0);
}
