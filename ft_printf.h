/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:44:22 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/20 00:00:07 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int ft_treat_int(int i);

int ft_treat_uint(unsigned int ui, char c);

void ft_put_hexa(unsigned long long num, char c, int base);

int ft_treat_hexa(unsigned int num, char c);

int ft_treat_point(unsigned long long p);

int ft_treat_str(char *s);

int ft_treat_char(int c);

int ft_treat_something(char c, va_list ap);

int ft_count_output(const char *input, va_list ap);



int ft_strlen(char *s);

int count_digit(long n);

char *ft_itoa_base(int n, int base);

//static char *ft_itoa_ui(unsigned int n, int base);

void ft_putstr_fd(char *s, int fd);

void ft_putchar_fd(char c, int fd);

int ft_printf(const char *, ...);

#endif