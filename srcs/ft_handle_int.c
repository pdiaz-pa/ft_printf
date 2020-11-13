/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdiaz-pa <pdiaz-pa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:14:23 by pdiaz-pa          #+#    #+#             */
/*   Updated: 2020/02/28 12:08:34 by pdiaz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	ft_handle_inttt(char *str, int num, t_flags flags)
{
	int cont;

	cont = 0;
	if (flags.dot >= 0 && num < 0 && num != -2147483648)
		ft_putchar('-');
	if (flags.dot >= 0)
		cont += ft_handle_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	cont += ft_putstr_p(str, ft_strlen(str));
	return (cont);
}

static int	ft_handle_intt(char *str, int num, t_flags flags)
{
	int cont;

	cont = 0;
	if (flags.minus == 1)
		cont += ft_handle_inttt(str, num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		cont += ft_handle_width(flags.width, 0, 0);
	}
	else
		cont += ft_handle_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		cont += ft_handle_inttt(str, num, flags);
	return (cont);
}

int			ft_handle_int(int i, t_flags flags)
{
	int		cont;
	int		num;
	char	*str;

	cont = 0;
	num = i;
	if (flags.dot == 0 && i == 0)
	{
		cont += ft_handle_width(flags.width, 0, 0);
		return (cont);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1) && num != -2147483648)
	{
		if (flags.dot <= -1 && flags.zero == 1)
			ft_putstr_p("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		cont++;
	}
	str = ft_itoa(i);
	cont += ft_handle_intt(str, num, flags);
	free(str);
	return (cont);
}
