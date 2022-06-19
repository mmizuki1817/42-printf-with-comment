/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:51:40 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/20 04:05:21 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *s)
{
    size_t i;

    i = 0;
    while (*s++)
        i++;
    return (i);
}

int count_digit(long n)
{
    int count;

    count = 0;
    if (n <= 0)
    {
        count++;
        n = n * (-1);
    }
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return (count);
}
/*
char *ft_itoa_base(int n, int base)
{
    char *buffer;
    int count;
    long long li;

    li = (long long)n;
    count = count_digit(li);
    buffer = (char *)malloc(sizeof(char) * (count + 1));
    if (buffer == NULL)
        return (NULL);
    buffer[count--] = '\0';
    if (n < 0)
    {
        li = li * (-1);
        buffer[0] = '-';
    }
    if (li == 0)
        buffer[0] = '0';
    while (li > 0)
    {
        buffer[count--] = (char)((li % base) + '0');
        li = li / base;
    }
    return (buffer);
}*/

void ft_putstr_fd(char *s, int fd)
{
    if (s == NULL)
        return ;
    while (*s)
        write(fd, s++, 1);
}

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}


