/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex_l_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:31:15 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/11 14:20:48 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_hex_l_fd(unsigned int nbr, int fd)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_write_hex_l_fd(nbr / 16, fd);
	ft_putchar_fd(hex[nbr % 16], fd);
	count++;
	return (count);
}
