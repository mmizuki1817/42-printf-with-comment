/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimatsub <mimatsub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 19:42:23 by mimatsub          #+#    #+#             */
/*   Updated: 2022/06/20 03:07:34 by mimatsub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" // static は必要？

// 整数を10進で出力する int, short
int ft_treat_int(int i) //int を超えた時の処理
{
    char *str;
    size_t count;

    str = ft_itoa_base(i, 10);
    ft_putstr_fd(str, 1);
    count = ft_strlen(str);
    free(str);
    return (count);
}

void ft_put_base(unsigned long long num, char c, int base)
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
        ft_put_base(num / base, c, base);
        ft_put_base(num % base, c, base);
    }
    return ;
}

// x:整数を16進で出力する
// ui:符号なし整数を10進で出力する 
// %iもまとめたい->int 4byte, long 8byte断念
// why 'x' can use unsigned int?
int ft_treat_base(unsigned int num, char c)
{
    size_t count;
    int base;

    if (!num)
        num = 0;
    if (c =='x' || c == 'X')
        base = 16;
    else
        base = 10;
    ft_put_base((unsigned long long)num, c, base);
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

int ft_treat_point(unsigned long long p) // unsigned int だとうまくいかない
{
    size_t count;

    if (!p)
    {
        ft_putstr_fd("0x0", 1);
        return (3);
    }
    ft_putstr_fd("0x", 1);
    count = 2;
    ft_put_base(p, 'x', 16);
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
    size_t count; //戻り値のcountはint?size_t統一

    count = 0;
    if (c == 'c') // １文字を出力する char
        count = ft_treat_char(va_arg(ap, int));
    else if (c == 's') // 文字列を出力する char *
        count = ft_treat_str(va_arg(ap, char *));
    else if (c == 'p')
        count = ft_treat_point((unsigned long long)va_arg(ap, void *)); // void*->us long long とは
    else if (c == 'x' || c == 'X' || c == 'u')  // 符号なし整数を10進で出力する unsigned int, unsigned short
    // 整数を16進で出力する int, short, unsigned int, unsigned short 負の数についても
        count = ft_treat_base(va_arg(ap, unsigned int), c); // why unsigned int? 整数なのに？
    else if (c == 'i' || c == 'd') // 整数を10進で出力する int, short
        count = ft_treat_int(va_arg(ap, int));
    else if (c == '%')
        count = ft_treat_char('%'); // 戻り値を持ちたい
    return (count); // %の後ろが全く関係ない文字なら？->segfaさせたい // まだ
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
    size_t count; 

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