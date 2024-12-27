/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:40:26 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/21 18:05:30 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	ft_isspace(int c)
{
	if (c == '\r' || c == '\f' || c == ' ' || c == '\n' || c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	long long int	nbr;
	int				i;
	int				sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		nbr *= 10;
		nbr += nptr[i++] - '0';
		if ((nbr > 2147483647 && sign == 1) || (nbr > 2147483648 && sign == -1))
			return (write(2, "Error\n", 6), -1);
	}
	if (nptr[i] != '\0')
		return (write(2, "Error\n", 6), -1);
	return (nbr * sign);
}
