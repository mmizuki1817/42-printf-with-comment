/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:42:23 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/19 23:59:38 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_treat_int(int i) 
{
    char *str;
    size_t count;

    str = ft_itoa_base(i, 10);
    ft_putstr_fd(str, 1);
    count = ft_strlen(str);
    free(str);
    return (count);
}

/*
static int ft_treat_uint(unsigned int ui)
{
    char *str;
    size_t count;

    str = ft_itoa_ui(ui, 10);
    ft_putstr_fd(str, 1);
    ft_strlen(str);
    free(str);
    return (count);
}*/



void ft_put_hexa(unsigned long long num, char c, int base)
{
    if (num < (unsigned long long)base)
    {
        if (num <= 9)
            ft_putchar_fd(num + '0', 1);
        else if (num > 9 && c == 'x')
            ft_putchar_fd('a' + num - 10, 1);
        else if (num > 9 && c == 'X')
            ft_putchar_fd('A' + num - 10, 1);
    }
    else 
    {
        ft_put_hexa(num / base, c, base);
        ft_put_hexa(num % base, c, base);
    }
    return ;
}


int ft_treat_uint(unsigned int ui, char c)
{
    size_t count;
    int base;

    base = 10;
    ft_put_hexa((unsigned long long)ui, c, base);
    if (ui == 0)
        return (1);
    while (ui > 0)
    {
        ui = ui / base;
        count++;
    }
    return (count);
}

int ft_treat_hexa(unsigned int num, char c)
{
    size_t count;
    int base;

    if (!num)
        num = 0;
    base = 16;
    ft_put_hexa((unsigned long long)num, c, base);
    count = 0;
    if (num == 0)
        return (1);
    while (num > 0)
    {
        num = num / base;
        count++;
    }
    return (count);
}

int ft_treat_point(unsigned long long p)
{
    size_t count;

    if (!p)
    {
        ft_putstr_fd("0x0", 1);
        return (3);
    }
    ft_putstr_fd("0x", 1);
    count = 2;
    ft_put_hexa(p, 'x', 16);
    while (p > 0)
    {
        p = p / 16;
        count++;
    }
    return (count);
}

int ft_treat_str(char *s)
{
    if (!s)
        s = "(null)";
    ft_putstr_fd(s, 1);
    return (ft_strlen(s));
}

int ft_treat_char(int c)
{
    ft_putchar_fd(c, 1);
    return (1);
}

int ft_treat_something(char c, va_list ap)
{
    size_t count;

    count = 0;
    if (c == 'c')
        count = ft_treat_char(va_arg(ap, int));
    else if (c == 's')
        count = ft_treat_str(va_arg(ap, char *));
    else if (c == 'p')
        count = ft_treat_point((unsigned long long)va_arg(ap, void *));
    else if (c == 'x' || c == 'X')
        count = ft_treat_hexa(va_arg(ap, unsigned int), c);
    else if (c == 'i' || c == 'd')
        count = ft_treat_int(va_arg(ap, int));
    else if (c == 'u')
        count = ft_treat_uint(va_arg(ap, unsigned int), c);
    else if (c == '%')
        count = ft_treat_char('%');
    return (count);
}

int ft_count_output(const char *input, va_list ap)
{
    size_t i;
    size_t count;

    i = 0;
    count = 0;
    while (input[i])
    {
        if (input[i] == '%')
        {
            i++;
            count += ft_treat_something(input[i], ap);
        }
        else
        {
            ft_putchar_fd(input[i], 1);
            count++;
        }
        i++;
    }
    return (count);
}

int ft_printf(const char* input, ...)
{
    va_list ap;
    int count; 

    count = 0;
    va_start(ap, input);
    count = ft_count_output(input, ap);
    va_end(ap);
    return (count);
}
/*
#include <stdio.h>
int main(void)
{
    ft_printf("hoge");
}*/