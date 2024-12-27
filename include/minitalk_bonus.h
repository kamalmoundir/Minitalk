/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmoundir <kmoundir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:38:50 by kmoundir          #+#    #+#             */
/*   Updated: 2024/12/21 14:56:20 by kmoundir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <signal.h>
# include <unistd.h>

int	ft_atoi(const char *nptr);
# define RESET "\033[0m"
# define BLACK "\033[30m" /* Black */
# define RED "\033[31m" /* Red */
# define GREEN "\033[32m" /* Green */
# define YELLOW "\033[33m" /* Yellow */
# define BLUE "\033[34m" /* Blue */
# define MAGENTA "\033[35m" /* Magenta */
# define CYAN "\033[36m" /* Cyan */
# define WHITE "\033[37m" /* White */
# define BOLDBLACK "\033[1m\033[30m" /* Bold Black */
# define BOLDRED "\033[1m\033[31m" /* Bold Red */
# define BOLDGREEN "\033[1m\033[32m" /* Bold Green */
# define BOLDYELLOW "\033[1m\033[33m" /* Bold Yellow */
# define BOLDBLUE "\033[1m\033[34m" /* Bold Blue */
# define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
# define BOLDCYAN "\033[1m\033[36m" /* Bold Cyan */
# define BOLDWHITE "\033[1m\033[37m" /* Bold White */

#endif
