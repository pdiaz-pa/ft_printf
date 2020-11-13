/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:52:12 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/02/28 12:08:34 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_handle_hexxx(char *hex, t_flags flags)
{
	int cont;

	cont = 0;
	if (flags.dot >= 0)
	{
		cont += ft_handle_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
	}
	cont += ft_putstr_p(hex, ft_strlen(hex));
	return (cont);
}

static int	ft_handle_hexx(char *hex, t_flags flags)
{
	int cont;

	cont = 0;
	if (flags.minus == 1)
		cont += ft_handle_hexxx(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		cont += ft_handle_width(flags.width, 0, 0);
	}
	else
	{
		cont += ft_handle_width(flags.width, ft_strlen(hex), flags.zero);
	}
	if (flags.minus == 0)
		cont += ft_handle_hexxx(hex, flags);
	return (cont);
}

int			ft_handle_hex(unsigned int number, int lowercase, t_flags flags)
{
	char	*hex;
	int		cont;

	number = (unsigned int)(4294967295 + 1 + number);
	cont = 0;
	if (flags.dot == 0 && number == 0)
	{
		cont += ft_handle_width(flags.width, 0, 0);
		return (cont);
	}
	hex = ft_utl_base((unsigned long long)number, 16);
	if (lowercase == 1)
		hex = ft_str_tolower(hex);
	cont += ft_handle_hexx(hex, flags);
	free(hex);
	return (cont);
}
