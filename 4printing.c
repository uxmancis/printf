/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4printing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:52:25 by uxmancis          #+#    #+#             */
/*   Updated: 2023/03/14 18:55:33 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c, int num_printed)
{
	write(1, &c, 1);
	num_printed++;
	return (num_printed);
}

int	putstr(char *str, int num_printed)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		num_printed = num_printed +6;
		return (num_printed);
	}
	else
	{
		while (str[i] != '\0')
		{
			num_printed = printchar(str[i], num_printed);
			i++;
		}
	}
	return (num_printed);
}

/*DESCRIPTION:
Write only works with chars, not with ints.
As a consequence, we've to chop numbers into making them <10,
so that we can write them as chars by ASCII table conversion (+48)
---------------------------------------------------------------------------*/
int	putnbr(int arg, int num_printed)
{
	if (arg == -2147483648)
	{
		num_printed = printchar('-', num_printed);
		num_printed = putstr("2147483648", num_printed);
		return (num_printed);
	}
	if (arg < 0)
	{
		num_printed = printchar('-', num_printed);
		arg = arg * (-1);
	}
	if (arg >= 10)
	{
		num_printed = putnbr((arg / 10), num_printed);
		num_printed = printchar(((arg % 10) + 48), num_printed);
	}
	if (arg < 10)
		num_printed = printchar((arg + 48), num_printed);
	return (num_printed);
}

/*DESCRIPTION:
putunbr works in the same way putnbr does. The one difference is that 
putnbr does NOT have to manage negative numbers as it gets unsigned ints as
parameters. Which means, the negative numbers' management is no needed.
*In order to understand this, check what an unsigned int is and how does it work.
---------------------------------------------------------------------------*/
int	putunbr(unsigned int arg, int num_printed)
{
	if (arg > 9)
	{
		num_printed = putnbr(arg / 10, num_printed);
	}
	num_printed = printchar((arg % 10) + '0', num_printed);
	return (num_printed);
}
