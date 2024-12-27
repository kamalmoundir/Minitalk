/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:05:21 by kmoundir          #+#    #+#             */
/*   Updated: 2024/10/11 13:56:38 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char c, va_list args)
{
	int	count_caracter;

	count_caracter = 0;
	if (c == 'i' || c == 'd')
		count_caracter += ft_itoa_fd(va_arg(args, int), 1);
	else if (c == 'u')
		count_caracter += ft_itoa_u_fd(va_arg(args, int), 1);
	else if (c == 's')
		count_caracter += ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'c')
		count_caracter += ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'x')
		count_caracter += ft_write_hex_l_fd(va_arg(args, int), 1);
	else if (c == 'X')
		count_caracter += ft_write_hex_up_fd(va_arg(args, int), 1);
	else if (c == 'p')
		count_caracter += ft_print_ptr_fd(va_arg(args, void *), 1);
	else if (c == '%')
		count_caracter += ft_putchar_fd('%', 1);
	return (count_caracter);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		count_caracter;

	va_start(args, str);
	count_caracter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count_caracter += print_format(*str, args);
		}
		else
			count_caracter += ft_putchar_fd(*str, 1);
		str ++;
	}
	return (count_caracter);
}
