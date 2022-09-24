/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-paul <pedroavezum@student.42sp.org>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:33:59 by pde-paul          #+#    #+#             */
/*   Updated: 2022/09/23 18:40:55 by pde-paul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int    ft_hexlen(unsigned long int n)
{
    int    length;

    length = 1;
    while (n >= 16)
    {
        length++;
        n = n / 16;
    }
    return (length);
}

static char    ascii_transformation(unsigned long int input, char type)
{
    if (input <= 9)
        return (input + 48);
    else if (type == 'l')
        return (input + 87);
    else if (type == 'U')
        return (input + 55);
    else if (type == 'p')
        return (input + 87);
    return (input);
}

int    hexa_conversion(unsigned long long number, char type)
{
    char                *str;
    int                    length;
    unsigned long int    mod;

    length = ft_hexlen (number);
    if (type == 'p')
    {
        if (number == 0)
            return (ft_printf("(nil)") - 2);
        ft_printf("0x");
    }
    str = (char *) calloc(sizeof(char), (length + 1));
    if (number == 0)
        str[--length] = '0';
    while (number != 0)
    {
        mod = (number % 16);
        str[--length] = ascii_transformation(mod, type);
        number = number / 16;
    }
    length = ft_putstr(str);
    free(str);
    return (length);
}

int    argument_handling(const char *str, int count, va_list arg)
{
    int    rtr;

    rtr = 0;
    if (str[count] == 'c')
        rtr = ft_putchar(va_arg(arg, int));
    if (str[count] == 's')
        rtr = ft_putstr(va_arg(arg, char *));
    if (str[count] == 'p')
        rtr = hexa_conversion(va_arg(arg, unsigned long long int), 'p') + 2;
    if (str[count] == 'd')
        rtr = ft_putnbr(va_arg(arg, int));
    if (str[count] == 'i')
        rtr = ft_putnbr(va_arg(arg, int));
    if (str[count] == 'u')
        rtr = ft_putnbr(va_arg(arg, unsigned int));
    if (str[count] == 'x')
        rtr = hexa_conversion(va_arg(arg, unsigned int), 'l');
    if (str[count] == 'X')
        rtr = hexa_conversion(va_arg(arg, unsigned int), 'U');
    if (str[count] == '%')
        rtr = ft_putchar('%');
    return (rtr);
}

int    ft_printf(const char *str, ...)
{
    int        count_size;
    int        total_length;
    va_list    args;

    total_length = 0;
    va_start(args, str);
    count_size = 0;
    while (str[count_size] != '\0')
    {
        if (str[count_size] == '%')
        {
            count_size++;
            total_length += argument_handling(str, count_size, args);
        }
        else
            total_length += ft_putchar(str[count_size]);
        count_size++;
    }
    return (total_length);
}
