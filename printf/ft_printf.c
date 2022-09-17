/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-paul <pedroavezum@student.42sp.org>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:33:59 by pde-paul          #+#    #+#             */
/*   Updated: 2022/09/16 20:07:15 by pde-paul         ###   ########.fr       */
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

static char    conversion_ascii(unsigned long int receptor, char id)
{
    if (receptor <= 9)
        return (receptor + 48);
    else if (id == 'l')
        return (receptor + 87);
    else if (id == 'U')
        return (receptor + 55);
    else if (id == 'p')
        return (receptor + 87);
    return (receptor);
}

int    ft_convert_hex(unsigned long long number, char id)
{
    char                *str;
    int                    length;
    unsigned long int    mod;

    length = ft_hexlen (number);
    if (id == 'p')
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
        str[--length] = conversion_ascii(mod, id);
        number = number / 16;
    }
    length = ft_putstr(str);
    free(str);
    return (length);
}

int    handle_argument_format(const char *str, int count, va_list arg)
{
    int    length;

    length = 0;
    if (str[count] == 'c')
        length = ft_putchar(va_arg(arg, int));
    if (str[count] == 's')
        length = ft_putstr(va_arg(arg, char *));
    if (str[count] == 'p')
        length = ft_convert_hex(va_arg(arg, unsigned long long int), 'p') + 2;
    if (str[count] == 'd')
        length = ft_putnbr(va_arg(arg, int));
    if (str[count] == 'i')
        length = ft_putnbr(va_arg(arg, int));
    if (str[count] == 'u')
        length = ft_putnbr(va_arg(arg, unsigned int));
    if (str[count] == 'x')
        length = ft_convert_hex(va_arg(arg, unsigned int), 'l');
    if (str[count] == 'X')
        length = ft_convert_hex(va_arg(arg, unsigned int), 'U');
    if (str[count] == '%')
        length = ft_putchar('%');
    return (length);
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
            total_length += handle_argument_format(str, count_size, args);
        }
        else
            total_length += ft_putchar(str[count_size]);
        count_size++;
    }
    return (total_length);
}

int main(void)
{
    int a = 200;
    return (ft_printf("vamos ver se vai printar o valor de %d\n", a));
}