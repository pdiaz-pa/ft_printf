/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:23:08 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/02/27 15:08:42 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_isconversion(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
	|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_isflag(int c)
{
	return ((c == '-') || (c == '0') || (c == '.') || (c == '*') || (c == ' '));
}

int	ft_handle(int c, t_flags flags, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count = ft_handle_char(va_arg(args, int), flags);
	else if (c == '%')
		count += ft_handle_percent(flags);
	else if (c == 's')
		count = ft_handle_string(va_arg(args, char *), flags);
	else if ((c == 'i') || (c == 'd'))
		count = ft_handle_int(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_handle_uint(va_arg(args, unsigned int), flags);
	else if (c == 'p')
		count = ft_handle_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'x')
		count = ft_handle_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count = ft_handle_hex(va_arg(args, unsigned int), 0, flags);
	return (count);
}
