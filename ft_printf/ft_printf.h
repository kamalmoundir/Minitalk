/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:10:12 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/21 18:07:44 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_itoa_fd(int n, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_printf(const char *str, ...);
int		ft_write_hex_l_fd(unsigned int nbr, int fd);
int		ft_write_hex_up_fd(unsigned int nbr, int fd);
int		ft_itoa_u_fd(unsigned int n, int fd);
int		ft_print_ptr_fd(void *ptr, int fd);
size_t	ft_strlen(const char *s);

#endif
