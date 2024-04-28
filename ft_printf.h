/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:52:39 by uxmancis          #+#    #+#             */
/*   Updated: 2023/03/04 13:35:47 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> //For variadic function: va_list, va_start, va_arg, va_end
# include <unistd.h>
# include <stdio.h>
# include <limits.h> //Includes INT_MIN and INT_MAX values
# include <stdlib.h> //Includes: malloc

//file: ft_printf.c
int	ft_printf(const char *str, ...);
int	find_specifier(const char *str, int i, va_list list, int num_printed);

//file: 4printing.c
int	printchar(char c, int num_printed);
int	putstr(char *str, int num_printed);
int	putnbr(int arg, int num_printed);
int	putunbr(unsigned int arg, int num_printed);

//file: hex_cases_last.c
//both unsigned long and size_t work for arg parameter. E.g.: printf ("%p", "")
int	puthexnbr(unsigned long arg, int num_printed, char x_type);

#endif