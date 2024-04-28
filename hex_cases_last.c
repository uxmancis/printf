/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_cases_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:50:26 by uxmancis          #+#    #+#             */
/*   Updated: 2023/03/14 18:55:42 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*DESCRIPTION:
The approach of the function design in puthexnbr is very similar to putnbr.
Uses recursion for calling the function itself but sending argument / 16 as
parameter, instead of / 10, as in putnbr.
Once the parameter sent to puthexnbr is smaller than 16, it prints the 
respective character of the string chosen.
---------------------------------------------------------------------------*/
int	puthexnbr(size_t arg, int num_printed, char x_type)
{
	if (arg >= 16)
	{
		num_printed = puthexnbr(arg / 16, num_printed, x_type);
	}
	if ((x_type == 'x') || (x_type == 'p'))
		num_printed = printchar("0123456789abcdef"[arg % 16], num_printed);
	if (x_type == 'X')
		num_printed = printchar("0123456789ABCDEF"[arg % 16], num_printed);
	return (num_printed);
}
