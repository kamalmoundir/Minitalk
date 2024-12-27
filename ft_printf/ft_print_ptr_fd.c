/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:50:43 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/11 13:43:21 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_ptr_recursive(unsigned long long ptr, int fd, char *hex)
{
	int	count;

	count = 0;
	if (ptr == 0)
		count += ft_putchar_fd('0', fd);
	if (ptr >= 16)
		count += ft_print_ptr_recursive(ptr / 16, fd, hex);
	count += ft_putchar_fd(hex[ptr % 16], fd);
	return (count);
}

int	ft_print_ptr_fd(void *ptr, int fd)
{
	char				*hex;
	int					count;
	unsigned long long	ptr1 ;

	ptr1 = (unsigned long long)ptr;
	hex = "0123456789abcdef";
	count = 0;
	if (ptr == NULL)
	{
		count += ft_putstr_fd("(nil)", fd);
		return (count);
	}
	count += ft_putchar_fd('0', fd);
	count += ft_putchar_fd('x', fd);
	count += ft_print_ptr_recursive(ptr1, fd, hex);
	return (count);
}
