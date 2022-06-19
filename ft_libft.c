/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:51:40 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/20 05:07:52 by mimatsub         ###   ########.fr       */
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


