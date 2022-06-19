/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:44:22 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/20 04:50:35 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int ft_treat_int(int i);

void ft_put_base(unsigned long long num, char c, int base);

int ft_treat_base(unsigned int num, char c);

int ft_treat_point(unsigned long long p);

int ft_treat_str(char *s);

int ft_treat_char(int c);

int ft_treat_something(char c, va_list ap);

int ft_count_output(const char *input, va_list ap);



int ft_strlen(char *s);

int count_digit(long n);

char *ft_itoa_base(int n, int base);

void ft_putstr_fd(char *s, int fd);

void ft_putchar_fd(char c, int fd);

int ft_printf(const char *, ...);

#endif