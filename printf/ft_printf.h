/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-paul <pedroavezum@student.42sp.org>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:23:53 by pde-paul          #+#    #+#             */
/*   Updated: 2022/09/23 18:34:25 by pde-paul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int        ft_printf(const char *str, ...);
int        argument_handling(const char *str, int count, va_list arg);
int        hexa_conversion(unsigned long long number, char id);

int        ft_strlen(const char *str);
int        ft_putchar(char c);
int        ft_putnbr(long int n);
int        ft_putstr(char *s);

#endif